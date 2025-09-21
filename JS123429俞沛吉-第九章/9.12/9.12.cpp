#include<iostream>
#include<array>
#include<cmath>

using namespace std;

class Rectangle
{
public:
	Rectangle(const array<double, 2>& m, const array<double, 2>& n, const array<double, 2>& p, const array<double, 2>& q)
		:a({ 1,1 }),
		b({ 1,1 }),
		c({ 1,1 }),
		d({ 1,1 })
	{
		Set(m, n, p, q);
		Calculate();
	}
	void Set(const array<double, 2>& m, const array<double, 2>& n, const array<double, 2>& p, const array<double, 2>& q)
	{
		if (m[0] <= 20 && m[0] > 0 && m[1] <= 20 && m[1] > 0 && n[0] <= 20 && n[0] > 0 && n[1] <= 20 && n[1] > 0 && p[0] <= 20 && p[0] > 0 && p[1] <= 20 && p[1] > 0 && q[0] <= 20 && q[0] > 0 && q[1] <= 20 && q[1] > 0 && m[0] + p[0] == n[0] + q[0] && m[1] + p[1] == n[1] + q[1] && (n[0] - m[0]) * (p[0] - n[0]) + (n[1] - m[1]) * (p[1] - n[1]) == 0)
		{
			a = m;
			b = n;
			c = p;
			d = q;
		}
		else
			cout << "Wrong input! " << endl;
	}
	void Calculate()
	{
		double x, y;
		x = sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
		y = sqrt(pow(c[0] - b[0], 2) + pow(c[1] - b[1], 2));
		if (x >= y)
		{
			length = x;
			width = y;
		}
		else
		{
			length = y;
			width = x;
		}
		perimeter = (length + width) * 2;
		area = length * width;
	}
	bool square()
	{
		if (length == width)
			return true;
		else
			return false;
	}
	void displayRectangle()
	{
		cout << (square() ? "Square" : "Rectangle") << endl;
		cout << "length: " << length << endl;
		cout << "width: " << width << endl;
		cout << "perimeter: " << perimeter << endl;
		cout << "area: " << area << endl;
	}
private:
	array<double, 2>a;
	array<double, 2>b;
	array<double, 2>c;
	array<double, 2>d;
	double length;
	double width;
	double perimeter;
	double area;
};

int main()
{
	array<double, 2>a = { 4,1 };
	array<double, 2>b1 = { 8,4 };
	array<double, 2>c1 = { 5,8 };
	array<double, 2>d = { 1,5 };
	array<double, 2>b2 = { 12,7 };
	array<double, 2>c2 = { 9,11 };

	Rectangle s(a, b1, c1, d);
	s.displayRectangle();

	cout << endl;
	Rectangle r(a, b2, c2, d);
	r.displayRectangle();

	return 0;
}