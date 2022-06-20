#include "Array.h"		// self created Array-class
#include <iostream>

int main()
{
	//TODO: if you want to test your Array class, write your code here
	// It's only for your IDE. 
	//std::cout << "Hello, world!" << std::endl;
	using namespace std;
	Array ar1, ar2;
	const int N = 5;
	const int N2 = 3;
	int values[N] = { -4,-1,0,25,30 };

	ar1.setArray(values, N);
	for (int i = 0; i < N; i++)
		ar2.setValue(values[i]);
	bool eq = ar2 == ar1;
	cout << "Eq = " << eq << endl;

	cout << "Our arrays:\n";
	cout << "Array1: " << ar1 << endl;
	cout << "Array2: " << ar2 << endl;

	cout << "Add new element to ar1 and ar2:\n";
	ar1.setValue(1);
	ar2.setValue(-1);
	cout << "Our arrays:\n";
	cout << "Array1: " << ar1 << endl;
	cout << "Array2: " << ar2 << endl;
	eq = ar2 == ar1;
	bool not_eq = ar2 != ar1;
	cout << "Eq = " << eq << endl;
	cout << "Not eq = "<<not_eq<<endl;
	cout << "Add to ar2 new array\n";
	int values2[N2] = { -1,0,1 };
	ar2.setArray(values2, N2);
	cout << "ar2: " << ar2 << endl;
	//ar2.setValue(-100);
	////ar2.setValue();
	//ar2.setArray(values, N);
	//cout << "ar2: " << ar2 << endl;
	cout << "Destructors and ending program\n";

	//ar1.~Array();
	//ar2.~Array();

	cout << "Bye!\n";
	system("pause");
	return 0;
}
