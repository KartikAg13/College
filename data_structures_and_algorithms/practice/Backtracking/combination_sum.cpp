#include <iostream>
#include <vector>

using namespace std;

void combination(vector<int> &array, int target, int index, int sum, vector<vector<int>> &result, vector<int> &current, int &count) {
	if(sum == target) {
		result.push_back(current);
		count++;
		return ;
	}
	else if(index == array.size())
		return ;
	
	combination(array, target, index + 1, sum, result, current, count);

	if(array[index] + sum <= target) {	// safe condition
		sum = sum + array[index];
		current.push_back(array[index]);
		combination(array, target, index, sum, result, current, count);
		current.pop_back();
	}
}

int main() {
	vector<int> array = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
	int target = 15;
	vector<vector<int>> result;
	vector<int> current;
	int count = 0;

	combination(array, target, 0, 0, result, current, count);
	cout << "Total number of solutions: " << count << endl;
	for(auto i: result) {
		for(auto j: i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}