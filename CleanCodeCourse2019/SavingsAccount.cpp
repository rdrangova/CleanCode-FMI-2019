#include "SavingsAccount.h"


SavingsAccount::SavingsAccount() :Account(), interestRate(0)
{
}

SavingsAccount::SavingsAccount(string iban, unsigned long long ownerId, double amount, double interestRate)
	: Account(iban, ownerId, amount), interestRate(interestRate)
{
}

double SavingsAccount::getInterestRate() const
{
	return this->interestRate;
}

void SavingsAccount::deposit(double toBeAdded)
{
	this->setBalance(getBalance() + toBeAdded);
}

bool SavingsAccount::withdraw(double toBeRemoved)
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

void SavingsAccount::display() const
{
	std::cout << "-------ACCOUNT-------\n"
		<< "Type: Savings account\n"
		<< "IBAN: " << this->getIBAN()
		<< "\nOwner ID: " << this->getOwnerId()
		<< "\nInterest rate: " << this->getInterestRate()
		<< "\nBalance: " << this->getBalance() << "\n\n";

}

Account* SavingsAccount::copy() const
{
	return new SavingsAccount(*this);
}

