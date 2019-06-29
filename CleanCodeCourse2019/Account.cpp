#include "Account.h"

Account::Account() :iban("No IBAN"), ownerId(0), amount(0)
{
}

Account::Account(string iban, unsigned long long ownerId, double amount)
	: iban(iban), ownerId(ownerId), amount(amount)
{
}

double Account::getBalance() const
{
	return this->amount;
}

string Account::getIBAN() const
{
	return this->iban;
}

unsigned long long Account::getOwnerId() const
{
	return this->ownerId;
}

void Account::setBalance(double amount)
{
	this->amount = amount;
}

