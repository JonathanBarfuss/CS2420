#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include "dictionary.h"

TEST_CASE("Testing Dictionary"){
	Dictionary<int, char> d;
  CHECK(d.empty());
	CHECK(d.size() == 0);
	d.put(0, 'A');	

	std::stringstream sout;
	d.put(1, 'B');
	d.del(1);
	d.del(0);
	CHECK(d.get(0) == nullptr);
	CHECK(d.empty());
	d.del(0);
	d.del(1);
	CHECK(d.empty());
	d.put(2, 'C');
	d.put(3, 'D');
	d.put(4, 'E');
	d.put(5, 'F');
	d.put(6, 'G');
	d.put(7, 'H');
	d.put(8, 'I');
	d.put(9, 'J');
	d.del(5);
	std::vector<char> values = d.values();
	CHECK(std::count(values.begin(), values.end(), 'F') == 0);
	CHECK(d.size() == 7);
  CHECK(!d.empty());

	CHECK(d.get(1) == nullptr);
	d.put(0, '_');

	CHECK(d.size() == 8);
	CHECK(*(d.get(0)) == '_'); 
	d.put(0, '*');
	CHECK(d.size() == 8);
	CHECK(*(d.get(0)) == '*'); 
	d.del(1);
	CHECK(d.size() == 8); 
	CHECK(d.keys().size() == d.size());
	CHECK(d.values().size() == d.size());

	sout << d;
	CHECK(sout.str().size() > 1);
	
	d.clear();
	CHECK(d.size() == 0);
	CHECK(d.keys().size() == d.size());
	CHECK(d.values().size() == d.size());
}
