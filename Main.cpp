#include "RBT.h"
#include <iostream>

using namespace std;
int main()
{
	AArrey<string, double> myAA;
	
	cout << "test repos work!"<<endl;
	myAA.insert("jan", 327.2);
	myAA.insert("feb", 368.2);
	myAA.insert("mar", 197.3);
	myAA.insert("apr", 178.4);
	myAA.insert("may", 100.0);
	myAA.insert("jun", 69.9);
	myAA.insert("jul", 32.3);
	myAA.insert("aug", 37.3);
	myAA.insert("sep", 19.0);
	myAA.insert("oct", 37.0);
	myAA.insert("nov", 73.2);
	myAA.insert("dec", 110.9);
	myAA.print();


	Iterator<string>* qitK = myAA.createBftIteratorKey();
	while (qitK->has_next())
	{
		cout << qitK->next() << " ";
	}
	myAA.getKeys();

	myAA.clear();
	try
	{
		Iterator<double>* qitD = myAA.createBftIteratorData();
		while (qitD->has_next())
		{
			cout << qitD->next() << " ";
		}
	}
	catch (out_of_range error)
	{
		cout << error.what();
	}

	myAA.getValue();

	
	return 0;
}