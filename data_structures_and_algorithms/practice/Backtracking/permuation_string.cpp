#include <iostream>
#include <vector>

using namespace std;

void permutations(string &value, int i, int j, vector<string> &result, int &count) {
	if(i == j) {
		result.push_back(value);
		count++;
		return ;
	}
	for(int index = i; index <= j; index++) {
		swap(value[i], value[index]);
		permutations(value, i + 1, j, result, count);
		swap(value[i], value[index]);
	}
}

int main() {
	string original = "abCde";
	vector<string> result;
	int i = 0, count = 0;
	int j = original.size() - 1;

	permutations(original, i, j, result, count);

	cout << "Number of Permutations: " << count << endl;
	for(auto &value: result)
		cout << value << endl;

	return 0;
}