#include<iostream>
#include<iomanip>

using namespace std;

unsigned int Mcd(int n, unsigned int d)
{
	if (n < 0)
		n = -n;
	if (n == 0)
		return 1;

	unsigned int c = n;
	unsigned int m = d - d / n * n;
	while (m != 0)
	{
		unsigned int temp = m;
		m = c - c / m * m;
		c = temp;
	}

	return c;
}

class RationalNumber
{
	friend ostream& operator<<(ostream& output, const RationalNumber& a);
public:
	RationalNumber(int n = 0, int d = 1)
	{
		int de = d;
		if (de == 0)
		{
			cout << "Denominator must >0" << endl;
			de = 1;
		}
		else if (de < 0)
		{
			cout << "Denominator must >0" << endl;
			de = -de;
		}
		simplify(n, de);
	}
	void simplify(int n, unsigned int d)
	{
		unsigned int m = Mcd(n, d);
		numerator = n / m;
		denominator = d / m;
	}
	RationalNumber operator+(const RationalNumber& c) const
	{
		int n = numerator * c.denominator + denominator * c.numerator;
		unsigned int d = denominator * c.denominator;
		RationalNumber result(n, d);
		return result;
	}
	RationalNumber operator-(const RationalNumber& c) const
	{
		int n = numerator * c.denominator - denominator * c.numerator;
		unsigned int d = denominator * c.denominator;
		RationalNumber result(n, d);
		return result;
	}
	RationalNumber operator*(const RationalNumber& c) const
	{
		int n = numerator * c.numerator;
		unsigned int d = denominator * c.denominator;
		RationalNumber result(n, d);
		return result;
	}
	RationalNumber operator/(const RationalNumber& c) const
	{
		int n = numerator * c.denominator;
		unsigned int d = denominator * c.numerator;
		RationalNumber result(n, d);
		return result;
	}
	bool operator>(const RationalNumber& right) const
	{
		int result = numerator * right.denominator - denominator * right.numerator;
		if (result > 0)
			return true;
		else
			return false;
	}
	bool operator<(const RationalNumber& right) const
	{
		int result = numerator * right.denominator - denominator * right.numerator;
		if (result < 0)
			return true;
		else
			return false;
	}
	bool operator==(const RationalNumber& right) const
	{
		int result = numerator * right.denominator - denominator * right.numerator;
		if (result == 0)
			return true;
		else
			return false;
	}
	bool operator!=(const RationalNumber& right) const
	{
		int result = numerator * right.denominator - denominator * right.numerator;
		if (result != 0)
			return true;
		else
			return false;
	}
private:
	int numerator;
	unsigned int denominator;
};

ostream& operator<<(ostream& output, const RationalNumber& a)
{
	output << a.numerator << "/" << a.denominator << endl;
	return output;
}

int main()
{
	RationalNumber a(2, 4);
	RationalNumber b(21, -9);
	cout << a << b;

	cout << boolalpha << (a > b) << endl;
	cout << boolalpha << (a < b) << endl;
	cout << boolalpha << (a == b) << endl;
	cout << boolalpha << (a != b) << endl;

	RationalNumber c;
	RationalNumber d;
	RationalNumber e;
	RationalNumber f;

	c = a + b;
	d = a - b;
	e = a * b;
	f = a / b;

	cout << c << d << e << f;

	return 0;
}