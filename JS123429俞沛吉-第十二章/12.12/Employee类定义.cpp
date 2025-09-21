#include<iostream>
#include"Employee.h"

using namespace std;

Employee::Employee(const string& first, const string& last,
	const string& ssn, const Date& dateOfBirth)
	:firstName(first), lastName(last), socialSecurityNumber(ssn), birthDate(dateOfBirth)
{
}

const Employee& Employee::operator=(const Employee& right)
{
	if (&right != this)
	{
		firstName = right.firstName;
		lastName = right.lastName;
		socialSecurityNumber = right.socialSecurityNumber;
		birthDate = right.birthDate;
	}
	return *this;
}

void Employee::setFirstName(const string& first)
{
	firstName = first;
}

string Employee::getFirstName() const
{
	return firstName;
}

void Employee::setLastName(const string& last)
{
	lastName = last;
}

string Employee::getLastName()const
{
	return lastName;
}

void Employee::setSocialSecurityNumber(const string& ssn)
{
	socialSecurityNumber = ssn;
}

string Employee::getSocialSecurityNumber()const
{
	return socialSecurityNumber;
}

int Employee::getbirthMonth()const
{
	return birthDate.month;
}

void Employee::print()const
{
	cout << getFirstName() << " " << getLastName()
		<< "\nsocial security number:" << getSocialSecurityNumber();
	cout << endl << "date of birth: " << birthDate;
}