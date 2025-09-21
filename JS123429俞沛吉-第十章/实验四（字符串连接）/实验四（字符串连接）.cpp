#include <iostream>

#pragma warning(disable : 4996)

#include "String.h"

using namespace std;

int main()
{
	String string1, string2("The date is");
	String string3(" August 1, 1993");

	cout << "string1 = string2 + string3\n";
	string1 = string2 + string3;
	cout << "\"" << string1 << "\" = \"" << string2 << "\" + \"" << string3 << "\"" << endl;

	return 0;
}