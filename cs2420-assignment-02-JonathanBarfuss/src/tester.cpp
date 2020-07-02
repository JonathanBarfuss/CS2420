#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <sstream>
#include "date.h"
using namespace std;

TEST_CASE("one argument constructor") {
    CHECK(Date(2018).str() == "Jan 1, 2018");
}

TEST_CASE("two arguments constructor") {
    CHECK(Date(2018, 7).str() == "Jul 1, 2018");
}

TEST_CASE("+ operator") {
    Date dd(2018, 9, 10);
    Date d = dd;

    d = dd; CHECK((d + 23).str() == "Oct 3, 2018");
    d = dd; CHECK((d + 38).str() == "Oct 18, 2018");
    d = dd; CHECK((d + 56).str() == "Nov 5, 2018");
    d = dd; CHECK((d + 91).str() == "Dec 10, 2018");
    d = dd; CHECK((d + 134).str() == "Jan 22, 2019");

    Date ddd(2020, 1, 16);
    CHECK((ddd + 16).str() == "Feb 1, 2020");
}

TEST_CASE("Adding months") {
    Date dd(2018, 9, 10);
    Date d = dd;

    d = dd; CHECK(d.addMonths(7).str() == "Apr 10, 2019");
    d = dd; CHECK(d.addMonths(17).str() == "Feb 10, 2020");
}

TEST_CASE("<< operator") {
    Date dd(2018, 9, 10);
    stringstream sout;
    sout << dd;

    CHECK(sout.str() == "Sep 10, 2018");
}

TEST_CASE("str() function") {
    Date dd(2018, 9, 10);
    CHECK(dd.str() == "Sep 10, 2018");
}

TEST_CASE("format() function") {
    Date d(2020, 8, 19);
    CHECK(Date::format("mm/dd/yyyy", d) == "08/19/2020");
    CHECK(Date::format("dd/mm/yyyy", d) == "19/08/2020");
    CHECK(Date::format("yyyy/mm/dd", d) == "2020/08/19");
}