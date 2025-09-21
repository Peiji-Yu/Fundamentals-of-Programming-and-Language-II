#ifndef HUGEINT_H
#define HUGEINT_H

#include <array>
#include <iostream>
#include <string>

using namespace std;

class HugeInt
{
	friend ostream& operator << (ostream&, const HugeInt&);
public:
	static const int digits = 30; // maximum digits in a HugeInt

	HugeInt(long = 0); // conversion/default constructor
	HugeInt(const string&); // conversion constructor

	// addition operator; HugeInt + HugeInt
	HugeInt operator+(const HugeInt&) const;

	// addition operator; HugeInt + int
	HugeInt operator+(int) const;

	// addition operator;
	// HugeInt + string that represents large integer value
	HugeInt operator+(const string&) const;

	bool operator>(const HugeInt&) const;
	bool operator>=(const HugeInt&) const;
	bool operator<(const HugeInt&) const;
	bool operator<=(const HugeInt&) const;
	bool operator==(const HugeInt&) const;
	bool operator!=(const HugeInt&) const;
	const HugeInt& operator+=(const HugeInt&);

	void carry(HugeInt&, int) const;
	HugeInt operator*(const HugeInt&) const;
	HugeInt operator/(const HugeInt&) const;
private:
	array<short, digits>integer;
};// end class HugetInt
#endif
