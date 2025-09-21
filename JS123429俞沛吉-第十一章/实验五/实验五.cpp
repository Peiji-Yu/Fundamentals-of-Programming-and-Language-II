#include <iostream>

using namespace std;

class Date
{
public:
	Date(int y, int m, int d) :year(y), month(m), day(d) {}
	void print() const
	{
		cout << year << "-" << month << "-" << day << endl;
	}
private:
	int year;
	int month;
	int day;
};

class FinalTest
{
public:
	FinalTest(string t, Date d = Date(2014, 1, 1)) :test(t), date(d) {}
	void print() const
	{
		cout << "Title: " << test << endl;
		cout << "Test Date: ";
		date.print();
	}
	void setDue(Date d)
	{
		date = d;
	}
private:
	string test;
	Date date;
};

int main()
{
	FinalTest item1("C++ Test", Date(2014, 6, 2));
	item1.print();
	FinalTest item2("Java");
	item2.print();
	item2.setDue(Date(2014, 6, 10));
	item2.print();
}