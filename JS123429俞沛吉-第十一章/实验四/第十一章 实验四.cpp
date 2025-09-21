#include<iostream>

using namespace std;

class MyBase
{
	int x;
public:
	MyBase(int a) :x(a){}
	int getX() { cout << " " << endl; return x; }
};

class MyDerived : public MyBase
{
	int y;
public:
	MyDerived(int a) :y(a), MyBase(a + 4) {}
	int getY() { cout << " " << endl; return y; }
};

int main()
{
	MyBase a(2), * p = &a;
	MyDerived b(4), * q = &b;
	MyBase& c = a;
	MyBase& d = b;
	cout << a.getX() << " " << p->getX();
	cout << b.getY() << " " << q->getY() << " " << b.getX() << " " << q->getX();
	a = b;
	cout << a.getX() << " ";
	p = q;
	cout << p->getX() << " ";
	cout << c.getX() << " " << d.getX() << " ";
	cout << b.getX() << " " << b.getY() << endl;
};