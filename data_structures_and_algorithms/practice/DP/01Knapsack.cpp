#include <iostream> 
#include <vector>

using namespace std;

int recursive(vector<int> &weights, vector<int> &prices, int capacity, int index) {
	if(index < 0 || capacity == 0)
		return 0;
	else if(weights[index] > capacity)
		return recursive(weights, prices, capacity, index - 1);
	else {
		int include = prices[index] + recursive(weights, prices, capacity - weights[index], index - 1);
		int exclude = recursive(weights, prices, capacity, index - 1);
		return max(include, exclude);
	}
}

int memoization(vector<int> &weights, vector<int> &prices, int capacity, int index, vector<vector<int>> &table) {
	if(index < 0 || capacity == 0)
		return 0;
	else if(table[index][capacity] != -1)
		return table[index][capacity];
	else if(weights[index] > capacity) {
		table[index][capacity] = memoization(weights, prices, capacity, index - 1, table);
		return table[index][capacity];
	}
	else {
		int include = prices[index] + memoization(weights, prices, capacity - weights[index], index - 1, table);
		int exclude = memoization(weights, prices, capacity, index - 1, table);
		table[index][capacity] = max(include, exclude);
		return table[index][capacity];
	}
}

int tabulation(vector<int> &weights, vector<int> &prices, int capacity) {
	int length = weights.size();
	vector<vector<int>> table(length + 1, vector<int>(capacity + 1, 0));
	for(int i = 0; i < length; i++) {
		for(int c = 0; c <= capacity; c++) {
			if(weights[i] > c) 
				table[i + 1][c] = table[i][c];
			else {
				int include = prices[i] + table[i][c - weights[i]];
				int exclude = table[i][c];
				table[i + 1][c] = max(include, exclude);
			}
		}
	}
	return table[length][capacity];
}

int optimization(vector<int> &weights, vector<int> &prices, int capacity) {
	int length = weights.size();
	vector<int> table(capacity + 1, 0);
	for(int i = 0; i < length; i++) {
		for(int c = capacity; c >= weights[i]; c--) {
			int include = prices[i] + table[c - weights[i]];
			int exclude = table[c];
			table[c] = max(include, exclude);
		}
	}
	return table[capacity];
}

int main() {
	vector<int> weights = {3, 1, 2, 4, 6};
	vector<int> prices = {7, 2, 1, 6, 12};
	int length = weights.size();
	int capacity = 10, index = weights.size() - 1, result = 0;
	
	result = recursive(weights, prices, capacity, index);
	cout << "Recursive: " << result << endl;
	
	vector<vector<int>> table(length + 1, vector<int>(capacity + 1, -1));
	result = memoization(weights, prices, capacity, index, table);
	cout << "Memoization: " << result << endl;

	result = tabulation(weights, prices, capacity);
	cout << "Tabulation: " << result << endl;

	result = optimization(weights, prices, capacity);
	cout << "Optimization: " << result << endl; 
	return 0;
}