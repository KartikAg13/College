// https://leetcode.com/problems/maximum-subarray/submissions/1569953845/

#include <iostream>
#include <vector>

using namespace std;

int subarray(vector<int> array) {
	int sum = 0, maximum = 0;
	int start = -1, end = -1;
	for(int index = 0; index < array.size(); index++) {
		if(sum == 0)
			start = index;
		sum = sum + array[index];
		if(sum > maximum) {
			maximum = sum;
			end = index;
		}
		if(sum < 0)
			sum = 0;
	}
	for(int index = start; index <= end; index++)
		cout << array[index] << " ";
	cout << endl;
	return maximum;
}

int main() {
	vector<int> array = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int result = subarray(array);
	cout << "Maximum sum: " << result << endl;
	return 0;
}