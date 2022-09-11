#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return GCD(b, a % b);
	}
}

int isPrimeNumber(int a) {
	for (int i = 2; i < floor(sqrt(a)) + 1; i++) {
		if (a % i == 0) {
			return false;
		}
	}

	return true;
}

int randomPrimeNumber() {
	int randomNumber = rand() % 3000 + 1000;

	while (!isPrimeNumber(randomNumber)) {
		randomNumber++;
	}

	return randomNumber;
}

int findD(int a) {
	for (int d = 2; d < 1000000000; d++) {
		if (GCD(d, a) == 1) {
			return d;
		}
	}

	return 0;
}

int findE(int d, int a) {
	for (int e = 2; e < 1000000000; e++) {
		if ((e * d) % a == 1) {
			return e;
		}
	}

	return 0;
}   

long long modExp(long long x, long long y, long long N) {
	long long b = 1;

	while (y > 0) {
		if (y % 2 == 0) {
			y /= 2;
			x = (x * x) % N;
		}
		else {
			y--;
			b = (b * x) % N;
		}
	}

	return b;
}

int** generateKeys() {
	int p = randomPrimeNumber();
	int q = randomPrimeNumber();
	int n = p * q;
	int d = findD((p - 1) * (q - 1));
	int e = findE(d, (p - 1) * (q - 1));

	int** keys = new int*[2];
	keys[0] = new int[2];
	keys[1] = new int[2];

	keys[0][0] = e;
	keys[0][1] = n;
	keys[1][0] = d;
	keys[1][1] = n;

	return keys;
}

vector<string> split(string s, string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}

string encode(string input, int e, int n) {
	string result = "";

	for (int i = 0; i < input.length(); i++) {
		result += to_string(modExp((int)input[i], e, n));
		result += " ";
	}

	return result;
}


string decode(string input, int d, int n) {
	vector<string> inputArray = split(input, " ");
	inputArray.pop_back();
	string result = "";
	string::size_type sz;

	for (int i = 0; i < inputArray.size(); i++) {
		result += (char) modExp(stol(inputArray.at(i), &sz), d, n);
	}

	return result;
}

int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(0));

	int** keys = generateKeys();

	string encoded = encode("text", keys[0][0], keys[0][1]);

	string decoded = decode(encoded, keys[1][0], keys[1][1]);
	
	cout << decoded;

	return 0;
}