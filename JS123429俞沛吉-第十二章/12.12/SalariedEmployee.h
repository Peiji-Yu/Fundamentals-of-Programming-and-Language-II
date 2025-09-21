#ifndef SALARIED_H
#define SALARIED_H

#include <string>
#include "Employee.h"

using namespace std;

class SalariedEmployee : public Employee
{
public:
	SalariedEmployee(const string&, const string&, const string&, double = 0.0, const Date &d= Date(2000, 1, 1));
	virtual ~SalariedEmployee(){}

	void setWeeklySalary(double);
	double getWeeklySalary() const;

	virtual double earnings() const override;
	virtual void print() const override;
private:
	double weeklySalary;
};

#endif
