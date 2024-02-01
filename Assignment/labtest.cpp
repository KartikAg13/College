#include <iostream>
using namespace std;
class Footballer {
    public:
    string player, club;
    int goals, matches;

    void input() {
        cout << "Enter the details:" << endl;
        cin >> player >> club >> goals >> matches;
    }


};
int main() {
    int size;
    cout << "Enter the number of players: ";
    cin >> size;
    string unique[size];
    int total[size];
    int found = 0, swap = 0;
    string t;
    Footballer *f = new Footballer[size]();
    for(int i = 0; i < size; i++)
        f[i].input();
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(f[i].club == f[j].club && i != j) {
                for(int k = 0; k < size; k++) {
                    if(f[i].club == f[k].club) {
                        found = 1;
                        break;
                    }
                }
                if(found == 0) {
                    total[i] = f[i].matches + f[j].matches;
                    unique[i] = f[i].club + f[j].club;
                }
                found = 0;
            }
        }
    } 
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(total[i] < total[j]) {
                swap = total[i];
                total[i] = total[j];
                total[j] = swap;
                t = unique[i];
                unique[i] = unique[j];
                unique[j] = t;
            }
        }
    }
    for(int i = 0; i < size; i++) {
        cout << unique[i] << ": " << total[i] << endl;
    }
}