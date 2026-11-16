#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void showPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    int rollNumber;

public:
    Student(string n, int a, int r) : Person(n, a) {
        rollNumber = r;
    }

    void showStudent() {
        showPerson();
        cout << "Roll Number: " << rollNumber << endl;
    }
};

class GraduateStudent : public Student {
private:
    string thesis;

public:
    GraduateStudent(string n, int a, int r, string t) : Student(n, a, r) {
        thesis = t;
    }

    void showGraduateStudent() {
        showStudent();
        cout << "Thesis: " << thesis << endl;
    }
};

int main() {
    Student s("John", 20, 101);
    s.showStudent();

    cout << endl;

    GraduateStudent gs("Alice", 24, 201, "Machine Learning");
    gs.showGraduateStudent();

    return 0;
}
