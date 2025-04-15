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

int tabulation(vector<int> &weights, vector<int> &prices, int capacity, int index, vector<vector<int>> &table) {
	
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
	return 0;
}