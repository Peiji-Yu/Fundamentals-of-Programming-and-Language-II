#ifndef COMMISSION_H  
#define COMMISSION_H  

#include <string>
#include "Employee.h" 

using namespace std;

class CommissionEmployee : public Employee 
{
public:
    CommissionEmployee(const string& first, const string& last, const string& ssn, double grossSales = 0.0, double commissionRate = 0.0, const Date& d = Date(2000, 1, 1));
    virtual ~CommissionEmployee() {}

    void setCommissionRate(double);
    double getCommissionRate() const;

    void setGrossSales(double); 
    double getGrossSales() const; 

    virtual double earnings() const override;
    virtual void print() const override;

private:
    double grossSales; 
    double commissionRate; 
};

#endif
