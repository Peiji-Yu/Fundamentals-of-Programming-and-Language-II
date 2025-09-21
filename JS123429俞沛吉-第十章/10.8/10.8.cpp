#include<iostream>
#include<string>

using namespace std;

class Complex
{
	friend ostream& operator<<(ostream& output, const Complex& c);
	friend istream& operator>>(istream& input, Complex& c);
public:
	Complex(double r = 0, double i = 0)
	{
		realPart = r;
		imaginaryPart = i;
	}
	Complex operator+(const Complex& c) const
	{
		Complex result;
		result.realPart = realPart + c.realPart;
		result.imaginaryPart = imaginaryPart + c.imaginaryPart;
		return result;
	}
	Complex operator-(const Complex& c) const
	{
		Complex result;
		result.realPart = realPart - c.realPart;
		result.imaginaryPart = imaginaryPart - c.imaginaryPart;
		return result;
	}
	Complex operator*(const Complex& right) const
	{
		Complex result;
		result.realPart = realPart * right.realPart - imaginaryPart * right.imaginaryPart;
		result.imaginaryPart = imaginaryPart * right.realPart + realPart * right.imaginaryPart;
		return result;
	}
	bool operator==(const Complex& right) const
	{
		if (realPart == right.realPart && imaginaryPart == right.imaginaryPart)
			return true;
		else
			return false;
	}
	bool operator!=(const Complex& right) const
	{
		return !(*this == right);
	}
private:
	double realPart;
	double imaginaryPart;
};

ostream& operator<<(ostream& output, const Complex& c)
{
	output << "(" << c.realPart << "," << c.imaginaryPart << ")" << endl;
	return output;
}
istream& operator>>(istream& input, Complex &c)
{
	string s;
	input >> s;
	s = s.substr(1);
	c.realPart = stod(s);
	unsigned int start = s.find(',');
	s = s.substr(start + 1);
	c.imaginaryPart = stod(s);
	return input;
}

int main()
{
	Complex a(3.3, 4.1);
	Complex b;

	cin >> b;
	cout << "a: " << a << "b: " << b;

	cout << boolalpha << (a == b) << endl;
	cout << (a != b) << endl;

	Complex c = a + b;
	cout << "c = a + b" << endl;
	cout << "c: " << c;

	Complex d = a - b;
	cout << "d = a - b" << endl;
	cout << "d: " << d;

	Complex e = a * b;
	cout << "e = a * b" << endl;
	cout << "e: " << e;

	return 0;
}