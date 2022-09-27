#include "Employee.h"
#include "Person.h"
#include <stdio.h>

void initEmployee(struct employee *employee)
{
    initPerson(&employee->person);
    employee->ID = NULL;
    employee->salary = 0;
}

void setID(struct employee *employee, char *ID)
{
    employee->ID = ID;
}

char *getID(struct employee *employee)
{
    return employee->ID;
}

void setSalary(struct employee *employee, float salary)
{
    employee->salary = salary;
}

float getSalary(struct employee *employee)
{
    return employee->salary;
}