#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    fstream file;

    file.open("students.csv", ios::out);
    cout << "Initial write pointer (tellp): " << file.tellp() << endl;
    file << "101,Alice,85\n";
    cout << "Write pointer after record 1 (tellp): " << file.tellp() << endl;
    file << "102,Bob,90\n";
    file.close();

    file.open("students.csv", ios::in);
    cout << "Initial read pointer (tellg): " << file.tellg() << endl;

    string line;
    while (getline(file, line)) {
        cout << "Record: " << line << endl;
    }
    cout << "Read pointer at end (tellg): " << file.tellg() << endl;

    file.clear();
    file.seekg(0, ios::beg);
    cout << "Read pointer after seekg(0) (tellg): " << file.tellg() << endl;
    file.close();

    file.open("students.csv", ios::in | ios::out);
    file.seekp(0, ios::end);
    cout << "Write pointer after seekp(end) (tellp): " << file.tellp() << endl;
    file << "103,Charlie,95\n";
    file.close();

    return 0;
}
