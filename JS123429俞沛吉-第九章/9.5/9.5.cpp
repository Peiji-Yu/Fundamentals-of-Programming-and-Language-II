#include<iostream>

using namespace std;

class Complex
{
public:
	Complex(int r = 0, int i = 0)
	{
		realPart = r;
		imaginaryPart = i;
	}
	Complex sum(Complex c)
	{
		Complex result;
		result.realPart = realPart + c.realPart;
		result.imaginaryPart = imaginaryPart + c.imaginaryPart;
		return result;
	}
	Complex minus(Complex c)
	{
		Complex result;
		result.realPart = realPart - c.realPart;
		result.imaginaryPart = imaginaryPart - c.imaginaryPart;
		return result;
	}
	void displayComplex()
	{
		cout << "(" << realPart << "," << imaginaryPart << ")" << endl;
	}

private:
	double realPart;
	double imaginaryPart;
};

int main()
{
	Complex a(3, 4);
	Complex b(1, 2);

	Complex c = a.sum(b);
	c.displayComplex();

	a.minus(b).displayComplex();

	return 0;
}