#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findMinMax(vector<int> &array, int first, int last) {
    if(first == last) 
        return make_pair(array[first], array[last]);

    else if(last == first + 1) {
        if(array[first] < array[last])
            return make_pair(array[first], array[last]);
        else
            return make_pair(array[last], array[first]);
    }

    int middle = first + (last - first) / 2;
    pair<int, int> left = findMinMax(array, first, middle);
    pair<int, int> right = findMinMax(array, middle + 1, last);

    int minimum = (left.first < right.first) ? left.first : right.first;
    int maximum = (left.second > right.second) ? left.second : right.second;
    return make_pair(minimum, maximum);
}

int main() {
    vector<int> array = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int length = array.size();
    pair<int, int> result = findMinMax(array, 0, length - 1);
    cout << "Minimum: " << result.first << endl;
    cout << "Maximum: " << result.second << endl;
    return 0;
}