#include <iostream>
#include <vector>

using namespace std;

bool safe(string value) {
	int first = 0, last = value.length() - 1;
	while(first < last) {
		if(value[first] != value[last])
			return false;
		first++;
		last--;
	}
	return true;
}

void palindrome(string &original, int index, vector<string> &array, vector<vector<string>> &result, int &count) {
	if(index == original.length()) {
		result.push_back(array);
		count++;
		return ;
	}
	for(int i = index; i < original.length(); i++) {
		string value = original.substr(index, i - index + 1);
		if(safe(value)) {
			array.push_back(value);
			palindrome(original, i + 1, array, result, count);
			array.pop_back();
		}
	}
}

int main() {
	string original = "aabb";
	int index = 0, count = 0;
	vector<string> array;
	vector<vector<string>> result;

	palindrome(original, index, array, result, count);

	for(auto i: result) {
		for(auto j: i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}