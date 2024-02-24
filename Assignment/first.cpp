#include <iostream>
using namespace std;
class RomanticGift {
    string sender_name, recipient_name;
    float price;

    public:
    RomanticGift() {
        sender_name = recipient_name = "";
        price = .0f;
    }

    RomanticGift(string s, string r, float p) {
        sender_name = s;
        recipient_name = r;
        price = p;
    }

    virtual void displayDetails() {
        cout << "Sender name: " << sender_name << endl;
        cout << "Recipient name: " << recipient_name << endl;
        cout << "Price: " << price << endl;
    }

    friend void printGiftDetails(RomanticGift &);
};

class Flower : public RomanticGift {
    string flower_type, color, arrangement_style;

    public:
    Flower(string f, string c, string a) {
        flower_type = f;
        color = c;
        arrangement_style = a;
    }

    void displayDetails() override {
        cout << "Flower type: " << flower_type << endl;
        cout << "Color: " << color << endl;
        cout << "Arrangement style: " << arrangement_style << endl;
    }
};

class ChocolateBox : public RomanticGift {
    string chocolate_type, flavour;
    int quantity;

    public:
    ChocolateBox(string c, string f, int q) {
        chocolate_type = c;
        flavour = f;
        quantity = q;
    }

    void displayDetails() override {
        cout << "Chocolate type: " << chocolate_type << endl;
        cout << "Flavour: " << flavour << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

class LoveLetter : public RomanticGift {
    string message_content, style;

    public:
    LoveLetter(string m, string s) {
        message_content = m;
        style = s;
    }

    void displayDetails() override {
        cout << "Message content: " << message_content << endl;
        cout << "Style: " << style << endl;
    }
};

void printGiftDetails(RomanticGift &object) {
    object.displayDetails();
}

int main() {
    Flower f("flower", "color", "arrangement");
    ChocolateBox c("chocolate", "flavour", 5);
    LoveLetter l("message", "style");
    printGiftDetails(f);
    printGiftDetails(c);
    printGiftDetails(l);
    return 0;
}