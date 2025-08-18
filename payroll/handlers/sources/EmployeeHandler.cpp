#include "EmployeeHandler.h"

#include <vector>
#include <algorithm>

EmployeeHandler::EmployeeHandler(){}

EmployeeHandler::~EmployeeHandler(){}

static bool is_only_whitespace(const std::string& str);

std::vector<Employee> employees; // Store employees in a vector

int EmployeeHandler::AddEmployee(
    unsigned long long EmpID, 
    const std::string& Name, 
    const std::string& Address, 
    const EmployeeType& Type,
    const double Income,
    const double CommisionRate
) const {
    Employee employee(
        EmpID, 
        Name, 
        Address,
        Type
    );

    // TODO: Just to avoid unused variable warning
    if (Type == EmployeeType::C) {}
    if (CommisionRate == 0.0) {}

    for (const auto& emp : employees) {
        if (emp.getEmpID() == EmpID)
            return 0;
    }

    if (is_only_whitespace(Name))
        return 0;

    if (is_only_whitespace(Address))
        return 0;

    if (Income <= 0)
        return 0;

    if (Type == EmployeeType::C && CommisionRate < 0)
        return 0;

    employees.push_back(employee); // Add employee to the vector

    return 1;
}

bool EmployeeHandler::DeleteEmployee(const unsigned long long EmpID) const {
    auto it = std::remove_if(employees.begin(), employees.end(),
        [EmpID](const Employee& emp) { return emp.getEmpID() == EmpID; });

    if (it != employees.end()) {
        employees.erase(it, employees.end());
        return true;
    }
    return false;
}

static bool is_only_whitespace(const std::string& str) {
    return std::all_of(str.begin(), str.end(), 
        [](unsigned char c) { return std::isspace(c); });
}