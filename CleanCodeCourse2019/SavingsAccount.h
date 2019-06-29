#pragma once

#include "Account.h"
#include "CurrentAccount.h"

class SavingsAccount :public Account
{
public:
	SavingsAccount();
	SavingsAccount(string iban, unsigned long long ownerId, double amount, double interestRate);

	double getInterestRate() const;
	virtual void deposit(double toBeAdded) override;
	virtual bool withdraw(double toBeRemoved) override;
	virtual void display() const override;
	virtual Account* copy() const override;
private:
	double interestRate;
};

