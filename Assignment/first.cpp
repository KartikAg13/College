#include <iostream>
using namespace std;
class Item {
    public:
    string name;
    float price;
    int quantity;

    Item() {
        name = " ";
        price = 0.0;
        quantity = 0;
    }
};

class ShoppingCart {
    public:
    Item items[100];
    int count;

    ShoppingCart() {
        count = 0;
    }

    void addItem(string name, float price, int quantity) {
        if(quantity < 0)
            throw "InvalidQuantityException";
        items[count].name = name;
        items[count].price = price;
        items[count].quantity = quantity;
        count++;
    }

    void removeItem(string name) {
        int i;
        for(i = 0; i < count; i++) {
            if(items[i].name == name) {
                for(int j = i; j < count - 1; j++) {
                    items[j] = items[j + 1];
                }
                count--;
                return;
            }
        }
        throw "ItemNotFoundException";
    }

    void updateQuantity(string name, int quantity) {
        if(quantity < 0)
            throw "InvalidQuantityException";
        for(int i = 0; i < count; i++) {
            if(items[i].name == name) {
                items[i].quantity = quantity;
                return;
            }
        }
        throw "ItemNotFoundException";
    }

    float totalPrice() {
        float total = 0;
        for(int i = 0; i < count; i++) {
            total += items[i].price * items[i].quantity;
        }
        return total;
    }

    void checkout() {
        if(count == 0)
            throw "EmptyCartException";
        for(int i = 0; i < count; i++) {
            cout << items[i].name << " " << items[i].price << " " << items[i].quantity << endl;
        }
        cout << "Total price: " << totalPrice() << endl;
    }
};
int main() {
    ShoppingCart cart;
    cart.addItem("Apple", 10.0, 2);
    cart.addItem("Banana", 5.0, 3);
    cart.addItem("Orange", 7.0, 4);
    cart.removeItem("Banana");
    cart.updateQuantity("Apple", 3);
    cart.checkout();
    return 0;
}