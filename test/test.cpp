#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    vector <int> array = {1, 1, 2, 2, 3, 4, 4, 4};
    map <int, int> frequency;
    int count = 0;
    for(int index = 0; index < array.size(); index++) {
        if(frequency.find(array[index]) == frequency.end()) {
            for(int i = index; i < array.size(); i++) {
                if(array[index] == array[i])
                    count++;
            }
            frequency[array[index]] = count;
        }
        count = 0;
    }
    int unique = 1;
    for(auto it : frequency) {
        if(it.first != it.second) {
            unique = 0;
            break;
        }
    }
    if(unique == 0) 
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}