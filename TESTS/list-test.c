#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../list.h"

TEST_CASE("Comprovant la creacio the List", "[CREATE]") {
    List l;

    SECTION("Creant la llista") {
        l = LIST_create();
        REQUIRE(l.pri != NULL);
        REQUIRE(l.ult != NULL);

        SECTION("Comprovant que esta buida") {
            REQUIRE(LIST_isEmpty(l));
        }

        SECTION("Comprovant que es borra la llista") {
            REQUIRE(LIST_destroy(&l) == 1);
            REQUIRE(l.pri == NULL);
            REQUIRE(l.ult == NULL);
        }
    }
}

TEST_CASE("Comprovant el add", "[INSERT]") {
    List l;
    l = LIST_create();
    char nom[] = "Ramon";
    Person p = PERSON_create(nom, 456);

    SECTION("Comprovant que es pot afegir persones") {
        REQUIRE(LIST_add(&l, p));

        SECTION("Comprovant que s'ha guardat bé la persona") {
            REQUIRE(!PERSON_isUndefined(LIST_getFirstPerson(l)));
            REQUIRE(PERSON_compareByName(LIST_getFirstPerson(l), p) == 0);
            REQUIRE(PERSON_compareByAge(LIST_getFirstPerson(l), p) == 0);
        }
    }
}

TEST_CASE("Comprovant la eliminació de la llista", "[DESTROY]") {
    List l;
    Person p1, p2;
    char nom1[] = "Ramon";
    char nom2[] = "Antonia";

    l = LIST_create();

    p1 = PERSON_create(nom1, 93);
    p2 = PERSON_create(nom2, 345);

    LIST_add(&l, p1);
    LIST_add(&l, p2);

    SECTION("Comprovant que es borra la llista") {
        REQUIRE(LIST_destroy(&l) == 1);
        REQUIRE(l.pri == NULL);
        REQUIRE(l.ult == NULL);
    }
}

TEST_CASE("Comprovant la funció LIST_isEmpty", "[EMPTY]") {
    List l;
    Person p1, p2;
    char nom1[] = "Ramon";
    char nom2[] = "Antonia";

    l = LIST_create();

    p1 = PERSON_create(nom1, 93);
    p2 = PERSON_create(nom2, 345);

    SECTION("Abans d'afegir cap persona") {
        REQUIRE(LIST_isEmpty(l));
    }

    LIST_add(&l, p1);
    LIST_add(&l, p2);

    SECTION("Després d'afegir els elements") {
        REQUIRE(!LIST_isEmpty(l));
    }
}

TEST_CASE("Comprovant l'esborrat d'una persona", "[DELETE]") {
    List l;
    Person p1, p2;
    char nom1[] = "Ramon";
    char nom2[] = "Antonia";
    char nom3[] = "Miquel";

    l = LIST_create();

    p1 = PERSON_create(nom1, 93);
    p2 = PERSON_create(nom2, 345);

    LIST_add(&l, p1);
    LIST_add(&l, p2);

    SECTION("Comprovant l'eliminació d'una persona inexistent") {
        REQUIRE(LIST_deletePerson(&l, nom3) == -1);
    }

    SECTION("Comprovant l'eliminació d'una persona existent") {
        REQUIRE(LIST_deletePerson(&l, nom1) == 1);
        REQUIRE(PERSON_isUndefined(LIST_getPerson(l, nom1)));
    }

    SECTION("Comprovant la eliminació completa") {
        REQUIRE(!LIST_isEmpty(l));
        LIST_deletePerson(&l, nom1);
        LIST_deletePerson(&l, nom2);
        REQUIRE(LIST_isEmpty(l));
    }

}

TEST_CASE("Comprovant l'eliminació a partir de la funció LIST_deleteFirstPerson()", "[DELETE_FIRST]") {
    List l;
    Person p1, p2, paux;
    char nom1[] = "Ramon";
    char nom2[] = "Antonia";

    l = LIST_create();

    p1 = PERSON_create(nom1, 93);
    p2 = PERSON_create(nom2, 345);

    LIST_add(&l, p1);
    LIST_add(&l, p2);

    SECTION("Comprovant l'eliminació del primer element") {
        paux = LIST_getFirstPerson(l);
        REQUIRE(PERSON_compareByName(paux, p2) == 0);
        REQUIRE(LIST_deleteFirstPerson(&l) == 1);
        paux = LIST_getFirstPerson(l);
        REQUIRE(PERSON_compareByName(paux, p1) == 0);
    }
}

TEST_CASE("Comprovant la funció LIST_getPerson()", "[GET]") {
    List l;
    Person p1, p2, paux;
    char nom1[] = "Ramon";
    char nom2[] = "Antonia";
    char nom3[] = "Miquel";

    l = LIST_create();

    p1 = PERSON_create(nom1, 93);
    p2 = PERSON_create(nom2, 345);

    LIST_add(&l, p1);
    LIST_add(&l, p2);

    SECTION("Comprovant un GET satisfactori") {
        paux = LIST_getPerson(l, nom1);
        REQUIRE(PERSON_compareByName(paux, p1) == 0);
        REQUIRE(PERSON_compareByAge(paux, p1) == 0);
    }

    SECTION("Comprovant un GET no satisfactori") {
        paux = LIST_getPerson(l, nom3);
        REQUIRE(PERSON_isUndefined(paux));
    }
}

TEST_CASE("Comprovant la obtenció del primer element", "[GET_FIRST]") {
    List l;
    Person p1, p2, paux, pauxx;
    char nom1[] = "Ramon";
    char nom2[] = "Antonia";

    l = LIST_create();

    p1 = PERSON_create(nom1, 93);
    p2 = PERSON_create(nom2, 345);

    LIST_add(&l, p1);
    LIST_add(&l, p2);

    SECTION("Comprovant la funció getFirst") {
        paux = LIST_getFirstPerson(l);
        pauxx = LIST_getPerson(l, nom2);
        REQUIRE(PERSON_compareByName(paux, pauxx) == 0);
        REQUIRE(PERSON_compareByAge(paux, pauxx) == 0);
    }
}

TEST_CASE("Comprovant la funció LIST_size()", "[SIZE]") {
    List l;
    Person p1, p2;
    char nom1[] = "Ramon";
    char nom2[] = "Antonia";

    l = LIST_create();

    p1 = PERSON_create(nom1, 93);
    p2 = PERSON_create(nom2, 345);

    SECTION("Size al afegir elements") {
        REQUIRE(LIST_size(l) == 0);
        LIST_add(&l, p1);
        REQUIRE(LIST_size(l) == 1);
        LIST_add(&l, p2);
        REQUIRE(LIST_size(l) == 2);
    }

    LIST_add(&l, p1);
    LIST_add(&l, p2);

    SECTION("Size al eliminar elements") {
        REQUIRE(LIST_size(l) == 2);
        LIST_deletePerson(&l, nom1);
        REQUIRE(LIST_size(l) == 1);
        LIST_deletePerson(&l, nom2);
        REQUIRE(LIST_size(l) == 0);
    }
}

TEST_CASE("Comprovant el getter d'edat més gran", "[GET_OLDEST]") {
    List l;
    Person p1, p2, p3, p4, p5, paux;
    char nom1[] = "Ramon";
    char nom2[] = "Antonia";
    char nom3[] = "Miquel";

    l = LIST_create();

    p1 = PERSON_create(nom1, 93);
    p2 = PERSON_create(nom2, 33);
    p3 = PERSON_create(nom3, 21);
    p4 = PERSON_create(nom2, 22);
    p5 = PERSON_create(nom1, 27);

    SECTION("Obtenció del més gran sense elements a la llista") {
        paux = LIST_getOldestPerson(l);
        REQUIRE(PERSON_isUndefined(paux));
    }

    LIST_add(&l, p1);
    LIST_add(&l, p2);
    LIST_add(&l, p3);
    LIST_add(&l, p4);
    LIST_add(&l, p5);

    SECTION("Obtenció del més gran") {
        paux = LIST_getOldestPerson(l);
        REQUIRE(PERSON_compareByName(paux, p1) == 0);
        REQUIRE(PERSON_compareByAge(paux, p1) == 0);
    }
}

TEST_CASE("Comprovant el getter d'edat més petits", "[GET_YOUNGEST]") {
    List l;
    Person p1, p2, p3, p4, p5, paux;
    char nom1[] = "Ramon";
    char nom2[] = "Antonia";
    char nom3[] = "Miquel";

    l = LIST_create();

    p1 = PERSON_create(nom1, 93);
    p2 = PERSON_create(nom2, 33);
    p3 = PERSON_create(nom3, 21);
    p4 = PERSON_create(nom2, 22);
    p5 = PERSON_create(nom1, 27);

    SECTION("Obtenció del més gran sense elements a la llista") {
        paux = LIST_getYoungestPerson(l);
        REQUIRE(PERSON_isUndefined(paux));
    }

    LIST_add(&l, p1);
    LIST_add(&l, p2);
    LIST_add(&l, p3);
    LIST_add(&l, p4);
    LIST_add(&l, p5);

    SECTION("Obtenció del més petit") {
        paux = LIST_getYoungestPerson(l);
        REQUIRE(PERSON_compareByName(paux, p3) == 0);
        REQUIRE(PERSON_compareByAge(paux, p3) == 0);
    }
}
