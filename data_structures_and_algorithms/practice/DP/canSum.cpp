#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool canSum(int target, vector<int> &array, unordered_map<int, bool> &m) {
	if(m.find(target) != m.end())
		return m[target];
	else if(target == 0)
		return true;
	else if(target < 0)
		return false;
	for(int number: array) {
		int remainder = target - number;
		if(canSum(remainder, array, m) == true) {
			m[target] = true;
			return true; 
		}
	}
	m[target] = false;
	return false;
}

int main() {
	int target = 300;
	vector<int> array = {7, 14};
	unordered_map<int, bool> m;
	bool result = canSum(target, array, m);
    cout << "Can sum " << target << ": " << (result ? "true" : "false") << endl;
	return 0;
}