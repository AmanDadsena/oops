#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

protected:
    string accountHolder;

public:
    BankAccount(int accNum, string name, double bal) {
        accountNumber = accNum;
        accountHolder = name;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    double getBalance() {
        return balance;
    }

    void display() {
        cout << "Account: " << accountNumber << ", Name: " << accountHolder << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, string name, double bal, double rate)
        : BankAccount(accNum, name, bal) {
        interestRate = rate;
    }

    void addInterest() {
        double interest = getBalance() * (interestRate / 100);
        deposit(interest);
        cout << "Interest added: " << interest << endl;
    }
};

int main() {
    SavingsAccount acc(101, "Alice", 1000.0, 5.0);
    acc.display();
    acc.deposit(500.0);
    acc.addInterest();
    acc.withdraw(200.0);
    acc.display();
    return 0;
}
