#ifndef EMPLOYEE_
#define EMPLOYEE_
#include "Person.h"

struct employee
{
    char *ID;
    float salary;
    struct person person;
};

void initEmployee(struct employee *);

void setID(struct employee *, char *ID);

char *getID(struct employee *);

void setSalary(struct employee *, float salary);

float getSalary(struct employee *);

#endif