#include <iostream>

using namespace std;

class Shape {
    public:
    double calculateArea(int radius) {
        return 3.14 * radius * radius;
    }

    double calculateArea(int width, int height) {
        return width * height;
    }

    double calculateArea(float base, float height) {
        return base * height / 2.0;
    }
};

class Circle : public Shape {
    private:
    int radius = 0;

    public:
    void setRadius(int r) {
        radius = r;
    }

    int getRadius() {
        return radius;
    }
};

class Rectangle : public Shape {
    private:
    int width = 0;
    int height = 0;

    public:
    void setWidth(int w) {
        width = w;
    }

    int getWidth() {
        return width;
    }

    void setHeight(int h) {
        height = h;
    }

    int getHeight() {
        return height;
    }
};

class Triangle : public Shape {
    private:
    float base;
    float height;

    public:
    void setBase(float b) {
        base = b;
    }

    float getBase() {
        return base;
    }

    void setHeight(float h) {
        height = h;
    }

    float getHeight() {
        return height;
    }
};

int main() {
    string shape;
    cout << "Enter the type of shape: ";
    cin >> shape;
    double result;
    if(shape == "Circle") {
        int radius;
        Circle circle;
        cout << "Enter the radius: ";
        cin >> radius;
        circle.setRadius(radius);
        result = circle.calculateArea(circle.getRadius());
    }
    else if(shape == "Rectangle") {
        int width;
        int height;
        Rectangle rectangle;
        cout << "Enter the width: ";
        cin >> width;
        cout << "Enter the height: ";
        cin >> height;
        rectangle.setWidth(width);
        rectangle.setHeight(height);
        result = rectangle.calculateArea(rectangle.getWidth(), rectangle.getHeight());
    }
    else if(shape == "Triangle") {
        float base;
        float height;
        Triangle triangle;
        cout << "Enter the base: ";
        cin >> base;
        cout << "Enter the height: ";
        cin >> height;
        triangle.setBase(base);
        triangle.setHeight(height);
        result = triangle.calculateArea(triangle.getBase(), triangle.getHeight());
    }
    cout << "The area of the shape is: " << result << " square centimeters" << endl;
    return 0;
}