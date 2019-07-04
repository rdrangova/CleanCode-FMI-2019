#include "pch.h"
#include "CppUnitTest.h"
#include "../CleanCodeCourse2019/Bank.h"
#include "../CleanCodeCourse2019/Bank.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BankTests
{
	TEST_CLASS(BankTests)
	{
	public:

		TEST_METHOD(testAddCustomer)
		{
			Bank Radus("Radus International Bank", "Dondukov 1, Sofia");
			unsigned long long id = 666;
			Assert::AreEqual(id,Radus.getCustomers()[0].getId());
		}

		TEST_METHOD(testDeleteCustomer)
		{
			Bank Radus("Radus International Bank", "Dondukov 1, Sofia");
			unsigned long long id = 666;
			string name = "Radost";
			string address = "Studentski grad";
			Radus.addCustomer(id, name, address);

			Radus.deleteCustomer(id);
			Assert::AreEqual(0, int(Radus.getCustomers().size()));
		}


	};
}
