// https://leetcode.com/problems/valid-palindrome/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>

using namespace std;

bool palindrome(string value) {
	int left = 0;
	int right = value.length() - 1;
	while(left < right) {
		if(isalnum(value[left]) == false) {
			left++;
			continue;
		}
		if(isalnum(value[right]) == false) {
			right--;
			continue;
		}
		if(tolower(value[left]) == tolower(value[right])) {
			left++;
			right--;
		}
		else
			return false;
	}
	return true;
}

int main() {
	string value = "A man, a plan, a canal: Panama";
	bool result = palindrome(value);
	cout << "The string is palindrome: " << result << endl;
	return 0;
}