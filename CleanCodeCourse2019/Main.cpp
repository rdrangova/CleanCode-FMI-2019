#include "Account.h"
#include "Bank.h"
#include "Customer.h"
#include "CurrentAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"

void PrintMenu()
{
	std::cout << "\n-------MENU-------\n" <<
		"1 List customers\n" <<
		"2 Add new customer\n" <<
		"3 Delete customer\n" <<
		"4 List all accounts\n" <<
		"5 List customer accounts\n" <<
		"6 Add new account\n" <<
		"7 Delete account\n" <<
		"8 Withdraw from account\n" <<
		"9 Deposit to account\n" <<
		"10 Transfer\n" <<
		"11 Display info for the bank\n" <<
		"12 Quit\n\n";
}

int ValidInput()
{
	int input;
	std::cout << "Insert a code from the menu: ";
	std::cin >> input;
	std::cout << "\n";
	if (input < 1 && input>12)
	{
		std::cout << "Invalid input!/n Try again!";
		return ValidInput();
	}
	else
	{
		return input;
	}
}
int main()
{
	Bank Radus("Radus International Bank", "Dondukov 1, Sofia");
	Radus.addCustomer(666, "Radost", "Studentski grad");
	Radus.addAccount("current", "RIB666", 666, 100000);
	Radus.addAccount("current", "RIB116", 666, 200000);
	int input;

	do
	{
		PrintMenu();
		input = ValidInput();

		switch (input)
		{
		case 1:Radus.listCustomers(); break;
		case 2:Radus.addCustomer(); break;
		case 3:Radus.deleteCustomer(); break;
		case 4:Radus.listAccounts(); break;
		case 5: Radus.listCustomerAccount(); break;
		case 6: Radus.addAccount(); break;
		case 7: Radus.deleteAccount(); break;
		case 8: Radus.withdrawFromAccount(); break;
		case 9: Radus.depositToAccount(); break;
		case 10: Radus.transfer(); break;
		case 11:Radus.display(); break;
		case 12: std::cout << "Quiting the bank..."; break;
		default:std::cout << "Wrong input!\n";break;
		}
	} while (input != 12);

	system("pause");
	return 0;
}