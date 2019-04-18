#include "pch.h"
#include "Vector.h"
#include <iostream>

int main()
{
	int n = 6;
	double d = 2.0;
	//	double *tmp = new double[n];
	Vector<double> A(n), B(n), C(n);
	for (int i = 0; i < n; i++)
	{
		A.SetPtr(i, i + 3);
		B.SetPtr(i, (i + 1) * 3);
	}
	cout << "A:" << A << endl;
	A.DelElement(2);
	cout << "A:" << A << endl;
	A.addElement(20);
	cout << "A:" << A << endl;
	cout << "B:" << B << endl;
	C = A + B;
	cout << endl << endl;

	cout << "A + B:" << C << endl;
	C = A - B;
	cout << "A - B:" << C << endl;
	C = A * B;
	cout << "A * B:" << C << endl;
	C = A / B;
	cout << "A / B:" << C << endl;
	C = A + d;
	cout << "A + " << d << ":" << C << endl;
	//C = d + A ;
	//cout << d <<" + A: " << C  <<endl;
	C = A * d;
	cout << "A * " << d << ":" << C << endl;
	return 1;
}

