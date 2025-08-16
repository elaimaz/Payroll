#include "Employee.h"

Employee::Employee(
    unsigned long long empID, 
    std::string name, 
    std::string address, 
    EmployeeType type,
    double income,
    double commisionRate)
    : 
    EmpID(empID), 
    Name(std::move(name)), 
    Address(std::move(address)), 
    Type(type), 
    Income(income), 
    CommisionRate(commisionRate) {}

Employee::~Employee() = default;