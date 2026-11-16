#include <iostream>

using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray() {
        size = 0;
        data = nullptr;
        cout << "Default Constructor" << endl;
    }

    DynamicArray(int s, int val) {
        size = s;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = val;
        }
        cout << "Parameterized Constructor" << endl;
    }

    ~DynamicArray() {
        delete[] data;
        cout << "Destructor" << endl;
    }

    DynamicArray(const DynamicArray& other) {
        size = other.size;
        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
        cout << "Copy Constructor" << endl;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        cout << "Copy Assignment" << endl;
        if (this != &other) {
            delete[] data;
            size = other.size;
            if (size > 0) {
                data = new int[size];
                for (int i = 0; i < size; i++) {
                    data[i] = other.data[i];
                }
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    DynamicArray(DynamicArray&& other) {
        size = other.size;
        data = other.data;
        other.size = 0;
        other.data = nullptr;
        cout << "Move Constructor" << endl;
    }

    DynamicArray& operator=(DynamicArray&& other) {
        cout << "Move Assignment" << endl;
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = other.data;
            other.size = 0;
            other.data = nullptr;
        }
        return *this;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray a1;
    DynamicArray a2(3, 10);
    DynamicArray a3 = a2;
    DynamicArray a4 = static_cast<DynamicArray&&>(a2);

    a1 = a3;
    DynamicArray a5;
    a5 = static_cast<DynamicArray&&>(a3);

    cout << "a4 data: ";
    a4.display();
    cout << "a5 data: ";
    a5.display();

    return 0;
}
