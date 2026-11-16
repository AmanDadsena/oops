#include <iostream>
#include <string>

using namespace std;

class Expense {
public:
    int id;
    string title;
    string category;
    double amount;

    void setDetails(int i, string t, string c, double a) {
        id = i;
        title = t;
        category = c;
        amount = a;
    }

    void display() {
        cout << "ID: " << id << " | Title: " << title << " | Category: " << category << " | Amount: " << amount << endl;
    }
};

class ExpenseTracker {
private:
    Expense list[50];
    int count;

public:
    ExpenseTracker() {
        count = 0;
    }

    void addExpense(string title, string category, double amount) {
        if (count < 50) {
            list[count].setDetails(count + 1, title, category, amount);
            count++;
            cout << "Expense added successfully!" << endl;
        } else {
            cout << "Expense list is full!" << endl;
        }
    }

    void viewAll() {
        if (count == 0) {
            cout << "No expenses recorded." << endl;
            return;
        }
        cout << "\n--- All Expenses ---" << endl;
        for (int i = 0; i < count; i++) {
            list[i].display();
        }
    }

    void viewTotal() {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += list[i].amount;
        }
        cout << "Total Expense: " << total << endl;
    }

    void filterByCategory(string cat) {
        bool found = false;
        cout << "\nExpenses for " << cat << ":" << endl;
        for (int i = 0; i < count; i++) {
            if (list[i].category == cat) {
                list[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No expenses found for this category." << endl;
        }
    }
};

int main() {
    ExpenseTracker tracker;
    int choice;

    while (true) {
        cout << "\n--- EXPENSE TRACKER ---" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. View All Expenses" << endl;
        cout << "3. View Total Amount" << endl;
        cout << "4. Filter by Category" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string title, category;
            double amount;
            cout << "Enter Title: ";
            cin >> title;
            cout << "Enter Category: ";
            cin >> category;
            cout << "Enter Amount: ";
            cin >> amount;
            tracker.addExpense(title, category, amount);
        } else if (choice == 2) {
            tracker.viewAll();
        } else if (choice == 3) {
            tracker.viewTotal();
        } else if (choice == 4) {
            string category;
            cout << "Enter Category to filter: ";
            cin >> category;
            tracker.filterByCategory(category);
        } else if (choice == 5) {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
