#include <iostream>
using namespace std;

class Shape {
protected:
    double x, y;
public:
    void get_data(double a, double b = 0) {
        x = a;
        y = b;
    }
    virtual void display_area() {
        cout << "Area not defined for base Shape." << endl;
    }
};

class Rectangle : public Shape {
public:
    void display_area() override {
        cout << "Area of Rectangle: " << x * y << endl;
    }
};

class Triangle : public Shape {
public:
    void display_area() override {
        cout << "Area of Triangle: " << 0.5 * x * y << endl;
    }
};

class Circle : public Shape {
public:
    void display_area() override {
        cout << "Area of Circle: " << 3.14159 * x * x << endl;
    }
};

int main() {
    Rectangle rect;
    Triangle tri;
    Circle cir;

    double a, b;

    // Rectangle
    cout << "Enter length and breadth of rectangle: ";
    cin >> a >> b;
    rect.get_data(a, b);
    rect.display_area();

    // Triangle
    cout << "Enter base and height of triangle: ";
    cin >> a >> b;
    tri.get_data(a, b);
    tri.display_area();

    // Circle
    cout << "Enter radius of circle: ";
    cin >> a;
    cir.get_data(a); // second argument defaults to 0
    cir.display_area();

    return 0;
}