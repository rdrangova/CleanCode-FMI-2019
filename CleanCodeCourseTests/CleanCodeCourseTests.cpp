#include "pch.h"
#include "CppUnitTest.h"
#include "../CleanCodeCourse2019/Bank.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CleanCodeCourseTests
{
	Bank Radus("Radus International Bank", "Dondukov 1, Sofia");

	TEST_CLASS(CleanCodeCourseTests)
	{
	public:

		TEST_METHOD(testAddCustomer)
		{
			unsigned long long id = 666;
			string name = "Radost";
			string address = "Studentski grad";
			Radus.addCustomer(id,name,address);
			Assert::AreEqual(id,Radus.getCustomers()[0].getId());
			Assert::AreEqual(name, Radus.getCustomers()[0].getName());
			Assert::AreEqual(address, Radus.getCustomers()[0].getaddress());
		}
	};
}
