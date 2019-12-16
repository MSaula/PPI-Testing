#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../list.h"

TEST_CASE("Comprovant la creacio the List", "[CREATE]")
{
    List l;

    SECTION("Creant la llista")
    {
        l = LIST_create();
    }

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

TEST_CASE("Comprovant el insert", "[INSERT]")
{

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
