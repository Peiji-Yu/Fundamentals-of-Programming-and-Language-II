#ifndef DATE_H  
#define DATE_H  

#include <array>  
#include <iostream>  

using namespace std;

class Date
{
    friend ostream& operator<<(ostream&, const Date&);
    friend class Employee;
public:
    Date(int m = 1, int d = 1, int y = 1900);
    void setDate(int, int, int);
    Date& operator++();
    Date operator++(int);
    Date& operator+=(unsigned int); 
    static bool leapYear(int);
    bool endOfMonth(int) const; 
private:
    unsigned int month;
    unsigned int day;
    unsigned int year;
    static const array<unsigned int, 13> days;
    void helpIncrement();
};

#endif  
