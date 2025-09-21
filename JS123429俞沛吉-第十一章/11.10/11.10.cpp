#include <iostream>

using namespace std;

class Account
{
public:
	Account(double b)
	{
		if (b >= 0)
			balance = b;
		else
		{
			balance = 0;
			throw invalid_argument("Balance must >0! ");
		}
	}
	void credit(double m)
	{
		balance += m;
	}
	bool debit(double m)
	{
		if (m > balance)
		{
			cout << "Debit amount exceeded account balance. " << endl;
			return false;
		}
		else
		{
			balance -= m;
			return true;
		}
	}
	double getBalance()
	{
		return balance;
	}
private:
	double balance;
};

class SavingsAccount : public Account
{
public:
	SavingsAccount(double b, double ir) :Account(b), InterestRate(ir) {}
	double calculateInterest()
	{
		return getBalance() * InterestRate / 100;
	}
private:
	double InterestRate;
};

class CheckingAccount : public Account
{
public:
	CheckingAccount(double b, double f) :Account(b), fee(f) {}
	void credit(double m)
	{
		Account::credit(m);
		Account::debit(fee);
	}
	void debit(double m)
	{
		bool flag = Account::debit(m);
		if (flag)
			Account::debit(fee);
	}
private:
	double fee;
};

int main()
{
	Account a(1000);
	SavingsAccount b(500, 5);
	CheckingAccount c(2000, 10);

	a.credit(500);
	a.debit(2000);
	cout << a.getBalance() << endl;

	double i = b.calculateInterest();
	cout << i << endl;
	b.credit(i);
	cout << b.getBalance() << endl;

	c.credit(500);
	c.debit(1000);
	cout << c.getBalance() << endl;
}