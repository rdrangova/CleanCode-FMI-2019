#pragma once
#include <iostream>
#include <string>

using std::string;

class Account
{
public:
	Account();
	Account(string iban, unsigned long long ownerId, double amount);
	virtual void deposit(double toBeAdded) = 0;
	virtual bool withdraw(double toBeRemoved) = 0;
	virtual void display() const = 0;
	double getBalance() const;
	string getIBAN() const;
	unsigned long long getOwnerId() const;

	void setBalance(double amount);
	virtual Account* copy() const = 0;
private:
	string iban;
	unsigned long long ownerId;
	double amount;
};

