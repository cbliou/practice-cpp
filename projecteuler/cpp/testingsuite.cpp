#pragma once
#include "testingsuite.h"

void testubigint() {
	ubigint i1(string("123"));
	ubigint i2(string("12"));
	ubigint i3 = i1 + i2;
	assert(i3 == "135");
	assert(ubigint("12345678976543212345") + ubigint("000000000000000000000000000000000000000000000000000000000000000000") == ubigint("12345678976543212345"));
	assert(ubigint("001010") + ubigint("100100") == ubigint("101110"));
	assert(ubigint("999999999999999999999") + ubigint("99999999999999999999999999999999999999999") == ubigint("100000000000000000000999999999999999999998"));
	assert(ubigint("38501266947982387462495") + ubigint("385026256697873265267") == ubigint("38886293204680260727762"));
	assert(ubigint("0") + ubigint("0") == ubigint("0"));
	assert(ubigint("1") + ubigint("0") == ubigint("1"));
	assert(ubigint("9") + ubigint("9") == ubigint("18"));
	assert(ubigint("11111") + ubigint("12321") == ubigint("23432"));
	assert(ubigint("37107287533902102798797998220837590246510135740250") + ubigint("46376937677490009712648124896970078050417018260538") == ubigint("83484225211392112511446123117807668296927154000788"));
}

void testUtil() {
	assert(determinePalindrome(121) == true);
	assert(determinePalindrome(11) == true);
	assert(determinePalindrome(1) == true);
	assert(determinePalindrome(12321) == true);
	assert(determinePalindrome(12831) == false);
	assert(determinePalindrome(1122) == false);
	assert(determinePalindrome(2345432) == true);
	assert(determinePalindrome(995599) == true);
	assert(determinePalindrome(88988) == true);
	assert(determinePalindrome(99398) == false);

	assert(testPrime(24) == false);
	assert(testPrime(14) == false);
	assert(testPrime(145) == false);
	assert(testPrime(149) == true);
	assert(testPrime(13) == true);
	assert(testPrime(3) == true);
	assert(testPrime(5) == true);
	assert(testPrime(7) == true);
	assert(testPrime(11) == true);
	assert(testPrime(17) == true);

	assert(triangleNumber(1) == 1);
	assert(triangleNumber(2) == 3);
	assert(triangleNumber(3) == 6);
	assert(triangleNumber(4) == 10);
	assert(triangleNumber(5) == 15);
	assert(triangleNumber(0) == 0);
	assert(triangleNumber(-1) == 0);

	assert(getNumDivisors(1) == 1);
	assert(getNumDivisors(2) == 2);
	assert(getNumDivisors(3) == 2);
	assert(getNumDivisors(4) == 3);
	assert(getNumDivisors(5) == 2);
	assert(getNumDivisors(6) == 4);
	assert(getNumDivisors(7) == 2);
	assert(getNumDivisors(8) == 4);
	assert(getNumDivisors(9) == 3);
	assert(getNumDivisors(10) == 4);
	assert(getNumDivisors(11) == 2);
	assert(getNumDivisors(12) == 6);
	assert(getNumDivisors(13) == 2);
	assert(getNumDivisors(14) == 4);
	assert(getNumDivisors(15) == 4);
	assert(getNumDivisors(21) == 4);
	assert(getNumDivisors(28) == 6);
	assert(getNumDivisors(60) == 12);
}