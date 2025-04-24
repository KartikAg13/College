#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int recursive(int amount, vector<int> &coins, int length, int index, int current) {
	if(current == amount)
		return 0;
	else if(index == length || current > amount)
		return INT_MAX;
	else {
		int include = recursive(amount, coins, length, index, current + coins[index]);
		if(include != INT_MAX)
			include++;
		int exclude = recursive(amount, coins, length, index + 1, current);
		if(include == INT_MAX && exclude == INT_MAX)
			return INT_MAX;
		return min(include, exclude);
	}
}

int memoization(int amount, vector<int> &coins, int length, int index, int current, vector<vector<int>> &table) {
	if(current == amount)
		return 0;
	else if(index == length || current > amount)
		return INT_MAX;
	else if(table[index][current] != -1)
		return table[index][current];
	else {
		int include = memoization(amount, coins, length, index, current + coins[index], table);
		if(include != INT_MAX)
			include++;
		int exclude = memoization(amount, coins, length, index + 1, current, table);
		if(include == INT_MAX && exclude == INT_MAX)
			table[index][current] = INT_MAX;
		else
			table[index][current] = min(include, exclude);
		return table[index][current];
	}
}

int tabulation(int amount, vector<int> &coins) {
	int length = coins.size();
	vector<vector<int>> table(length + 1, vector<int>(amount + 1, INT_MAX));
	for(int i = 0; i <= length; i++)
		table[i][0] = 0;
	for(int i = 1; i <= length; i++) {
		for(int c = 1; c <= amount; c++) {
			int include = INT_MAX;
			int exclude = table[i - 1][c];
			if(c >= coins[i - 1]) {
				int previous = table[i][c - coins[i - 1]];
				if(previous != INT_MAX)
					include = previous + 1;
			}
			if(include == INT_MAX && exclude == INT_MAX)
				table[i][c] = INT_MAX;
			else
				table[i][c] = min(include, exclude);
		}
	}
	return table[length][amount] == INT_MAX ? -1 : table[length][amount];
}

int optimization(int amount, vector<int> &coins) {
	int length = coins.size();
	vector<int> table(amount + 1, INT_MAX);
	table[0] = 0;
	for(int i = 0; i < length; i++) {
		for(int c = coins[i]; c <= amount; c++) {
			if(table[c - coins[i]] != INT_MAX) {
				if(table[c] == INT_MAX)
					table[c] = min(INT_MAX, 1 + table[c - coins[i]]);
				else
					table[c] = min(table[c], 1 + table[c - coins[i]]);
			}
		}
	}
	return table[amount] == INT_MAX ? -1 : table[amount];
}

int main() {
	int amount = 25;
	vector<int> coins = {4, 5, 2, 1, 9};
	int length = coins.size(), index = 0, current = 0, result = 0;

	result = recursive(amount, coins, length, index, current);
	cout << "Recursive: " << result << endl;

	vector<vector<int>> table(length + 1, vector<int>(amount + 1, -1));
	result = memoization(amount, coins, length, index, current, table);
	cout << "Memoization: " << result << endl;

	result = tabulation(amount, coins);
	cout << "Tabulation: " << result << endl;

	result = optimization(amount, coins);
	cout << "Optimization: " << result << endl;
	return 0;
}