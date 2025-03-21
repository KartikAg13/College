// https://leetcode.com/contest/weekly-contest-439/problems/find-the-largest-almost-missing-integer/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int largest(vector<int> array, int window) {
	int size = array.size();
	vector<int> frequency(51);
	for(int index = 0; index < size; index++)
		frequency[array[index]]++;
	int number = -1;
	if(window == 1) {
		for(int index = 0; index < 51; index++) {
			if(frequency[index] == 1)
				number = index;
		}
		return number;
	}
	else if(window == size) {
		for(int index = 0; index < 51; index++) {
			if(frequency[index] >= 1)
				number = index;
		}
		return number;
	}
	else {
		int first = array[0], last = array[size - 1];
		int cf = 0, cl = 0, sf = 0, sl = 0;
		int i = 0, j = window - 1;
		while(j != size) {
			for(int index = i; index <= j; index++) {
				if(array[index] == first)
					cf++;
				if(array[index] == last)
					cl++;
			}
			if(cf > 0)
				sf++;
			if(cl > 0)
				sl++;
			cf = cl = 0;
			i++;
			j++;
		}
		bool f = (sf == 1);
		bool l = (sl == 1);
		if(f && l)
			return max(first, last);
		else if(f)
			return first;
		else if(l)
			return last;
		else 
			return -1;
	}
}

int main() {
	vector<int> array = {3,1,7,10,0};
	int window = 1;
	cout << largest(array, window) << endl;
	return 0;
}