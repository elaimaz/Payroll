#include <gtest/gtest.h>

#include "EmployeeHandler.h"

class EmployeeTest : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

};

// Test error adding employee with duplicate Employee ID
TEST_F(EmployeeTest, ErrorAddEmployeeNotValidEmpID) {
    EmployeeHandler Handler;

    unsigned long long EmpID = 1;
    std::string Name = "John Doe";
    std::string Address = "123 Main St";
    EmployeeType Type = EmployeeType::H;
    double Income = 20.0;

    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income), 1);

    EmpID = 1; // Duplicate ID
    Name = "Joana Doe";
    Address = "456 Elm St";

    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income), 0);
}

// Test error adding employee with not valid name
TEST_F(EmployeeTest, ErrorAddEmployeeNotValidName) {
    EmployeeHandler Handler;

    unsigned long long EmpID = 1;
    std::string Name = "     "; // Invalid name
    std::string Address = "123 Main St";
    EmployeeType Type = EmployeeType::H;
    double Income = 20.0;

    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income), 0);

    EmpID = 2;
    Name = ""; // Empty name

    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income), 0);
}

// Test error adding employee with not valid address
TEST_F(EmployeeTest, ErrorAddEmployeeNotValidAddress) {
    EmployeeHandler Handler;

    unsigned long long EmpID = 1;
    std::string Name = "John Doe";
    std::string Address = "     "; // Invalid address
    EmployeeType Type = EmployeeType::H;
    double Income = 20.0;

    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income), 0);

    EmpID = 2;
    Name = "Joana Doe";
    Address = ""; // Empty address

    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income), 0);
}

// Test adding a hourly employee
TEST_F(EmployeeTest, AddHourlyEmployee) {
    EmployeeHandler Handler;

    unsigned long long EmpID = 1;
    std::string Name = "Alear";
    std::string Address = "Somniel";
    EmployeeType Type = EmployeeType::H;
    double Income = 20.0;

    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income), 1);
}

// Test not adding a hourly employee with error in hourly-rate
TEST_F(EmployeeTest, ErrorAddHourlyEmployeeNotValidHourlyRate) {
    EmployeeHandler Handler;

    unsigned long long EmpID = 1;
    std::string Name = "Alear";
    std::string Address = "Somniel";
    EmployeeType Type = EmployeeType::H;
    double Income = 0.0; // Invalid hourly-rate

    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income), 0);

    EmpID = 2;
    Name = "Etie";
    Address = "Firene";
    Income = -20.0; // Invalid Negative hourly-rate

    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income), 0);
}

// Test adding a monthly-salary employee
TEST_F(EmployeeTest, AddMonthlySalaryEmployee) {
    EmployeeHandler Handler;

    unsigned long long EmpID = 1;
    std::string Name = "Alear";
    std::string Address = "Somniel";
    EmployeeType Type = EmployeeType::S;
    double Income = 3000.0;

    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income), 1);
}

// Test adding a monthly-salary employee with comission-rate
TEST_F(EmployeeTest, AddMonthlySalaryWithCommissionRateEmployee) {
    EmployeeHandler Handler;

    unsigned long long EmpID = 1;
    std::string Name = "Alear";
    std::string Address = "Somniel";
    EmployeeType Type = EmployeeType::C;
    double Income = 3000.0;
    double CommisionRate = 1.0;

    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income, CommisionRate), 1);
}

// Test not adding a monthly salary employee error in monthly-salary
TEST_F(EmployeeTest, ErrorAddMonthlySalaryEmployeeNotValidMonthlySalary) {
    EmployeeHandler Handler;

    unsigned long long EmpID = 1;
    std::string Name = "Alear";
    std::string Address = "Somniel";
    EmployeeType Type = EmployeeType::C;
    double Income = 0.0; // Invalid monthly-salary
    double CommisionRate = 1.0;

    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income, CommisionRate), 0);

    EmpID = 2;
    Name = "Etie";
    Address = "Firene";
    Income = -3000.0; // Invalid Negative monthly-salary
    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income, CommisionRate), 0);
}

// Test not adding a monthly salary employee error in comission-rate
TEST_F(EmployeeTest, ErrorAddMonthlySalaryEmployeeNotValidComissionRate) {
    EmployeeHandler Handler;

    unsigned long long EmpID = 1;
    std::string Name = "Alear";
    std::string Address = "Somniel";
    EmployeeType Type = EmployeeType::C;
    double Income = 3000.0; 
    double CommisionRate = -1.0;

    ASSERT_EQ(Handler.addEmployee(EmpID, Name, Address, Type, Income, CommisionRate), 0);
}
