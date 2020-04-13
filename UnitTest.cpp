#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestInsertRoot)
		{
			AArrey<double, int> myMap;
			myMap.insert(1.213, 34);
			Iterator<double>* qitK = myMap.createBftIteratorKey();
			Assert::AreEqual(1.213, qitK->next());
		}

		TEST_METHOD(TestInsertError)
		{
			AArrey<double, int> myMap;
			myMap.insert(1.213, 34);
			try
			{
				myMap.insert(1.213, 34);
			}
			catch (invalid_argument error)
			{
				Assert::AreEqual("Error - This key is already in memory!", error.what());
			}
		}

		TEST_METHOD(TestInsertFixupCase3)
		{
			AArrey<float, int> myMap;
			myMap.insert(1.213, 34);
			myMap.insert(2.23, 33);
			//case 3
			myMap.insert(4.3, 32);

		}

		TEST_METHOD(TestInsertFixupCase1)
		{
			AArrey<float, int> myMap;
			myMap.insert(2.213, 34);
			myMap.insert(1.23, 33);
			myMap.insert(3.3, 32);
			//case 1
			myMap.insert(4.1, 23);
		}

		TEST_METHOD(TestInsertFixupCase2)
		{
			AArrey<float, int> myMap;
			myMap.insert(11, 34);
			myMap.insert(14, 33);
			myMap.insert(2, 32);
			myMap.insert(15, 23);
			myMap.insert(7, 21);
			myMap.insert(1, 32);
			myMap.insert(5, 23);
			myMap.insert(8, 21);
			//case 1 -> |case 2 |->case 3
			myMap.insert(4, 123);
		}

		TEST_METHOD(TestRemoveRed)
		{
			AArrey<float, int> myMap;
			myMap.insert(11, 34);
			myMap.insert(14, 33);
			myMap.insert(2, 32);
			myMap.insert(15, 23);
			myMap.insert(7, 21);
			myMap.insert(1, 32);
			myMap.insert(5, 23);
			myMap.insert(8, 21);
			myMap.insert(4, 123);
			myMap.remove(2);
		}

		TEST_METHOD(TestRemoveBlack)
		{
			AArrey<float, int> myMap;
			myMap.insert(11, 34);
			myMap.insert(14, 33);
			myMap.insert(2, 32);
			myMap.insert(15, 23);
			myMap.insert(7, 21);
			myMap.insert(1, 32);
			myMap.insert(5, 23);
			myMap.insert(8, 21);
			myMap.insert(4, 123);
			myMap.remove(14);
		}

		TEST_METHOD(TestIteratorFalse)
		{
			AArrey<float, int> myMap;
			try
			{
				Iterator<float>* qit = myMap.createBftIteratorKey();
			}
			catch (out_of_range error)
			{
				Assert::AreEqual("tree is empty!", error.what());
			}
			
			
		}


	};
}
