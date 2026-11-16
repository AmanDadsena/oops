#include <iostream>
#include <exception>

using namespace std;

class BankException : public exception {
public:
    virtual const char* what() const throw() {
        return "Bank Transaction Error";
    }
};

class InsufficientFundsException : public BankException {
public:
    const char* what() const throw() {
        return "Error: Insufficient balance!";
    }
};

class NegativeAmountException : public BankException {
public:
    const char* what() const throw() {
        return "Error: Amount cannot be negative!";
    }
};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void withdraw(double amount) {
        if (amount < 0) {
            throw NegativeAmountException();
        }
        if (amount > balance) {
            throw InsufficientFundsException();
        }
        balance -= amount;
        cout << "Withdrawal successful. Current balance: " << balance << endl;
    }
};

int main() {
    BankAccount account(500.0);

    try {
        account.withdraw(-50);
    } catch (BankException& e) {
        cout << e.what() << endl;
    }

    try {
        account.withdraw(600);
    } catch (BankException& e) {
        cout << e.what() << endl;
    }

    try {
        account.withdraw(200);
    } catch (BankException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
