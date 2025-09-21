#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Person
{
public:
	Person(const string& first, const string& last, int a, int i)
	{
		setId(i);
		setAge(a);
		setFirstName(first);
		setLastName(last);
	}

	// accessor functions for id
	void setId(int i)
	{
		if (i > 0)
			id = i;
		else
			id = 0;
	}

	int getId() const
	{
		return id;
	}

	// accessor functions for lastName
	void setLastName(const string& s)
	{
		int i;
		for (i = 0; i < s.length(); i++)
		{
			lastName[i] = s[i];
		}
		lastName[i] = '\0';
	}

	string getLastName() const
	{
		return lastName;
	}

	// accessor functions for firstName
	void setFirstName(const string& s)
	{
		int i;
		for (i = 0; i < s.length(); i++)
		{
			firstName[i] = s[i];
		}
		firstName[i] = '\0';
	}

	string getFirstName() const
	{
		return firstName;
	}

	// accessor functions for age
	void setAge(int i)
	{
		if (i > 0)
			age = i;
		else
			age = 0;
	}

	int getAge() const
	{
		return age;
	}

private:
	char lastName[15];
	char firstName[10];
	int age;
	int id;
};

int main()
{
	// a)
	ofstream output("nameage.dat", ios::out | ios::binary);

	if (!output)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 100; i++)
	{
		Person blankPerson("", "unassigned", 0, i);
		output.write(reinterpret_cast<const char*>(&blankPerson), sizeof(Person));
	}

	// b)
	for (int i = 0; i < 10; i++)
	{
		int age;
		int id;
		string firstName;
		string lastName;

		cout << "Enter firstname, lastname, age, id: " << endl;
		cin >> firstName >> lastName >> age >> id;

		if (id >= 0 && id < 100)
		{
			Person p(firstName, lastName, age, id);
			output.seekp(id * sizeof(Person));
			output.write(reinterpret_cast<const char*>(&p), sizeof(Person));
		}
		else
			cout << "Wrong id input! " << endl;
	}

	// c)
	cout << endl << "Change a piece of information: " << endl;
	cout << "Enter firstname, lastname, age, id: " << endl;

	int age;
	int id;
	string firstName;
	string lastName;

	cin >> firstName >> lastName >> age >> id;
	Person p(firstName, lastName, age, id);

	ifstream input("nameage.dat", ios::in | ios::binary);
	input.seekg(id * sizeof(Person));
	Person g("", "", 0, 0);
	input.read(reinterpret_cast<char*>(&g), sizeof(Person));
	if (g.getLastName() == "unassigned")
		cout << "No info" << endl;

	output.seekp(id * sizeof(Person));
	output.write(reinterpret_cast<const char*>(&p), sizeof(Person));

	// d)
	cout << endl << "Delete a piece of information: " << endl;
	cout << "Enter id: " << endl;

	int ID;
	cin >> ID;
	Person blankPerson("", "unassigned", 0, ID);

	input.seekg(ID * sizeof(Person));
	Person h("", "", 0, 0);
	input.read(reinterpret_cast<char*>(&h), sizeof(Person));
	if (h.getLastName() != "unassigned")
	{
		output.seekp(ID * sizeof(Person));
		output.write(reinterpret_cast<const char*>(&blankPerson), sizeof(Person));
		cout << "Delete successfully! " << endl;
	}
	else
		cout << "The information does not exist! " << endl;

	return 0;
}