#include <iostream>

using namespace std;

class Products {
    public:
    int markedPrice() {
        return 1000;
    }

    int discount() {
        return 40;
    }
};

class Dress : public Products {
    public:
    char size(int chestSize) {
        if(chestSize >= 20 && chestSize <= 30)
            return 'S';
        else if(chestSize > 30 && chestSize < 41)
            return 'M';
        else
            return 'L';
    }
};

class Shirt : public Dress {
    public:
    int price(int chestSize) {
        if(size(chestSize) == 'L')
            return (markedPrice() + 1000) - (markedPrice() * discount()) / 100;
        else if(size(chestSize) == 'M')
            return (markedPrice() + 500) - (markedPrice() * discount()) / 100;
        else if(size(chestSize) == 'S')
            return markedPrice() - (markedPrice() * discount()) / 100;
    }
};

int main() {
    Shirt obj1;
    int size = 0;
    cout << "Enter the chest size: ";
    cin >> size;
    cout << "Dress Size: " << obj1.size(size) << endl << "Price: $" << obj1.price(size) << endl;
    return 0;
}