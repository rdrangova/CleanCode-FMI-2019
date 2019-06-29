#pragma once
#include <iostream>
#include <string>

using std::string;

class Customer
{
public:
	Customer();
	Customer(unsigned long long id, string name, string address);
	unsigned long long getId() const;
	string getName() const;
	string getaddress() const;
	void display() const;
private:
	unsigned long long id;
	string name;
	string address;

};

