#include <iostream>
#include <string>
using namespace std;

const int MAX_TRANSACTIONS = 10;

class Transaction {
public:
    string type;
    double amount;

    Transaction() {
        type = "";
        amount = 0.0;
    }

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }

    void display() {
        cout << type << ": " << amount << endl;
    }
};

class Account {
private:
    int accNumber;
    double balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int transCount;

public:
    Account() {
        accNumber = 0;
        balance = 0.0;
        transCount = 0;
    }

    void setAccount(int number) {
        accNumber = number;
    }

    int getAccountNumber() {
        return accNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            if (transCount < MAX_TRANSACTIONS) {
                transactions[transCount] = Transaction("Deposit", amount);
                transCount++;
            }
            cout << "Deposit successful.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            if (transCount < MAX_TRANSACTIONS) {
                transactions[transCount] = Transaction("Withdraw", amount);
                transCount++;
            }
            cout << "Withdrawal successful.\n";
        } else {
            cout << "Invalid withdrawal amount.\n";
        }
    }

    void showTransactions() {
        cout << "Recent Transactions:\n";
        for (int i = 0; i < transCount; i++) {
            transactions[i].display();
        }
        if (transCount == 0) {
            cout << "No transactions yet.\n";
        }
    }

    void showBalance() {
        cout << "Current balance: " << balance << endl;
    }
};

class Customer {
private:
    string name;
    Account account;

public:
    void createCustomer(string n, int accNo) {
        name = n;
        account.setAccount(accNo);
    }

    void showCustomerInfo() {
        cout << "Customer Name: " << name << endl;
        cout << "Account Number: " << account.getAccountNumber() << endl;
    }

    Account* getAccount() {
        return &account;
    }
};

int main() {
    Customer customer;
    string name;
    int accNo;
    double amount;
    int choice;

    cout << "Enter customer name: ";
    getline(cin, name);

    cout << "Enter account number: ";
    cin >> accNo;

    customer.createCustomer(name, accNo);

    do {
        cout << "\n===== Banking Menu =====\n";
        cout << "1. Show Customer Info\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Show Balance\n";
        cout << "5. View Transactions\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            customer.showCustomerInfo();
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            customer.getAccount()->deposit(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            customer.getAccount()->withdraw(amount);
            break;
        case 4:
            customer.getAccount()->showBalance();
            break;
        case 5:
            customer.getAccount()->showTransactions();
            break;
        case 6:
            cout << "Thank you for using the banking system.\n";
            break;
        default:
            cout << "Invalid option.\n";
        }

    } while (choice != 6);

    return 0;
}

