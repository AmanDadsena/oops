#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

int addGrace(int mark) {
    return mark + 5;
}

int main() {
    vector<int> marks = {85, 72, 90, 65, 95};

    unordered_map<int, string> studentNames;
    studentNames[101] = "Alice";
    studentNames[102] = "Bob";
    studentNames[103] = "Charlie";

    cout << "Roll 101 Name: " << studentNames[101] << endl;

    sort(marks.begin(), marks.end());
    cout << "Sorted marks: ";
    for (int m : marks) {
        cout << m << " ";
    }
    cout << endl;

    auto it = find_if(marks.begin(), marks.end(), [](int m) {
        return m == 90;
    });
    if (it != marks.end()) {
        cout << "Found mark: " << *it << endl;
    }

    vector<int> updatedMarks(marks.size());
    transform(marks.begin(), marks.end(), updatedMarks.begin(), addGrace);

    cout << "Updated marks (+5): ";
    for (int m : updatedMarks) {
        cout << m << " ";
    }
    cout << endl;

    map<string, int> gradeCount;
    gradeCount["A"] = 3;
    gradeCount["B"] = 2;
    for (auto p : gradeCount) {
        cout << "Grade " << p.first << ": " << p.second << endl;
    }

    return 0;
}
