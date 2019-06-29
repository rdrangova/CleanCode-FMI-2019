#pragma once

#include "Account.h"

class PrivilegeAccount :public Account
{
public:
	PrivilegeAccount();
	PrivilegeAccount(string iban, unsigned long long ownerId, double amount, double overdraft);

	double getOverdraft() const;
	virtual void deposit(double toBeAdded) override;
	virtual bool withdraw(double toBeRemoved) override;
	virtual void display() const override;
	virtual Account* copy() const override;
private:
	double overdraft;

};

