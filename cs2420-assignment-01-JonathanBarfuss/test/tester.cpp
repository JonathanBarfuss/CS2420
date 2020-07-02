#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "range.h"
using namespace std;

TEST_CASE("Integer ascending range; defaut step")
{
    Range<int> r(3, 11);
    vector<int> values = {3, 4, 5, 6, 7, 8, 9, 10, 11};

    CHECK(r.sum() == 63);
    CHECK(r.length() == 9);
    CHECK(r.average() == 63 / 9);
    CHECK(r.max() == 11);
    CHECK(r.min() == 3);
    CHECK(values == r.values());
    CHECK(r.contains(4));
    CHECK(!r.contains(16));
}

TEST_CASE("Integer ascending range; step = 2")
{
    Range<int> r(3, 12, 2);
    vector<int> values = {3, 5, 7, 9, 11};

    CHECK(r.sum() == 35);
    CHECK(r.length() == 5);
    CHECK(r.average() == 35 / 5);
    CHECK(r.max() == 11);
    CHECK(r.min() == 3);
    CHECK(values == r.values());
    CHECK(r.contains(5));
    CHECK(!r.contains(6));
}

TEST_CASE("Double ascending range; step = 2.5")
{
    Range<double> r(7.5, 20.3, 2.5);
    vector<double> values = {7.5, 10.0, 12.5, 15.0, 17.5, 20.0};

    CHECK(r.sum() == 82.5);
    CHECK(r.length() == 6);
    CHECK(r.average() == 82.5 / 6);
    CHECK(r.max() == 20.0);
    CHECK(r.min() == 7.5);
    CHECK(values == r.values());
    CHECK(r.contains(15));
    CHECK(!r.contains(16));
}

TEST_CASE("Integer descending range; step = -2")
{
    Range<int> r(12, 3, -2);
    vector<int> values = {12, 10, 8, 6, 4};

    CHECK(r.sum() == 40);
    CHECK(r.length() == 5);
    CHECK(r.average() == 40 / 5);
    CHECK(r.max() == 12);
    CHECK(r.min() == 4);
    CHECK(values == r.values());
    CHECK(r.contains(6));
    CHECK(!r.contains(5));
}

TEST_CASE("Double descending range; step = -2.5")
{
    Range<double> r(20.0, 4.0, -2.5);
    vector<double> values = {20.0, 17.5, 15.0, 12.5, 10.0, 7.5, 5.0};

    CHECK(r.sum() == 87.5);
    CHECK(r.length() == 7);
    CHECK(r.average() == 87.5 / 7);
    CHECK(r.max() == 20.0);
    CHECK(r.min() == 5.0);
    CHECK(values == r.values());
    CHECK(r.contains(15));
    CHECK(!r.contains(16));
}