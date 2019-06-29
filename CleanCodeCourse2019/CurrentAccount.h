#pragma once

#include "Account.h"

class CurrentAccount :public Account
{
public:
	CurrentAccount();
	CurrentAccount(string iban, unsigned long long ownerId, double amount);
	virtual void deposit(double toBeAdded) override;
	virtual bool withdraw(double toBeRemoved) override;
	virtual void display() const override;
	virtual Account* copy() const override;
};

