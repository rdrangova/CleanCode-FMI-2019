#include "PrivilegeAccount.h"



PrivilegeAccount::PrivilegeAccount() :Account(), overdraft(0)
{
}

PrivilegeAccount::PrivilegeAccount(string iban, unsigned long long ownerId, double amount, double overdraft)
	: Account(iban, ownerId, amount), overdraft(overdraft)
{
}

double PrivilegeAccount::getOverdraft() const
{
	return this->overdraft;
}

void PrivilegeAccount::deposit(double toBeAdded)
{
	this->setBalance(getBalance() + toBeAdded);
}

bool PrivilegeAccount::withdraw(double toBeRemoved)
{
	double newAmount = getBalance() + this->overdraft - toBeRemoved;
	if (newAmount < 0)
	{
		std::cout << "Not enough amount to be withdrawn!\n";
		return false;
	}
	else
	{
		this->setBalance(newAmount - (this->overdraft));
		return true;
	}
}

void PrivilegeAccount::display() const
{
	std::cout << "-------ACCOUNT-------\n"
		<< "Type: Privilage account\n"
		<< "IBAN: " << this->getIBAN()
		<< "\nOwner ID: " << this->getOwnerId()
		<< "\nOverdraft: " << this->getOverdraft()
		<< "\nBalance: " << this->getBalance() << "\n\n";
}

Account* PrivilegeAccount::copy() const
{
	return new PrivilegeAccount(*this);
}

