#include <iostream>
#include <vector>

using namespace std;

int recursive(vector<int> &loot, int index, int length) {
	if(index >= length)
		return 0;
	int include = loot[index] + recursive(loot, index + 2, length);
	int exclude = recursive(loot, index + 1, length);
	return max(include, exclude);
}

int memoization(vector<int> &loot, int index, int length, vector<int> &table) {
	if(index >= length)
		return 0;
	else if(table[index] != -1)
		return table[index];
	else {
		int include = loot[index] + memoization(loot, index + 2, length, table);
		int exclude = memoization(loot, index + 1, length, table);
		table[index] = max(include, exclude);
		return table[index];
	}
}

int tabulation(vector<int> &loot) {
	int length = loot.size();
	if(length == 0)
		return 0;
	else if(length == 1)
		return loot[0];
	vector<int> table(length, 0);
	table[0] = loot[0];
	table[1] = max(loot[0], loot[1]);
	for(int index = 2; index < length; index++) {
		int include = loot[index] + table[index - 2];
		int exclude = table[index - 1];
		table[index] = max(include, exclude);
	}
	return table[length - 1];
}

int optimization(vector<int> &loot) {
	int length = loot.size();
	if(length == 0)
		return 0;
	else if(length == 1)
		return loot[0];
	int previous2 = loot[0];
	int previous1 = max(loot[0], loot[1]);
	for(int index = 2; index < length; index++) {
		int current = max(previous1, previous2 + loot[index]);
		previous2 = previous1;
		previous1 = current;
	}
	return previous1;
}

int main() {
	vector<int> loot = {2, 7, 9, 3, 1};
	int length = loot.size();
	int index = 0, result = 0;
	
	result = recursive(loot, index, length);
	cout << "Recursive: " << result << endl;

	vector<int> table(length, -1);
	result = memoization(loot, index, length, table);
	cout << "Memoization: " << result << endl;	

	result = tabulation(loot);
	cout << "Tabulation: " << result << endl;

	result = optimization(loot);
	cout << "Optimization: " << result << endl;
	return 0;
}