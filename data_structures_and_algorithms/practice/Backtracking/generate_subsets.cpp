#include <iostream>
#include <vector>

using namespace std;

void subsets(vector<int> &array, int index, vector<int> &subset, vector<vector<int>> &result, int &count) {
	if(index == array.size()) {
		result.push_back(subset);
		count++;
		return ;
	}	

	subsets(array, index + 1, subset, result, count);

	subset.push_back(array[index]);
	subsets(array, index + 1, subset, result, count);
	subset.pop_back();
}

int main() {
	vector<int> array = {1, 2, 3, 4};
	int length = array.size();

	int index = 0, count = 0;
	vector<int> subset;
	vector<vector<int>> result;
	subsets(array, index, subset, result, count);

	cout << "Number of Subsets: " << count << endl;
	for(int i = 0; i < result.size(); i++) {
		for(int j = 0; j < result[i].size(); j++) 
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}