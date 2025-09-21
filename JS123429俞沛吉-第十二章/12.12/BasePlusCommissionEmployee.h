#ifndef BASEPLUS_H  
#define BASEPLUS_H  

#include <string>
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee 
{
public:
    BasePlusCommissionEmployee(const std::string& first, const std::string& last,
        const std::string& ssn, double sales = 0.0, double rate = 0.0, double salary = 0.0, const Date& d = Date(2000, 1, 1));
    virtual ~BasePlusCommissionEmployee() {} 

    void setBaseSalary(double);
    double getBaseSalary() const;

    virtual double earnings() const override;
    virtual void print() const override;  

private:
    double baseSalary;
};

#endif