#include "account.h"
#include <iostream>
#include <iomanip>

int Account::nextAccountNumber = 1000;

Account::Account() : accountNumber(new int(nextAccountNumber++)), customerName(""), balance(0.0) {}

Account::Account(const std::string& name, double initialDeposit)
    : accountNumber(new int(nextAccountNumber++)), customerName(name), balance(initialDeposit) {}

Account::~Account() {
    delete accountNumber;
}

Account::Account(const Account& other)
    : accountNumber(new int(*other.accountNumber)), customerName(other.customerName), balance(other.balance) {}

Account& Account::operator=(const Account& other) {
    if (this != &other) {
        *accountNumber = *other.accountNumber;
        customerName = other.customerName;
        balance = other.balance;
    }
    return *this;
}

int Account::getAccountNumber() const {
    return *accountNumber;
}

std::string Account::getCustomerName() const {
    return customerName;
}

double Account::getBalance() const {
    return balance;
}

void Account::setCustomerName(const std::string& name) {
    customerName = name;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

void Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
}

bool Account::operator==(const Account& other) const {
    return *accountNumber == *other.accountNumber;
}

int Account::getNextAccountNumber() {
    return nextAccountNumber;
}