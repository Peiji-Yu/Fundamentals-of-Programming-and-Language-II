#include<iostream>

using namespace std;

class TestException : public runtime_error
{
public:
	TestException() :runtime_error("Caught TestException")
	{
	}
};

void f()
{
	throw TestException();
}

void g()
{
	f();
}

void h()
{
	g();
}

int main()
{
	try
	{
		h();
	}
	catch (TestException& exception)
	{
		cout << "In main: " << exception.what() << endl;
	}

	return 0;
}