//Authors: Adrià Arroyo & Miquel Saula
//Date: 2/12/2019
//Projectes de Programació I - La Salle URL

#include "person.h"

Person PERSON_create (char * name, int age) {
    Person p;

    p.name = (char*) malloc (strlen(name) * sizeof(char) + 1);
    strcpy(p.name, name);

    p.age = age;

    return p;
}

char* PERSON_getName (Person p) {
    return p.name;
}

int PERSON_getAge (Person p) {
    return p.age;
}

void PERSON_setName (Person * p, char * nom) {
    p->name = (char *) realloc(p->name, strlen(nom) * sizeof(nom) + 1);
    strcpy(p->name, nom);
}

void PERSON_setAge (Person * p, int age) {
    p->age = age;
}

void PERSON_destroy (Person* p) {
    free(p->name);
    p->name = NULL;
    p->age = 0;
}

Person PERSON_undefined () {
    Person p;

    p.name = NULL;
    p.age = -1;

    return p;
}

int PERSON_isUndefined (Person p) {
    return p.name == NULL && p.age == -1;
}

int PERSON_compareByName (Person p1, Person p2) {
    return strcmp(p1.name, p2.name);
}

int PERSON_compareByAge (Person p1, Person p2) {
    return p1.age - p2.age;
}
