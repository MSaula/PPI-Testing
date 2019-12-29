#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../list.h"

TEST_CASE("Comprovant la creacio the List", "[CREATE]")
{
    List l;

    SECTION("Creant la llista")
    {
        l = LIST_create();
        REQUIRE(l.pri != NULL);
        REQUIRE(l.ult != NULL);

        SECTION("Comprovant que esta buida")
        {
            REQUIRE(LIST_isEmpty(l));
        }

        SECTION("Comprovant que es borra la llista")
        {
            REQUIRE(LIST_destroy(&l) == 1);
            REQUIRE(l.pri == NULL);
            REQUIRE(l.ult == NULL);
        }
    }
}

TEST_CASE("Comprovant el insert", "[INSERT]")
{
    List l;
    l = LIST_create();
    char nom[] = "Ramon";
    Person p = PERSON_create(nom, 456);

    SECTION("Comprovant que es pot afegir persones")
    {
        REQUIRE(LIST_add(&l, p));

        SECTION("Comprovant que s'ha guardat bé la persona")
        {
            REQUIRE(PERSON_isUndefined(LIST_getFirstPerson(l)) == 0);
            REQUIRE(PERSON_compareByName(LIST_getFirstPerson(l), p) == 0);
            REQUIRE(PERSON_compareByAge(LIST_getFirstPerson(l), p) == 0);
        }
    }
}

TEST_CASE("Comprovant l'esborrat d'una persona", "[DELETE]")
{
    List l;
    Person p1, p2;

    l = LIST_create();

    p1 = PERSON_create("Ramon", 93);
    p2 = PERSON_create("Antonia", 345);

    LIST_add(&l, p1);
    LIST_add(&l, p2);

    SECTION("Comprovant l'eliminació d'una persona inexistent") {
        REQUIRE(LIST_deletePerson(&l, "Miquel") == -1);
    }

    SECTION("Comprovant l'eliminació d'una persona existent") {
        REQUIRE(LIST_deletePerson(&l, "Ramon") == 1);
    }

    SECTION("Comprovant la eliminació completa") {
        LIST_deletePerson(&l, "Ramon");
        LIST_deletePerson(&l, "Antonia");
        REQUIRE(LIST_isEmpty(l));
    }

}
