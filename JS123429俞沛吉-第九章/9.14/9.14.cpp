#include<iostream>
#include<array>
#include<string>

using namespace std;

class HugeInteger
{
public:
	void input(string s)
	{
		if (s.length() > 40)
		{
			cout << "Limit integer to 40 digits! " << endl;
			s = s.substr(0, 40);
		}
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				HugeInt[i + 40 - s.length()] = s[i] - 48;
			else
			{
				cout << "Wrong input: " << s[i] << "!" << endl;
				HugeInt[i + 40 - s.length()] = 0;
			}
		}
	}
	void output()
	{
		cout << "The HugeInteger is: ";
		bool flag = false;
		for (int i = 0; i < 39; i++)
		{
			if (flag == true)
				cout << HugeInt[i];
			else if (HugeInt[i] != 0)
			{
				cout << HugeInt[i];
				flag = true;
			}
		}
		cout << HugeInt[39] << endl;
	}
	HugeInteger add(HugeInteger c)
	{
		HugeInteger result;
		unsigned int carry = 0;
		for (int i = 39; i >= 0; i--)
		{
			unsigned int value = HugeInt[i] + c.HugeInt[i] + carry;
			result.HugeInt[i] = value % 10;
			carry = value / 10;
		}
		if (carry != 0)
			cout << "Warning: Overflow! " << endl;
		return result;
	}
	HugeInteger substract(HugeInteger c)
	{
		HugeInteger result;
		int rent = 0;
		for (int i = 39; i >= 0; i--)
		{
			int value = HugeInt[i] - c.HugeInt[i] - rent;
			if (value < 0)
			{
				value += 10;
				rent = 1;
			}
			else
				rent = 0;
			result.HugeInt[i] = value;
		}
		if (rent)
			cout << "Warning: Negative Value! " << endl;
		return result;
	}
	bool isEqualTo(HugeInteger c)
	{
		for (int i = 0; i < 40; i++)
		{
			if (HugeInt[i] != c.HugeInt[i])
				return false;
		}
		return true;
	}
	bool isNotEqualTo(HugeInteger c)
	{
		for (int i = 0; i < 40; i++)
		{
			if (HugeInt[i] != c.HugeInt[i])
				return true;
		}
		return false;
	}
	bool isGreaterThan(HugeInteger c)
	{
		for (int i = 0; i < 40; i++)
		{
			if (HugeInt[i] > c.HugeInt[i])
				return true;
			else if (HugeInt[i] < c.HugeInt[i])
				return false;
		}
		return false;
	}
	bool isLessThan(HugeInteger c)
	{
		for (int i = 0; i < 40; i++)
		{
			if (HugeInt[i] > c.HugeInt[i])
				return false;
			else if (HugeInt[i] < c.HugeInt[i])
				return true;
		}
		return false;
	}
	bool isGreaterThanOrEqualTo(HugeInteger c)
	{
		for (int i = 0; i < 40; i++)
		{
			if (HugeInt[i] > c.HugeInt[i])
				return true;
			else if (HugeInt[i] < c.HugeInt[i])
				return false;
		}
		return true;
	}
	bool isLessThanOrEqualTo(HugeInteger c)
	{
		for (int i = 0; i < 40; i++)
		{
			if (HugeInt[i] > c.HugeInt[i])
				return false;
			else if (HugeInt[i] < c.HugeInt[i])
				return true;
		}
		return true;
	}
	bool isZero()
	{
		for (int i = 0; i < 40; i++)
		{
			if (HugeInt[i] != 0)
				return false;
		}
		return true;
	}
private:
	array<unsigned int, 40>HugeInt = {};
};

int main()
{
	HugeInteger a;
	HugeInteger b;
	HugeInteger c;
	HugeInteger d;
	HugeInteger g;

	HugeInteger e;
	HugeInteger f;

	string r = "3856490217";
	string s = "4982017635";
	string u = "0";
	string m = "38491";
	string n = "18284";

	a.input(r);
	a.output();

	b.input(s);
	b.output();

	c.input(u);
	c.output();

	e.input(m);
	e.output();

	f.input(n);
	f.output();

	cout << endl << boolalpha << a.isEqualTo(b) << endl;
	cout << a.isNotEqualTo(b) << endl;
	cout << a.isGreaterThan(b) << endl;
	cout << a.isLessThan(b) << endl;
	cout << a.isGreaterThanOrEqualTo(b) << endl;
	cout << a.isLessThanOrEqualTo(b) << endl;
	cout << c.isZero() << endl;

	cout << endl;
	c = a.add(b);
	c.output();

	g = b.substract(a);
	g.output();

	return 0;
}