#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int flag = 0;
    cout << "Enter the number of boxes: ";
    cin >> n;
    if(n > 0 && n <= 10) {
        int a[n];
        for(int i = 0; i < n; i++) {
            cout << "Enter the number of chocolates in box " << i + 1 << ": ";
            cin >> a[i];
            if(i == 0 && a[i] % 2 != 0) {
                cout << "Sorry!!! The first box always should contain positive even number of chocolates" << endl;
                return 0;
            }
            else {
                if(a[i] % 2 == 0)
                    flag++;
            }
        }
        cout << "Number of chocolates in each box: ";
        for(int i = flag - 1; i < n; i++)
            cout << a[i] << " ";
    }
    else
        cout << "Invalid Input" << endl;
    return 0;
}