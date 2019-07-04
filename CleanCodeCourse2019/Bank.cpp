#include "Bank.h"


Bank::Bank() :name("No name"), address("No address")
{
}

Bank::Bank(string name, string address)
	: name(name), address(address)
{
}

Bank::Bank(const Bank& other)
{
	this->name = other.name;
	this->address = other.address;
	this->customers = other.customers;
	Copy(other);
}

Bank& Bank:: operator=(const Bank& rhs)
{
	if (this != &rhs)
	{
		vector<Account*>::iterator i;

		for (i = accounts.begin(); i != accounts.end(); i++)
		{
			delete* i;
		}
		this->accounts.clear();

		this->name = rhs.name;
		this->address = rhs.address;
		this->customers = rhs.customers;
		Copy(rhs);
	}
	return *this;

}

Bank::~Bank()
{
	vector<Account*>::iterator i;

	for (i = accounts.begin(); i != accounts.end(); i++)
	{
		delete* i;
	}

}

string Bank::getName() const
{
	return this->name;
}

string Bank::getAddress() const
{
	return this->address;
}

void Bank::addCustomer(unsigned long long customerId, string name, string address)
{
	if (CustomerCheck(customerId) != -1)
	{
		std::cout << "Customer with this ID already exists.\n";
		return;
	}
	else
	{
		Customer newCustomer(customerId, name, address);
		customers.push_back(newCustomer);
	}
}

void Bank::listCustomers() const
{
	for (size_t i = 0; i < customers.size(); i++)
	{
		customers[i].display();
	}
	if (customers.size() == 0)
		std::cout << "There are no customers in the bank! \n";
}

void Bank::deleteCustomer(unsigned long long customerId)
{
	if (CustomerCheck(customerId) != -1)
	{
		customers.erase(customers.begin() + CustomerCheck(customerId));
		for (int i = 0; i < accounts.size(); i++)
		{
			if (customerId == accounts[i]->getOwnerId())
			{
				accounts.erase(accounts.begin() + i);
				i--;
			}
		}
		return;
	}
	std::cout << "Customer with this ID doesn't exists.\n";
}

void Bank::addAccount(string accountType, string iban, unsigned long long ownerId, double amount)
{
	if (CustomerCheck(ownerId) == -1)
	{
		std::cout << "Customer with this ID doesn't exist!\n";
		return;
	}
	else if (AccountCheck(iban) != -1)
	{
		std::cout << "Acount with this ID already exists!\n";
		return;
	}
	else if (CustomerCheck(ownerId) != -1 && AccountCheck(iban) == -1)
	{
		if (accountType == "current")
		{
			accounts.push_back(new CurrentAccount(iban, ownerId, amount));
		}
		else if (accountType == "savings")
		{
			double intRate;
			std::cout << "Please insert interest rate: ";
			std::cin >> intRate;
			accounts.push_back(new SavingsAccount(iban, ownerId, amount, intRate));
		}
		else if (accountType == "privilege")
		{
			double overdraft;
			std::cout << "Please insert overdraft: ";
			std::cin >> overdraft;
			accounts.push_back(new PrivilegeAccount(iban, ownerId, amount, overdraft));
		}
		else
		{
			std::cout << "Wrong input of account type!\n";
		}
	}
}

void Bank::deleteAccount(string iban)
{
	if (AccountCheck(iban) == -1)
	{
		std::cout << "This account doesn't exist and there is nothing to be deleted!\n";
	}
	else
	{
		accounts.erase(accounts.begin() + AccountCheck(iban));
	}
}

void Bank::listAccounts() const
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		accounts[i]->display();
	}
	if (accounts.size() == 0)
		std::cout << "There are no accounts in the bank! \n";

}

void Bank::listCustomerAccount(unsigned long long customerId) const
{
	int found = -1;
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getOwnerId() == customerId)
		{
			accounts[i]->display();
			found = i;
		}
	}
	if (found == -1)
	{
		std::cout << "Customer with this ID doesn't exist or have no accounts!\n";
	}
}

void Bank::transfer(string fromIBAN, string toIBAN, double amount)
{
	if (AccountCheck(fromIBAN) == -1)
	{
		std::cout << "The account from which you want to transfer doesn't exists!\n";
		return;
	}
	else if (AccountCheck(toIBAN) == -1)
	{
		std::cout << "The account to which you want to transfer doesn't exists!\n";
		return;
	}
	else
	{
		accounts[AccountCheck(fromIBAN)]->withdraw(amount);
		accounts[AccountCheck(toIBAN)]->deposit(amount);
	}
}

void Bank::display() const
{
	std::cout << "-------BANK-------\n"
		<< "Bank name: " << getName()
		<< "\nBank address: " << getAddress()
		<< "\nNumber of customers: " << customers.size()
		<< "\nNumber of accounts: " << accounts.size() << "\n\n";
}

void Bank::addCustomer()
{
	std::cout << "Insert the information about the customer you want to add: \n";
	unsigned long long id;
	std::cout << "Customer's ID: ";
	std::cin >> id;

	std::cout << "Customer's name: ";
	string name;
	std::cin >> name;

	std::cout << "Customer's address: ";
	string address;
	std::cin >> address;

	addCustomer(id, name, address);
}

void Bank::deleteCustomer()
{
	std::cout << "Insert the Customer's ID of the customer you want to be deleted: ";
	unsigned long long id;
	std::cin >> id;
	deleteCustomer(id);
}

void Bank::listCustomerAccount()
{
	std::cout << "Insert the Customer's ID of the customer whose accounts you want to see: ";
	unsigned long long id;
	std::cin >> id;
	listCustomerAccount(id);
}

void Bank::addAccount()
{
	std::cout << "Insert the information about the account you want to add...\n";
	std::cout << "Account Type(current, savings or privilege): ";
	string accType;
	std::cin >> accType;

	std::cout << "IBAN: ";
	string iban;
	std::cin >> iban;

	std::cout << "Owner's ID: ";
	unsigned long long owId;
	std::cin >> owId;

	std::cout << "Amount of money: ";
	double amount;
	std::cin >> amount;

	addAccount(accType, iban, owId, amount);
}

void Bank::deleteAccount()
{
	std::cout << "Insert the IBAN of the account you want to delete: ";
	string iban;
	std::cin >> iban;
	deleteAccount(iban);
}

void Bank::withdrawFromAccount()
{
	std::cout << "Insert the IBAN of the account you want to withdraw from: ";
	string iban;
	std::cin >> iban;
	if (AccountCheck(iban) == -1)
	{
		std::cout << "This account doesn't exists\n";
		return;
	}
	std::cout << "Amount you want to withdraw: ";
	double amount;
	std::cin >> amount;
	accounts[AccountCheck(iban)]->withdraw(amount);
}

void Bank::depositToAccount()
{
	std::cout << "Insert the IBAN of the account you want to deposit to: ";
	string iban;
	std::cin >> iban;
	if (AccountCheck(iban) == -1)
	{
		std::cout << "This account doesn't exists\n";
		return;
	}
	std::cout << "Amount you want to deposit: ";
	double amount;
	std::cin >> amount;
	accounts[AccountCheck(iban)]->deposit(amount);
}

void Bank::transfer()
{
	std::cout << "Insert the IBAN of the account you want to transfer from: ";
	string iban1;
	std::cin >> iban1;
	std::cout << "Insert the IBAN of the account you want to transfer to: ";
	string iban2;
	std::cin >> iban2;
	std::cout << "Insert the amount to transfer: ";
	double amount;
	std::cin >> amount;

	transfer(iban1, iban2, amount);
}

vector<Customer> Bank::getCustomers()
{
	return customers;
}

vector<Account*> Bank::getAccounts()
{
	return accounts;
}

void Bank::Copy(const Bank& bank)
{
	for (int i = 0; i < (int)bank.accounts.size(); i++)
	{
		this->accounts.push_back(bank.accounts[i]->copy());
	}
}

int Bank::CustomerCheck(unsigned long long id)
{
	for (int i = 0; i < customers.size(); i++)
	{
		if (id == customers[i].getId())
		{
			return i;
		}
	}
	return -1;
}

int Bank::AccountCheck(string iban)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (iban == accounts[i]->getIBAN())
		{
			return i;
		}
	}
	return -1;
}
