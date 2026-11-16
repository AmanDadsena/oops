#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack {
private:
    T arr[100];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    void push(T val) {
        if (topIndex < 99) {
            topIndex++;
            arr[topIndex] = val;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if (topIndex >= 0) {
            topIndex--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    T top() {
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

int main() {
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "Int Stack: ";
    while (!s1.isEmpty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;

    Stack<float> s2;
    s2.push(1.5f);
    s2.push(2.5f);
    cout << "Float Stack: ";
    while (!s2.isEmpty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    Stack<string> s3;
    s3.push("World");
    s3.push("Hello");
    cout << "String Stack: ";
    while (!s3.isEmpty()) {
        cout << s3.top() << " ";
        s3.pop();
    }
    cout << endl;

    return 0;
}
