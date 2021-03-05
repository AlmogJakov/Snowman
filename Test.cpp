/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;


TEST_CASE("Good snowman code") {
    CHECK(snowman(11114411) == string("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(snowman(12222212) == string(" _===_\n\\(o.o)/\n ( : )\n (\" \")"));
    CHECK(snowman(32443333) == string("   _\n  /_\\\n (-.-)\n/(> <)\\\n (___)"));
    CHECK(snowman(44444432) == string(" ___\n(_*_)\n(- -)\n(> <)\n(\" \")"));
    CHECK(snowman(44242123) == string("  ___\n (_*_)\n\\(o -)\n (] [)>\n (___)"));

    CHECK(snowman(41341144) == string("  ___\n (_*_)\n (O,-)\n<(   )>\n (   )"));
    CHECK(snowman(11111111) == string(" _===_\n (.,.)\n<( : )>\n ( : )"));
    CHECK(snowman(22222222) == string("  ___\n .....\n\\(o.o)/\n (] [)\n (\" \")"));
    CHECK(snowman(33333333) == string("   _\n  /_\\\n (O_O)\n/(> <)\\\n (___)"));
    CHECK(snowman(44444444) == string(" ___\n(_*_)\n(- -)\n(   )\n(   )"));

    CHECK(snowman(12341214) == string(" _===_\n (O.-)/\n<( : )\n (   )"));
    CHECK(snowman(12344321) == string("_===_\n(O.-)\n(] [)\\\n( : )"));
    CHECK(snowman(12333321) == string(" _===_\n (O.O)\n/(] [)\\\n ( : )"));
    CHECK(snowman(23232223) == string("  ___\n .....\n\\(o_O)/\n (] [)\n (___)"));
    CHECK(snowman(11112311) == string(" _===_\n\\(.,.)\n ( : )\\\n ( : )"));

    CHECK(snowman(44114432) == string(" ___\n(_*_)\n(. .)\n(> <)\n(\" \")"));
    CHECK(snowman(24224411) == string(" ___\n.....\n(o o)\n( : )\n( : )"));
    CHECK(snowman(31333342) == string("   _\n  /_\\\n (O,O)\n/(   )\\\n (\" \")"));
    CHECK(snowman(43232122) == string("  ___\n (_*_)\n\\(o_O)\n (] [)>\n (\" \")"));
    CHECK(snowman(34334442) == string("  _\n /_\\\n(O O)\n(   )\n(\" \")"));
    /* Add more checks here */
}

TEST_CASE("Bad snowman code") {
    // random checks
    CHECK_THROWS(snowman(0));
    CHECK_THROWS(snowman(00000000));
    CHECK_THROWS(snowman(11100111));
    CHECK_THROWS(snowman(55555555));

    CHECK_THROWS(snowman(99999999));
    CHECK_THROWS(snowman(12345678));
    CHECK_THROWS(snowman(12341235));
    CHECK_THROWS(snowman(123412344));

    // number length checks
    CHECK_THROWS(snowman(1234));
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(123412341));
    CHECK_THROWS(snowman(111111111));

    // negative checks
    CHECK_THROWS(snowman(-1111111));
    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(-1234123));
    CHECK_THROWS(snowman(-0));
    
    // digit range checks
    CHECK_THROWS(snowman(01111111));
    CHECK_THROWS(snowman(10111111));
    CHECK_THROWS(snowman(11011111));
    CHECK_THROWS(snowman(11101111));

    CHECK_THROWS(snowman(11110111));
    CHECK_THROWS(snowman(11111011));
    CHECK_THROWS(snowman(11111101));
    CHECK_THROWS(snowman(11111110));
    
    CHECK_THROWS(snowman(51111111));
    CHECK_THROWS(snowman(15111111));
    CHECK_THROWS(snowman(11511111));
    CHECK_THROWS(snowman(11151111));

    CHECK_THROWS(snowman(11115111));
    CHECK_THROWS(snowman(11111511));
    CHECK_THROWS(snowman(11111151));
    CHECK_THROWS(snowman(11111115));

    /* Add more checks here */
}


// /* Add more test cases here */
