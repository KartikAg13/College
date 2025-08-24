#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int key, int length) {
	for(int i = 0; i < length; i++) {
		if(!isalpha(text[i]))
			continue;
		int base = isupper(text[i]) ? 65 : 97;
		text[i] = (text[i] - base + key) % 26 + base;
	}
	return text;
}

int main() {
	string text;
	int key;
	cout << "Please enter the plain text: ";
	getline(cin, text);
	cout << "Please enter the encryption key: ";
	cin >> key;
	key = key % 26;
	int length = text.length();
	string encrypted_text = encrypt(text, key, length);
	cout << "Encrypted Text: " << encrypted_text << endl;
	return 0;
}