#include <iostream>

using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    double area() {
        return 0.5 * base * height;
    }
};

int main() {
    Shape* s;

    Circle c(5.0);
    Rectangle r(4.0, 6.0);
    Triangle t(3.0, 8.0);

    s = &c;
    cout << "Circle Area: " << s->area() << endl;

    s = &r;
    cout << "Rectangle Area: " << s->area() << endl;

    s = &t;
    cout << "Triangle Area: " << s->area() << endl;

    return 0;
}
