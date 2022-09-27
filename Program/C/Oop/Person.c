#include "Person.h"
#include <stdio.h>
#include <stdlib.h>

void initPerson(struct person *person)
{
    person->name = NULL;
    person->age = 0;
    person->phone = NULL;
    person->email = NULL;
    person->provinceCode = NULL;
    person->districtCode = NULL;
    person->ward = NULL;
}

char *getName(struct person *person)
{
    return person->name;
}

void setName(struct person *person, char *name)
{
    person->name = name;
}

int getAge(struct person *person)
{
    return person->age;
}

void setAge(struct person *person, int age)
{
    person->age = age;
}