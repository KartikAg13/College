#include <iostream>
#include <vector>
#include <limits>

using namespace std;

pair<int, pair<int, int>> profit(vector<int> &array, int low, int high) {
	if(low == high)
		return make_pair(0, make_pair(array[low], array[high]));
	
	int middle = low + (high - low) / 2;

	pair<int, pair<int, int>> left = profit(array, low, middle);
	pair<int, pair<int, int>> right = profit(array, middle + 1, high);

	pair<int, int> l = left.second;
	pair<int, int> r = right.second;

	int mini = min(l.first, r.first);
	int maxi = max(l.second, r.second);
	int cross = r.second - l.first;

	int maxprofit = max(max(left.first, right.first), max(cross, 0));

	return make_pair(maxprofit, make_pair(mini, maxi));
}

int main() {
	vector<int> array = {100, 180, 260, 310, 40, 535, 695};
	int length = array.size();
	pair<int, pair<int, int>> result = profit(array, 0, length - 1);
	cout << "Bought at " << result.second.first << " and sold at " << result.second.second << endl;
	cout << "The maximum profit is: " << result.first << endl;
	return 0;
}