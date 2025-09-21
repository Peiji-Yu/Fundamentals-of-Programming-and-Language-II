#include<iostream>

using namespace std;

class SimpleCalculator
{
public:
	double add(double a, double b)
	{
		return a + b;
	}
	double substract(double a, double b)
	{
		return a - b;
	}
	double multiply(double a, double b)
	{
		return a * b;
	}
	double divide(double a, double b)
	{
		return a / b;
	}
};

int main()
{
	double a, b;
	cout << "The value of a is: ";
	cin >> a;
	cout << "The value of b is: ";
	cin >> b;

	SimpleCalculator sc;
	cout << endl << "Adding a and b yields " << sc.add(a, b) << endl;
	cout << "Substracting b from a yields " << sc.substract(a, b) << endl;
	cout << "Multiplying a by b yields " << sc.multiply(a, b) << endl;
	cout << "Dividing a by b yields " << sc.divide(a, b) << endl;

	return 0;
}