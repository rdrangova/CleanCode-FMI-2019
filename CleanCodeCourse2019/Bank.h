
#pragma once
#include <vector>

#include "Customer.h"
#include "CurrentAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"

using std::vector;

class Bank
{
public:
	Bank();
	Bank(string name, string address);
	Bank(const Bank& other);
	Bank& operator=(const Bank& rhs);
	~Bank();
	string getName() const;
	string getAddress() const;
	void addCustomer(unsigned long long customerId, string name, string address);
	void listCustomers() const;
	void deleteCustomer(unsigned long long customerId);
	void addAccount(string accountType, string iban, unsigned long long ownerId, double amount);
	void deleteAccount(string iban);
	void listAccounts() const;
	void listCustomerAccount(unsigned long long customerId) const;
	void transfer(string fromIBAN, string toIBAN, double amount);
	void display() const;

	void addCustomer();
	void deleteCustomer();
	void listCustomerAccount();
	void addAccount();
	void deleteAccount();
	void withdrawFromAccount();
	void depositToAccount();
	void transfer();

	vector <Customer> getCustomers();
	vector <Account*> getAccounts();

	virtual void Copy(const Bank& bank);
private:
	int CustomerCheck(unsigned long long id);
	int AccountCheck(string iban);

private:
	string name;
	string address;
	vector <Customer> customers;
	vector <Account*> accounts;

};


