#include <iostream>
#include <vector>
using namespace std;

int countInRange(const vector<int> &arr, int num, int left, int right) {
	int count = 0;
	for (int i = left; i <= right; i++) {
    	if (arr[i] == num) count++;
	}
	return count;
}

int majorityElementDC(const vector<int> &arr, int left, int right) {
	if (left == right) return arr[left];

	int mid = left + (right - left) / 2;
	int leftMajority = majorityElementDC(arr, left, mid);
	int rightMajority = majorityElementDC(arr, mid + 1, right);

	if (leftMajority == rightMajority) return leftMajority;

	int leftCount = countInRange(arr, leftMajority, left, right);
	int rightCount = countInRange(arr, rightMajority, left, right);

	return (leftCount > rightCount) ? leftMajority : rightMajority;
}

int main() {
	vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
	int n = arr.size();

	int majorityElement = majorityElementDC(arr, 0, n - 1);
	cout << "Majority Element: " << majorityElement << endl;

	return 0;
}

