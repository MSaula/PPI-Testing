#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../list.h"

TEST_CASE("Comprovant la creacio the List", "[CREATE]")
{
    List l;
    l = LIST_create();
    if(LIST_isEmpty())
}