#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "twostack.cpp"

TEST_CASE("Two Stack") 
{
  SUBCASE("Valid Expressions") 
  {
    REQUIRE_EQ(twostack((char*)"((1 + 1)+(1+1))"), 4.0);
    REQUIRE_EQ(twostack((char*)"(1 - 1)"), 0.0);
    REQUIRE_EQ(twostack((char*)"(1 * 1)"), 1.0);
    REQUIRE_EQ(twostack((char*)"(1 / 1)"), 1.0);
    REQUIRE_EQ(twostack((char*)"(1 ^ 1)"), 1.0);
  }
  SUBCASE("Invalid Expressions") 
  {
    REQUIRE_THROWS(twostack((char*)"1 + 1"));
    REQUIRE_THROWS(twostack((char*)"(1 + 1"));
  }
}