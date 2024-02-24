#include <iostream>
using namespace std;
class ABC {
    public:
        int x;

        ABC() {
            x = 10;
        }

        ABC(int y = 5) {
            x = y;
        }
};
int main() {
    ABC obj;
    cout << obj.x << endl;
    return 0;
}
