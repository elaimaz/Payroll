#pragma once

#include "Employee.h"

class IEmployee {
public:
    virtual int addEmployee(
        unsigned long long EmpID, 
        const std::string& Name, 
        const std::string& Address, 
        const EmployeeType& Type,
        const double Income = 0.0,
        const double CommisionRate = 0.0
    ) const = 0;

    virtual ~IEmployee() = default;
};