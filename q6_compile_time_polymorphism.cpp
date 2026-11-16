#include <iostream>

using namespace std;

class Complex {
private:
    int real;
    int imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    void set(int r) {
        real = r;
        imag = 0;
    }

    void set(int r, int i) {
        real = r;
        imag = i;
    }

    Complex operator+(Complex obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    Complex c3;
    c3.set(5);
    Complex c4;
    c4.set(2, 3);

    Complex c5 = c1 + c2;

    cout << "c1: "; c1.display();
    cout << "c2: "; c2.display();
    cout << "c3: "; c3.display();
    cout << "c4: "; c4.display();
    cout << "c1 + c2: "; c5.display();

    return 0;
}
