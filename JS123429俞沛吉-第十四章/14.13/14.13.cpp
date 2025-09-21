#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

int main()
{
	ofstream output("datasize.dat", ios::out);

	if (!output)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	output << left << setw(25) << "char" << sizeof(char) << endl;
	output << left << setw(25) << "unsigned char" << sizeof(unsigned char) << endl;
	output << left << setw(25) << "short int" << sizeof(short int) << endl;
	output << left << setw(25) << "unsigned short int" << sizeof(unsigned short int) << endl;
	output << left << setw(25) << "int" << sizeof(int) << endl;
	output << left << setw(25) << "unsigned int" << sizeof(unsigned int) << endl;
	output << left << setw(25) << "long int" << sizeof(long int) << endl;
	output << left << setw(25) << "unsigned long int" << sizeof(unsigned long int) << endl;
	output << left << setw(25) << "float" << sizeof(float) << endl;
	output << left << setw(25) << "double" << sizeof(double) << endl;
	output << left << setw(25) << "long double" << sizeof(long double) << endl;

	return 0;
}