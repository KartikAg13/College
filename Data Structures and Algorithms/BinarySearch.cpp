#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int key) {
    int first = 0;
    int last = size - 1;
    int mid = 0;
    cout << "Mid scores: ";
    while(first <= last) {
        mid = (first + last) / 2;
        cout << arr[mid] << " ";
        if(arr[mid] == key)
            return mid + 1;
        else if(arr[mid] < key)
            first = mid + 1;
        else
            last = mid - 1;
    }
    return -1;
}

int main() {
    int no = 0;
    int score = 0;
    int result = 0;
    cout << "Enter the number of teams: ";
    cin >> no;
    int teams[no];
    cout << "Enter the scores: " << endl;
    for(int idx = 0; idx < no; idx++)
        cin >> teams[idx];
    cout << "Enter the score to be searched: ";
    cin >> score;
    result = binarySearch(teams, no, score);
    if(result == -1)
        cout << endl << "Score not found" << endl;
    else
        cout << endl << "Score found for the team: " << result << endl;
    return 0;
}