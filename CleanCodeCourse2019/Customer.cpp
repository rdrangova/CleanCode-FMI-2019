#include "Customer.h"



Customer::Customer() :id(0), name("No name"), address("No address")
{
}

Customer::Customer(unsigned long long id, string name, string address)
	: id(id), name(name), address(address)
{
}

unsigned long long Customer::getId() const
{
	return this->id;
}

string Customer::getName() const
{
	return this->name;
}

string Customer::getaddress() const
{
	return this->address;
}

void Customer::display() const
{
	std::cout << "-----Customer-----\n"
		<< "ID: " << this->id
		<< "\nName: " << this->name
		<< "\nAddress: " << this->address << "\n\n";

}

