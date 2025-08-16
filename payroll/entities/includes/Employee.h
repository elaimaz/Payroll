#pragma once

#include <string>

enum class EmployeeType {
    H, // Hourly
    S, // MonthlySalary
    C  //MonthlySalaryWithCommissionRate
};

class Employee
{
private:
    unsigned long long EmpID;
    std::string Name;
    std::string Address;
    EmployeeType Type;
    // Income can be hourly-rate and monthly-salary
    double Income;
    double CommisionRate;

public:
    Employee(
        unsigned long long empID, 
        std::string name, 
        std::string address, 
        EmployeeType type,
        double income = 0.0,
        double commisionRate = 0.0);
    ~Employee();

    unsigned long long getEmpID() const { return EmpID; }
};
