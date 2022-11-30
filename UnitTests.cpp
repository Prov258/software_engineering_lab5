#include "pch.h"
#include "CppUnitTest.h"
#include "D:\programming\university\basics_of_software_engineering\lab3\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(calculate_Tests)
	{
	public:
		TEST_METHOD(calculate_get7and3_11returned)
		{
			int x = 7;
			int n = 3;
			double expected = 11;

			double actual = calculate(x, n);

			Assert::AreEqual(expected, actual);
		}

	public:
		TEST_METHOD(calculate_get4and9_8p4869returned)
		{
			int x = 4;
			int n = 9;
			double expected = 8.4869;

			double actual = calculate(x, n);

			Assert::AreEqual(expected, actual, 0.00001);
		}
	};

	TEST_CLASS(checkValidParams_Tests)
	{
	public:
		TEST_METHOD(checkValidParams_get5_exceptionNotThrown)
		{
			int n = 5;

			try
			{
				checkValidParams(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

	public:
		TEST_METHOD(checkValidParams_get0_exceptionThrown)
		{
			int n = 0;

			try
			{
				checkValidParams(n);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};

	TEST_CLASS(checkValidRange_Tests)
	{
	public:
		TEST_METHOD(checkValidRange_get1and8and1_exceptionNotThrown)
		{
			int from = 1;
			int to = 8;
			int step = 1;

			try
			{
				checkValidRange(from, to, step);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

	public:
		TEST_METHOD(checkValidRange_get8and1and1_exceptionThrown)
		{
			int from = 8;
			int to = 1;
			int step = 1;

			try
			{
				checkValidRange(from, to, step);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
}
