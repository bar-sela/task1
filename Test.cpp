#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '+')) == nospaces("@@@@@@@@@\n"
													 "@+++++++@\n"
													 "@+@@@@@+@\n"
													 "@+@+++@+@\n"
													 "@+@@@@@+@\n"
													 "@+++++++@\n"
													 "@@@@@@@@@"));


    CHECK(nospaces(mat(1, 1, '%', '-')) == nospaces("%"));
    CHECK(nospaces(mat(1, 1, '!', '-')) == nospaces("!"));
	CHECK(nospaces(mat(1, 5, '@', '+')) == nospaces("@\n"
	                                                 "@\n"
													 "@\n"
													 "@\n"
													 "@\n"));
	
    CHECK(nospaces(mat(3, 1, '$', '-')) == nospaces("$$$\n"));


    CHECK(nospaces(mat(5, 5, '@', '@')) == nospaces("@@@@@\n"
                                                    "@@@@@\n"
                                                    "@@@@@\n"
                                                    "@@@@@\n"
													"@@@@@\n"));

    CHECK(nospaces(mat(3, 3, '@', '*')) == nospaces("@@@\n"
                                                    "@*@\n"
                                                    "@@@"));

    CHECK(nospaces(mat(3, 3, '@', '@')).length() == 9);
    CHECK(nospaces(mat(5, 5, '*', '#')).length() == 25);
    CHECK(nospaces(mat(9, 7, '@', '+')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
}


//"Bad input"

    CHECK_THROWS(mat(0, 10, '$', '%'));
    CHECK_THROWS(mat(2, 1, '$', '%'));
    CHECK_THROWS(mat(8888, 2, '$', '%'));                                                        
    CHECK_THROWS(mat(10, 10, 1, 4));
    CHECK_THROWS(mat(3213, 1, '$', 2));
    CHECK_THROWS(mat(90, 2, 9, '%'));
    CHECK_THROWS(mat(1, 2, ' ', ' '));                                                          
    CHECK_THROWS(mat( '$', 'k', '$', '%'));
    CHECK_THROWS(mat( '$', 1, '$', '%'));
    CHECK_THROWS(mat( 1, '%', '$', '%'));                                                      
    CHECK_THROWS(mat(0, 213, '$', '%'));
    CHECK_THROWS(mat(-1, 89, '$', '%'));
    CHECK_THROWS(mat(0, -19, '$', '%'));
    CHECK_THROWS(mat(-1, -4, '$', '%'));                                                      
}

