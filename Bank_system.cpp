#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(const string& accNumber, double initialBalance) {
        accountNumber = accNumber;
        balance = initialBalance;
    }

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. Current balance: " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful. Current balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    virtual void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const string& accNumber, double initialBalance, double rate)
        : Account(accNumber, initialBalance) {
        interestRate = rate;
    }

    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest added. Current balance: " << balance << endl;
    }

    void display() {
        cout << "Savings Account Details" << endl;
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << endl;
    }
};

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(const string& accNumber, double initialBalance, double fee)
        : Account(accNumber, initialBalance) {
        transactionFee = fee;
    }

    void withdraw(double amount) {
        if (balance >= amount + transactionFee) {
            balance -= (amount + transactionFee);
            cout << "Withdrawal successful. Current balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void display() {
        cout << "Checking Account Details" << endl;
        Account::display();
        cout << "Transaction Fee: " << transactionFee << endl;
        cout << endl;
    }
};

int main() {
    Account* accounts[3];

    accounts[0] = new SavingsAccount("SA001", 5000, 2.5);
    accounts[1] = new CheckingAccount("CA001", 3000, 10);
    accounts[2] = new SavingsAccount("SA002", 10000, 3.0);

    for (int i = 0; i < 3; i++) {
        accounts[i]->display();
        accounts[i]->deposit(1000);
        accounts[i]->withdraw(2000);
        cout << endl;
    }

    delete accounts[0];
    delete accounts[1];
    delete accounts[2];

    return 0;
}

