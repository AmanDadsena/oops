#include <iostream>
#include <string>

using namespace std;

int main() {
    const double PI = 3.14159;
    int a, b;
    double radius;
    char grade = 'A';
    bool isActive = true;
    string name;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "Enter radius: ";
    cin >> radius;

    cout << "\nHello, " << name << "!" << endl;
    cout << "Grade: " << grade << ", Active status: " << isActive << endl;
    cout << "Area of circle: " << (PI * radius * radius) << endl;

    cout << "Sum: " << (a + b) << endl;
    cout << "Difference: " << (a - b) << endl;
    cout << "Product: " << (a * b) << endl;
    cout << "Division: " << (a / b) << endl;
    cout << "Modulo: " << (a % b) << endl;

    cout << "a > b: " << (a > b) << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "(a > 0 && b > 0): " << (a > 0 && b > 0) << endl;

    return 0;
}
