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