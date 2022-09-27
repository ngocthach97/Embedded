#ifndef PERSON_
#define PERSON_

struct person
{
    char *name;
    int age;
    int *phone;
    char *email;
    char *provinceCode;
    char *districtCode;
    char *ward;
};

void initPerson(struct person *);

char *getName(struct person *);

void setName(struct person *, char *name);

int getAge(struct person *);

void setAge(struct person *, int age);

int *getPhone(struct person *);

void setPhone(struct person *, int *phone);

char *getEmail(struct person *);

void setEmail(struct person *, char *email);

char *getProvince(struct person *);

void setProvince(struct person *, char *province);

char *getDistrict(struct person *);

void setDistrict(struct person *, char *district);

char *getWard(struct person *);

void setWard(struct person *, char *ward);

#endif