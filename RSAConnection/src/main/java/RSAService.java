import java.util.HashMap;
import java.util.Map;

public class RSAService {
    private static int GCD(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return GCD(b, a % b);
        }
    }

    private static boolean isPrimeNumber(int a) {
        for (int i = 2; i < Math.floor(Math.sqrt(a)) + 1; i++) {
            if (a % i == 0) {
                return false;
            }
        }

        return true;
    }

    private static int randomPrimeNumber() {
        int number = (int) (Math.random() * 6000 + 1000);

        while (!isPrimeNumber(number)) {
            number++;
        }

        return number;
    }

    private static int findD(int a) {
        for (int d = 2; d < 1000000000; d++) {
            if (GCD(d, a) == 1) {
                return d;
            }
        }

        return 0;
    }

    private static int findE(int d, int a) {
        for (int e = 2; e < 1000000000; e++) {
            if ((e * d) % a == 1) {
                return e;
            }
        }

        return 0;
    }

    public static Map<String, Integer[]> generateKeys() {
            int p = randomPrimeNumber();
            int q = randomPrimeNumber();
            int n = p * q;
            int d = findD((p - 1) * (q - 1));
            int e = findE(d, (p - 1) * (q - 1));

        Map<String, Integer[]> keys = new HashMap<>();
        keys.put("OpenKey", new Integer[] {e, n});
        keys.put("PrivateKey", new Integer[] {d, n});
        return keys;
    }

    private static long modExp(long x, long y, long N) {
        long b = 1;

        while (y > 0) {
            if (y % 2 == 0) {
                y /= 2;
                x = (x * x) % N;
            } else {
                y--;
                b = (b * x) % N;
            }
        }

        return b;
    }

    public static String encode(String value, Integer[] publicKey) {
        char[] valueCharArray = value.toCharArray();
        String[] resultArray = new String[valueCharArray.length];

        for (int i = 0; i < valueCharArray.length; i++) {
            int chrNumber = valueCharArray[i];
            resultArray[i] = Long.valueOf(modExp(chrNumber, publicKey[0], publicKey[1])).toString();
        }

        return String.join(" ", resultArray);
    }

    public static String decode(String value, Integer[] privateKey) {
        String[] valueArray = value.split(" ");
        char[] resultArray = new char[valueArray.length];

        for (int i = 0; i < valueArray.length; i++) {
            String encodeSymbol = valueArray[i];
            resultArray[i] = (char) modExp(Integer.parseInt(encodeSymbol), privateKey[0], privateKey[1]);
        }

        return String.valueOf(resultArray);
    }
}
