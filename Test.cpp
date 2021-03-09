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
#include <array>
#include <stdexcept>
#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <algorithm>
#include <iostream>
using namespace std;

constexpr int ten = 10;
constexpr int nine = 9;
constexpr int eight = 8;
constexpr int seven = 7;
constexpr int five = 5;
constexpr int one = 1;
constexpr int zero = 0;
constexpr int n = 65536;
constexpr int max_len = 34;
constexpr int min_len = 23;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

//////////////////////////////////////////////////////////////////////////////////
////////////////////////////// GOOD SNOWMAN CODES ////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

TEST_CASE("Good snowman code") {
    // 5 Random snowman inputs
    CHECK(snowman(11114411) == string("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(snowman(12222212) == string(" _===_\n\\(o.o)/\n ( : )\n (\" \")"));
    CHECK(snowman(32443333) == string("   _\n  /_\\\n (-.-)\n/(> <)\\\n (___)"));
    CHECK(snowman(44444432) == string(" ___\n(_*_)\n(- -)\n(> <)\n(\" \")"));
    CHECK(snowman(44242123) == string("  ___\n (_*_)\n\\(o -)\n (] [)>\n (___)"));
    // 5 Random snowman inputs
    CHECK(snowman(41341144) == string("  ___\n (_*_)\n (O,-)\n<(   )>\n (   )"));
    CHECK(snowman(11111111) == string(" _===_\n (.,.)\n<( : )>\n ( : )"));
    CHECK(snowman(22222222) == string("  ___\n .....\n\\(o.o)/\n (] [)\n (\" \")"));
    CHECK(snowman(33333333) == string("   _\n  /_\\\n (O_O)\n/(> <)\\\n (___)"));
    CHECK(snowman(44444444) == string(" ___\n(_*_)\n(- -)\n(   )\n(   )"));
    // 5 Random snowman inputs
    CHECK(snowman(12341214) == string(" _===_\n (O.-)/\n<( : )\n (   )"));
    CHECK(snowman(12344321) == string("_===_\n(O.-)\n(] [)\\\n( : )"));
    CHECK(snowman(12333321) == string(" _===_\n (O.O)\n/(] [)\\\n ( : )"));
    CHECK(snowman(23232223) == string("  ___\n .....\n\\(o_O)/\n (] [)\n (___)"));
    CHECK(snowman(11112311) == string(" _===_\n\\(.,.)\n ( : )\\\n ( : )"));
    // 5 Random snowman inputs
    CHECK(snowman(44114432) == string(" ___\n(_*_)\n(. .)\n(> <)\n(\" \")"));
    CHECK(snowman(24224411) == string(" ___\n.....\n(o o)\n( : )\n( : )"));
    CHECK(snowman(31333342) == string("   _\n  /_\\\n (O,O)\n/(   )\\\n (\" \")"));
    CHECK(snowman(43232122) == string("  ___\n (_*_)\n\\(o_O)\n (] [)>\n (\" \")"));
    CHECK(snowman(34334442) == string("  _\n /_\\\n(O O)\n(   )\n(\" \")"));
}

// Since number 2 represents Upwards Arm and number 3 represents Downwards Arm,
// and since we test snowman codes with opposite number such as 1 opposite to 4
// and 2 opposite to 3, so we can test opposite combines of Upwards Arm & Downwards Arm.
// Same for 1 & 4 (combines of snowman codes with one hand).
//              ___        _        ___
//    _===_    .....      /_\      (_*_)
//    (- -)    (O_O)    \(o.o)/    (.,.)
//    (   )   /(> <)\    (] [)    <( : )>
// 1. (   ) 2. (___)  3. (" ")  4. ( : )
//     ___       _        ___
//    (_*_)     /_\      .....     _===_
//    (-,-)    (O.O)    \(o_o)/    (. .)
//    (   )   /(> <)\    (] [)    <( : )>
// 5. (   ) 6. (___)  7. (" ")  8. ( : )
//     ___       _        ___
//    (_*_)     /_\      .....     _===_
//    (. -)    (o_O)    \(O.o)/    (-,.)
//    (   )   /(> <)\    (] [)    <( : )>
// 9. (   ) 10.(___)  11.(" ") 12. ( : )
//     ___       _        ___
//    (_*_)     /_\      .....     _===_
//    (- .)    (O_o)    \(o.O)/    (.,-)
//    (   )   /(> <)\    (] [)    <( : )>
// 13.(   ) 14.(___)  15.(" ") 16. ( : )
//     ___       _        ___
//    (_*_)     /_\      .....     _===_
//    (- -)   \(O_O)     (o.o)/    (.,.)
//   <(   )    (> <)\   /(] [)     ( : )>
// 17.(   ) 18.(___)  19.(" ")  20.( : )
//     ___       _        ___
//    (_*_)     /_\      .....     _===_
//    (- -)    (O_O)/   \(o.o)     (.,.)
//    (   )>  /(> <)     (] [)\   <( : )
// 21.(   ) 22.(___)  23.(" ")  24.( : )
//     ___       _        ___
//    (_*_)     /_\      .....     _===_
//    (- -)    (O_O)    \(o.o)/    (.,.)
//    ( : )   /(] [)\    (> <)    <(   )>
// 25.(   ) 26.(___)  27.( : )  28.( : )
//     ___       _        ___
//    (_*_)     /_\      .....     _===_
//    (- -)    (O_O)    \(o.o)/    (.,.)
//    (   )   /(> <)\    (] [)    <( : )>
// 29.( : ) 30.(" ")  31.(___)  32.(   )

TEST_CASE("Check each item") {
    // Hat
    CHECK(snowman(14444444) == string("_===_\n(- -)\n(   )\n(   )"));
    CHECK(snowman(23333333) == string("  ___\n .....\n (O_O)\n/(> <)\\\n (___)"));
    CHECK(snowman(32222222) == string("   _\n  /_\\\n\\(o.o)/\n (] [)\n (\" \")"));
    CHECK(snowman(41111111) == string("  ___\n (_*_)\n (.,.)\n<( : )>\n ( : )"));
    // Nose/Mouth
    CHECK(snowman(41444444) == string(" ___\n(_*_)\n(-,-)\n(   )\n(   )"));
    CHECK(snowman(32333333) == string("   _\n  /_\\\n (O.O)\n/(> <)\\\n (___)"));
    CHECK(snowman(23222222) == string("  ___\n .....\n\\(o_o)/\n (] [)\n (\" \")"));
    CHECK(snowman(14111111) == string(" _===_\n (. .)\n<( : )>\n ( : )"));
    // Left Eye
    CHECK(snowman(44144444) == string(" ___\n(_*_)\n(. -)\n(   )\n(   )"));
    CHECK(snowman(33233333) == string("   _\n  /_\\\n (o_O)\n/(> <)\\\n (___)"));
    CHECK(snowman(22322222) == string("  ___\n .....\n\\(O.o)/\n (] [)\n (\" \")"));
    CHECK(snowman(11411111) == string(" _===_\n (-,.)\n<( : )>\n ( : )"));
    // Right Eye
    CHECK(snowman(44414444) == string(" ___\n(_*_)\n(- .)\n(   )\n(   )"));
    CHECK(snowman(33323333) == string("   _\n  /_\\\n (O_o)\n/(> <)\\\n (___)"));
    CHECK(snowman(22232222) == string("  ___\n .....\n\\(o.O)/\n (] [)\n (\" \")"));
    CHECK(snowman(11141111) == string(" _===_\n (.,-)\n<( : )>\n ( : )"));
    // Left Arm
    CHECK(snowman(44441444) == string("  ___\n (_*_)\n (- -)\n<(   )\n (   )"));
    CHECK(snowman(33332333) == string("   _\n  /_\\\n\\(O_O)\n (> <)\\\n (___)"));
    CHECK(snowman(22223222) == string("  ___\n .....\n (o.o)/\n/(] [)\n (\" \")"));
    CHECK(snowman(11114111) == string("_===_\n(.,.)\n( : )>\n( : )"));
    // Right Arm
    CHECK(snowman(44444144) == string(" ___\n(_*_)\n(- -)\n(   )>\n(   )"));
    CHECK(snowman(33333233) == string("   _\n  /_\\\n (O_O)/\n/(> <)\n (___)"));
    CHECK(snowman(22222322) == string("  ___\n .....\n\\(o.o)\n (] [)\\\n (\" \")"));
    CHECK(snowman(11111411) == string(" _===_\n (.,.)\n<( : )\n ( : )"));
    // Torso
    CHECK(snowman(44444414) == string(" ___\n(_*_)\n(- -)\n( : )\n(   )"));
    CHECK(snowman(33333323) == string("   _\n  /_\\\n (O_O)\n/(] [)\\\n (___)"));
    CHECK(snowman(22222232) == string("  ___\n .....\n\\(o.o)/\n (> <)\n (\" \")"));
    CHECK(snowman(11111141) == string(" _===_\n (.,.)\n<(   )>\n ( : )"));
    // Base
    CHECK(snowman(44444441) == string(" ___\n(_*_)\n(- -)\n(   )\n( : )"));
    CHECK(snowman(33333332) == string("   _\n  /_\\\n (O_O)\n/(> <)\\\n (\" \")"));
    CHECK(snowman(22222223) == string("  ___\n .....\n\\(o.o)/\n (] [)\n (___)"));
    CHECK(snowman(11111114) == string(" _===_\n (.,.)\n<( : )>\n (   )"));
}

//////////////////////////////////////////////////////////////////////////////////
////////////////////////////// VALID OUTPUT LENGTH ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

// Max Hat Size (Mexican Hat) = 4 + 1(left arm space) +1(newline)
//                            + 5 + 1(left arm space) +1(newline) = 13
// Max Head Size = 5 + 1(left arm space) +1(newline) = 7
// Max Torso Size = 5 + 1(left arm) +1(right arm) +1(newline) = 8
// Max Base Size = 5 + 1(left arm space) = 6
// MAX-SUM = 13+8+7+6 = 34
//
// Min Hat Size (Straw Hat) = 5 +1(newline) = 6
// Min Head Size = 5 +1(newline) = 6
// Min Torso Size = 5 +1(newline) = 6
// Min Base Size = 5 = 5
// MIN-SUM = 6+6+6+5 = 23
//
// Therefor, 23 <= snowman-output-length <= 34.
void check_length() {
    int decimal_location = 1;
    int snowman_code = 0;
    bool seek = true;
    array<int, eight> arr = {1,1,1,1,1,1,1,0};
    for (int i = zero; i < n; i++) {
        int j = seven;
        while (seek) {
            if (arr.at(j)==4) {
            arr.at(j) = 1;
            } else {
            arr.at(j) = arr.at(j) + 1;
            seek = false;
            }
            j--;
        }
        seek = true;
        snowman_code = 0;
        decimal_location = 1;
        for (int x = seven; x >= zero; x--) {
            snowman_code = snowman_code + arr.at(x)*decimal_location;
            decimal_location = decimal_location*ten;
        }
        if (snowman(snowman_code).length() > max_len || snowman(snowman_code).length() < min_len) {
            string invalid_input = to_string(snowman_code);
            throw out_of_range{"output out of valid range (for input:"+invalid_input+")"};
        }
    }
}

TEST_CASE("Check snowman output length") {
    CHECK_NOTHROW(check_length());
}

//////////////////////////////////////////////////////////////////////////////////
////////////////////////////// BAD SNOWMAN CODES /////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

// Error for invalid digit range is more harder to handle then invalid input length,
// Therfor, performing a test for all cases (for invalid digit range) is more essential
// (implementation of the function in the next TEST_CASE).
TEST_CASE("Bad snowman code") {
    // Random checks
    CHECK_THROWS(snowman(0));
    CHECK_THROWS(snowman(00000000));
    CHECK_THROWS(snowman(11100111));
    CHECK_THROWS(snowman(55555555));
    // Random checks
    CHECK_THROWS(snowman(99999999));
    CHECK_THROWS(snowman(12345678));
    CHECK_THROWS(snowman(12341235));
    CHECK_THROWS(snowman(123412344));
    // Number length checks
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(11));
    CHECK_THROWS(snowman(111));
    CHECK_THROWS(snowman(1111));
    // Number length checks
    CHECK_THROWS(snowman(11111));
    CHECK_THROWS(snowman(111111));
    CHECK_THROWS(snowman(1111111));
    CHECK_THROWS(snowman(111111111));
    // Number length checks
    CHECK_THROWS(snowman(1111111111));
    CHECK_THROWS(snowman(1234));
    CHECK_THROWS(snowman(1234123));
    CHECK_THROWS(snowman(123412341));
    // Negative checks
    CHECK_THROWS(snowman(-11112222));
    CHECK_THROWS(snowman(-22221111));
    CHECK_THROWS(snowman(-22223333));
    CHECK_THROWS(snowman(-33332222));
    // Negative checks
    CHECK_THROWS(snowman(-33334444));
    CHECK_THROWS(snowman(-44443333));
    CHECK_THROWS(snowman(-12121212));
    CHECK_THROWS(snowman(-34343434));
    // Negative checks
    CHECK_THROWS(snowman(-0));
    CHECK_THROWS(snowman(-1234123));
    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(-1111111111));
    // Negative checks
    CHECK_THROWS(snowman(-1));
    CHECK_THROWS(snowman(-11));
    CHECK_THROWS(snowman(-111));
    CHECK_THROWS(snowman(-1111));
    // Negative checks
    CHECK_THROWS(snowman(-11111));
    CHECK_THROWS(snowman(-111111));
    CHECK_THROWS(snowman(-1111111));
    CHECK_THROWS(snowman(-111111111));
}

//////////////////////////////////////////////////////////////////////////////////
////////////////////////////// INVALID DIGIT INPUT ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

void digit_range_check(int digit) {
    int decimal_location = 1;
    int snowman_code = 0;
    array<int, eight> arr = {1,1,1,1,1,1,1,1};
    for (int i = zero; i <= seven; i++) {
        arr.at(i) = digit;
        snowman_code = 0;
        decimal_location = 1;
        for (int x = seven; x >= zero; x--) {
            snowman_code = snowman_code + arr.at(x)*decimal_location;
            decimal_location = decimal_location*ten;
        }
        arr.at(i) = one;
        INFO("Error for input: "+to_string(snowman_code));
        CHECK_THROWS(snowman(snowman_code));
    }
}

TEST_CASE("Check snowman output length") {
    digit_range_check(zero);
    for (int i = five; i <= nine; i++) {
        digit_range_check(i);
    }
}