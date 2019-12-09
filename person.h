#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    int age;
} Person;

Person PERSON_create(char *name, int age);
char *PERSON_getName(Person p);
int PERSON_getAge(Person p);
void PERSON_setName(Person *p, char *nom);
void PERSON_setAge(Person *p, int age);
void PERSON_destroy(Person *p);
Person PERSON_undefined();
int PERSON_isUndefined(Person p);
int PERSON_compareByName(Person p1, Person p2);
int PERSON_compareByAge(Person p1, Person p2);
