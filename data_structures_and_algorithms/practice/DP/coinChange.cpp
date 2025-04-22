#include <iostream>
#include <vector>

using namespace std;

void recursive(int amount, vector<int> &coins, int index, int current, int length, int &result) {
    if(current == amount)
        result++;
    else if(index == length || current > amount)
        return ;
    else {
        recursive(amount, coins, index, current + coins[index], length, result);
        recursive(amount, coins, index + 1, current, length, result);
    }
}

int memoization(int amount, vector<int> &coins, int index, int current, int length, vector<vector<int>> &table) {
    if(current == amount)
        return 1;
    else if(index == length || current > amount)
        return 0;
    else if(table[index][current] != -1)
        return table[index][current];
    else {
        int include = memoization(amount, coins, index, current + coins[index], length, table);
        int exclude = memoization(amount, coins, index + 1, current, length, table);
        table[index][current] = include + exclude;
        return table[index][current];
    }
}

int tabulation(int amount, vector<int> &coins) {
    int length = coins.size();
    vector<vector<int>> table(length + 1, vector<int>(amount + 1, 0));
    for(int i = 0; i <= length; i++)
        table[i][0] = 1;
    for(int i = 1; i <= length; i++) {
        for(int c = 1; c <= amount; c++) {
            int include = (c >= coins[i - 1] ? table[i][c - coins[i - 1]] : 0);
            int exclude = table[i - 1][c];
            table[i][c] = include + exclude;
        }
    }
    return table[length][amount];
}

int optimization(int amount, vector<int> &coins) {
	int length = coins.size();
	vector<int> table(amount + 1, 0);
	table[0] = 1;
	for(int i = 0; i < length; i++) {
		for(int c = coins[i]; c <= amount; c++) 
			table[c] = table[c] + table[c - coins[i]];
	}
	return table[amount];
}

int main() {
    int amount = 4;
    vector<int> coins = {1, 2, 3};
    int index = 0, current = 0, length = coins.size(), result = 0;

    recursive(amount, coins, index, current, length, result);
    cout << "Recursive: " << result << endl;

    vector<vector<int>> table(length, vector<int>(amount + 1, -1));
    result = memoization(amount, coins, index, current, length, table);
    cout << "Memoization: " << result << endl;

    result = tabulation(amount, coins);
    cout << "Tabulation: " << result << endl;

	result = optimization(amount, coins);
	cout << "Optimization: " << result << endl;
    return 0;
}