#include "CurrentAccount.h"



CurrentAccount::CurrentAccount() :Account()
{
}

CurrentAccount::CurrentAccount(string iban, unsigned long long ownerId, double amount)
	: Account(iban, ownerId, amount)
{
}

void CurrentAccount::deposit(double toBeAdded)
{
	this->setBalance(getBalance() + toBeAdded);
}

bool CurrentAccount::withdraw(double toBeRemoved)
{
	double newAmount = getBalance() - toBeRemoved;
	if (newAmount < 0)
	{
		std::cout << "Not enough amount to be withdrawn!\n";
		return false;
	}
	else
	{
		this->setBalance(newAmount);
		return true;
	}

}

void CurrentAccount::display() const
{
	std::cout << "-------ACCOUNT-------\n"
		<< "Type: Current account\n"
		<< "IBAN: " << this->getIBAN()
		<< "\nOwner ID: " << this->getOwnerId()
		<< "\nBalance: " << this->getBalance() << "\n\n";
}

Account* CurrentAccount::copy() const
{
	return new CurrentAccount(*this);
}

