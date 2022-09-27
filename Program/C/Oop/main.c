#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Person.h"
#include "Employee.h"

int main(int agrv, const char *argc[])
{
    struct person *person = (struct person *)malloc(sizeof(struct person));
    initPerson(person);
    setAge(person, 12);
    printf("%d \n", person->age);

    struct employee *employee = (struct employee *)malloc(sizeof(struct employee));
    initEmployee(employee);
    setAge(&employee->person, 12);

    printf("%d \n", getAge(&employee->person));

    return 0;
}
