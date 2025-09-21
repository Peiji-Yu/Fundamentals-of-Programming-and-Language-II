#include <iostream>  
#include <iomanip>  
#include <vector>  
#include "Employee.h"  
#include "SalariedEmployee.h"  
#include "CommissionEmployee.h"  
#include "BasePlusCommissionEmployee.h"  

using namespace std;

int main()
{
    cout << fixed << setprecision(2);

    Date d1(12, 3, 1990);
    Date d2(7, 23, 1978);
    Date d3(5, 15, 1999);

    SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", 800.0, d1);
    CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", 10000.0, 0.06, d2);
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000.0, 0.04, 300.0, d3);

    vector<Employee*> employees(3);

    employees[0] = &salariedEmployee;
    employees[1] = &commissionEmployee;
    employees[2] = &basePlusCommissionEmployee;

    string monthName[13] = { "","January","February","March","April","May","June","July","August","September","October","November","December"};

    for (int i = 1; i <= 12; i++)
    {
        cout << "Salaries for " << monthName[i] << ": \n\n";
        for (int j = 0; j < 3; j++)
        {
            employees[j]->print();
            cout << "\nearned $";
            if (employees[j]->getbirthMonth() == i)
                cout << (employees[j]->earnings() + 100) << endl << endl;
            else
                cout << employees[j]->earnings() << endl << endl;
        }
        cout << endl;
    }

    return 0;
}