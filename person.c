//Authors: Adrià Arroyo & Miquel Saula
//Date: 2/12/2019
//Projectes de Programació I - La Salle URL
#include "person.h"


Person PERSON_create (char * name, int age){
    Person p;


    p.name = (char*) malloc (strlen(name) * sizeof(char) + 1);
    strcpy(p.name, name);

    p.age = age;

    return p;
}

char* PERSON_getName (Person p){
    return p.name;
}

int PERSON_getAge (Person p){
    return p.age;
}

void PERSON_setName (Person * p, char * nom){
    p->name = (char *) realloc(p->name, strlen(nom) * sizeof(nom) + 1);
    strcpy(p->name, nom);
}

void PERSON_setAge (Person * p, int age){
    p->age = age;
}

void PERSON_destroy (Person* p){
    free(p->name);
    p->name = NULL;
    p->age = 0;
}

Person PERSON_undefined (){
    Person p;

    p.name = NULL;
    p.age = -1;

    return p;
}

int PERSON_isUndefined (Person p){
    return p.name == NULL && p.age == -1;
}

int PERSON_compareByName (Person p1, Person p2){
    return strcmp(p1.name, p2.name);
}

int PERSON_compareByAge (Person p1, Person p2){
    return p1.age - p2.age;
}

TEST_CASE("Comprovant la generació de l'objecte", "[CREATE]") {
    char nom[] = "Ramon";
    Person p = PERSON_create(nom, 456);

    SECTION("Comprovant valors retornats") {
        REQUIRE(!strcmp("Ramon", p.name));
        REQUIRE(p.age == 456);
    }
}

TEST_CASE("Comprovant getters i setters", "[G&S]") {
    char nom[] = "Ramon";
    char nomAux[] = "Antoni";
    Person p = PERSON_create(nom, 456);

    SECTION("Comprovant getter edat") {
        REQUIRE(PERSON_getAge(p) == 456);
    }

    SECTION("Comprovant getter nom") {
        REQUIRE(!strcmp("Ramon", PERSON_getName(p)));
    }

    SECTION("Comprovant setter edat") {
        PERSON_setAge(&p, 23);
        REQUIRE(PERSON_getAge(p) == 23);
    }

    SECTION("Comprovant setter nom") {
        PERSON_setName(&p, nomAux);
        REQUIRE(!strcmp(nomAux, PERSON_getName(p)));
    }
}

TEST_CASE("Comprovant la destrucció de memoria", "[DESTROY]") {
    char nom[] = "Ramon";
    Person p = PERSON_create(nom, 456);

    PERSON_destroy(&p);

    printf("Nom despres de destruir: %s", p.name);

    REQUIRE(p.name == NULL);
    REQUIRE(p.age == 0);
}

TEST_CASE("Comprovant la generació de la persona no definida", "[UNDEFINED]") {
    Person p = PERSON_undefined();

    char nom[] = "Ramon";
    Person p2 = PERSON_create(nom, 456);

    SECTION("Comprovant si s'ha generat el perfil correcte") {
        REQUIRE(p.name == NULL);
        REQUIRE(p.age == -1);
    }

    SECTION("Comprovant funció isUndefined()") {
        REQUIRE(PERSON_isUndefined(p));
        REQUIRE(!PERSON_isUndefined(p2));
    }
}

TEST_CASE("Comprovació de les comparacions", "[COMPARISIONS]") {
    char nom1[] = "Ramon";
    Person p1 = PERSON_create(nom1, 123);

    char nom2[] = "Antoni";
    Person p2 = PERSON_create(nom2, 45);

    SECTION("Comprovant la comparació de noms") {
        REQUIRE(PERSON_compareByName(p1, p2) > 0);
        REQUIRE(PERSON_compareByName(p2, p1) < 0);
        REQUIRE(PERSON_compareByName(p1, p1) == 0);
    }

    SECTION("Comprovant la comparació d'edats") {
        REQUIRE(PERSON_compareByAge(p1, p1) == 0);
        REQUIRE(PERSON_compareByAge(p1, p2) > 0);
        REQUIRE(PERSON_compareByAge(p2, p1) < 0);
    }
}
