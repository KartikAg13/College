#include <iostream>
#include <unordered_map>

using namespace std;

long long fibonacci(int number, unordered_map<int, long long> &m) {
	if(m.find(number) != m.end())
		return m[number];
	else if(number <= 1)
		return number;
	else if(number == 2)
		return 1;
	m[number] = fibonacci(number - 1, m) + fibonacci(number - 2, m);
	return m[number];
}

int main() {
	int number = 50;
	unordered_map<int, long long> m;
	long long result = fibonacci(number, m);
	cout << result << endl;
	return 0;
}