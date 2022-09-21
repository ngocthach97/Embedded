#include <stdio.h>
#include <string.h>

struct Person
{
    int ID;
    char name[50];
    char address[50];
    int age;
};

int main(int agrv, const char *argc[])
{
    struct Person p;
    FILE *file;
    file = fopen("/home/nguyen/Embedded/Program/C/IO/data.txt", "r");
    if (file == NULL)
    {
        printf("no such file./n");
        return 0;
    }
    while (fscanf(file, "%d\t%s\t%s\t%d", &p.ID, p.name, p.address, &p.age) != EOF)
    {
        printf("ID: %d\tName: %s\tAddress: %s\tAge: %d\n", p.ID, p.name, p.address, p.age);
    }
    fclose(file);
    return 0;
}
