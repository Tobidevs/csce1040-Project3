#include "project2.h"
#include <iostream>
#include <iomanip>


void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Open new account\n";
    std::cout << "2. Deposit into account\n";
    std::cout << "3. Withdraw from account\n";
    std::cout << "4. Print a list of all accounts\n";
    std::cout << "5. End transaction (Exit)\n";
    std::cout << "Enter your choice: ";
}

// open a new account
void openAccount(Node*& head) {
    std::string name;
    double initialDeposit;

    std::cout << "Enter customer name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter initial deposit amount: $";
    std::cin >> initialDeposit;

    Account newAccount(name, initialDeposit);
    Node* newNode = new Node(newAccount);
    newNode->next = head;
    head = newNode;

    std::cout << "Account created successfully!\n";
    std::cout << "Account Number: " << newAccount.getAccountNumber() << "\n";
    std::cout << "Customer Name: " << newAccount.getCustomerName() << "\n";
    std::cout << "Initial Balance: $" << std::fixed << std::setprecision(2) << newAccount.getBalance() << "\n";
}


// deposit into an account
void depositToAccount(Node* head) {
    int accountNumber;
    double amount;

    std::cout << "Enter account number: ";
    std::cin >> accountNumber;

    Node* current = head;
    while (current) {
        if (current->account.getAccountNumber() == accountNumber) {
            std::cout << "Enter deposit amount: $";
            std::cin >> amount;
            current->account.deposit(amount);
            std::cout << "Deposit successful!\n";
            std::cout << "Updated Balance: $" << std::fixed << std::setprecision(2) << current->account.getBalance() << "\n";
            return;
        }
        current = current->next;
    }

    std::cout << "Account not found!\n";
}


// withdraw from an account
void withdrawFromAccount(Node* head) {
    int accountNumber;
    double amount;

    std::cout << "Enter account number: ";
    std::cin >> accountNumber;

    Node* current = head;
    while (current) {
        if (current->account.getAccountNumber() == accountNumber) {
            std::cout << "Enter withdrawal amount: $";
            std::cin >> amount;
            if (amount > current->account.getBalance()) {
                std::cout << "Insufficient funds!\n";
            } else {
                current->account.withdraw(amount);
                std::cout << "Withdrawal successful!\n";
                std::cout << "Updated Balance: $" << std::fixed << std::setprecision(2) << current->account.getBalance() << "\n";
            }
            return;
        }
        current = current->next;
    }

    std::cout << "Account not found!\n";
}


// print all accounts
void printAllAccounts(Node* head) {
    if (!head) {
        std::cout << "No accounts found!\n";
        return;
    }

    Node* current = head;
    std::cout << "\nList of all accounts:\n";
    while (current) {
        std::cout << "Account Number: " << current->account.getAccountNumber() << "\n";
        std::cout << "Customer Name: " << current->account.getCustomerName() << "\n";
        std::cout << "Balance: $" << std::fixed << std::setprecision(2) << current->account.getBalance() << "\n\n";
        current = current->next;
    }
}

void deleteAllAccounts(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
