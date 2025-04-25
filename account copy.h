#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account {
private:
    int* accountNumber; 
    std::string customerName; 
    double balance; 

    static int nextAccountNumber;

public:
    Account(); 
    Account(const std::string& name, double initialDeposit);
    ~Account(); 

    Account(const Account& other); 
    Account& operator=(const Account& other); 

    // Getters
    int getAccountNumber() const;
    std::string getCustomerName() const;
    double getBalance() const;

    // Setters
    void setCustomerName(const std::string& name);
    void deposit(double amount);
    void withdraw(double amount);

    // Overloaded Operators
    bool operator==(const Account& other) const;

    // get the next account number
    static int getNextAccountNumber();
};

#endif