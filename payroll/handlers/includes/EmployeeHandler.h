#pragma once

#include "IEmployee.h"

class EmployeeHandler : public IEmployee
{
private:
    /* data */
public:
    EmployeeHandler(/* args */);
    ~EmployeeHandler();

    /**
     * @brief Try add employee.
     * 
     * @param EmpID employee ID.
     * @param Name employee name.
     * @param Address employee address.
     * @param Type employee type.
     * @param Income employee income can be hourly-rate or monthly-salary (default is 0.0).
     * @param CommisionRate employee commission rate (default is 0.0).
     * @return Number of employees added.
     */
    int addEmployee(
        unsigned long long EmpID, 
        const std::string& Name, 
        const std::string& Address, 
        const EmployeeType& Type, 
        const double Income = 0.0,
        const double CommisionRate = 0.0
    ) const override;
};
