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

class Rational
{
public:
	Rational(int n = 0, unsigned int d = 1)
	{
		simplify(n, d);
	}
	void simplify(int n, unsigned int d)
	{
		unsigned int m = Mcd(n, d);
		numerator = n / m;
		denominator = d / m;
	}
	Rational plus(const Rational& c) const
	{
		int n = numerator * c.denominator + denominator * c.numerator;
		unsigned int d = denominator * c.denominator;
		Rational result(n, d);
		return result;
	}
	Rational minus(const Rational& c) const
	{
		int n = numerator * c.denominator - denominator * c.numerator;
		unsigned int d = denominator * c.denominator;
		Rational result(n, d);
		return result;
	}
	Rational multiple(const Rational& c) const
	{
		int n = numerator * c.numerator;
		unsigned int d = denominator * c.denominator;
		Rational result(n, d);
		return result;
	}
	Rational divide(const Rational& c) const
	{
		int n = numerator * c.denominator;
		unsigned int d = denominator * c.numerator;
		Rational result(n, d);
		return result;
	}
	void displayRational1() const
	{
		cout << numerator << "/" << denominator << endl;
	}
	void displayRational2() const
	{
		double ans = static_cast<double>(numerator) / denominator;
		cout << setprecision(2) << fixed << ans << endl;
	}

private:
	int numerator;
	unsigned int denominator;
};

int main()
{
	Rational a(2, 4);
	Rational b(21, 9);

	Rational c;
	Rational d;
	Rational e;
	Rational f;

	a.displayRational1();
	b.displayRational1();
	cout << endl;
	
	c = a.plus(b);
	d = a.minus(b);
	e = a.multiple(b);
	f = a.divide(b);

	c.displayRational1();
	c.displayRational2();
	cout << endl;

	d.displayRational1();
	d.displayRational2();
	cout << endl;

	e.displayRational1();
	e.displayRational2();
	cout << endl;

	f.displayRational1();
	f.displayRational2();
	cout << endl;

	return 0;
}