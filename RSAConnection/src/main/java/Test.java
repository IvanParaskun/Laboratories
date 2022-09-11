import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;

public class Test {

    public static void main(String[] args) throws IOException {

        Map<String, Integer[]> keys = RSAService.generateKeys();

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

//        String textToEncode = reader.readLine();
//        String encodedText = RSAService.encode(textToEncode, keys.get("OpenKey"));
//
//        System.out.println("Закодированный текст: " + encodedText);

        String textToDecode = reader.readLine();
        System.out.println("Раскодированный текст: " + RSAService.decode(textToDecode, keys.get("PrivateKey")));
    }
}

enum Command {
    CREATE_TRL,
    PRINT_TRL;

    public
}
