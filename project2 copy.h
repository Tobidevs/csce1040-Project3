#ifndef PROJECT2_H
#define PROJECT2_H

#include "account.h"
#include <vector>

struct Node {
  Account account;
  Node* next;
  Node(const Account& acc) : account(acc), next(nullptr) {}
};

void displayMenu();
void openAccount(Node*& head);
void depositToAccount(Node* head);
void withdrawFromAccount(Node* head);
void printAllAccounts(Node* head);
void deleteAllAccounts(Node*& head); // to free memory

#endif