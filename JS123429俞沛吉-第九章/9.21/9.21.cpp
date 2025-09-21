#include<iostream>
#include<vector>

using namespace std;

class IntegerSet
{
public:
	IntegerSet()
		:a(101,false)
	{
	}
	IntegerSet(int b[], int size)
		:a(101, false)
	{
		for (int i = 0; i < size; i++)
			a[b[i]] = true;
	}
	IntegerSet unionOfSets(const IntegerSet& b) const
	{
		IntegerSet result;
		for (int i = 0; i < 101; i++)
		{
			if (a[i] == true || b.a[i] == true)
				result.insertElement(i);
		}
		return result;
	}
	IntegerSet intersectionOfSets(const IntegerSet& b) const
	{
		IntegerSet result;
		for (int i = 0; i < 101; i++)
		{
			if (a[i] == true && b.a[i] == true)
				result.insertElement(i);
		}
		return result;
	}
	void insertElement(int k)
	{
		if (k >= 0 && k <= 100)
			a[k] = true;
		else
			cout << "Wrong input! " << endl;
	}
	void printSet()
	{
		bool flag = true;
		for (int i = 0; i < 101; i++)
		{
			if (a[i] == true)
			{
				cout << i << " ";
				flag = false;
			}
		}
		if (flag)
			cout << "---";

		cout << endl;
	}
	bool isEqualTo(IntegerSet b)
	{
		for (int i = 0; i < 101; i++)
		{
			if (a[i] != b.a[i])
				return false;
		}
		return true;
	}
private:
	vector<bool>a;
};

int main()
{
	int intS[5] = { 1,3,8,12,14 };

	IntegerSet a;
	IntegerSet b(intS, 5);

	a.printSet();
	b.printSet();

	a.insertElement(1);
	a.insertElement(8);
	a.insertElement(9);
	a.insertElement(11);
	a.printSet();

	IntegerSet c = a.unionOfSets(b);
	c.printSet();

	a.intersectionOfSets(b).printSet();

	cout << boolalpha << a.isEqualTo(b) << endl;

	return 0;
}