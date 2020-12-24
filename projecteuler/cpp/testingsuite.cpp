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
	assert(ubigint("12123") + ubigint("0") == ubigint("12123"));
	assert(ubigint("1") * ubigint("1") == ubigint("1"));
	assert(ubigint("2") * ubigint("1") == ubigint("2"));
	assert(ubigint("1") * ubigint("2") == ubigint("2"));
	assert(ubigint("0") * ubigint("1") == ubigint("0"));
	assert(ubigint("0") * ubigint("12") == ubigint("0"));
	assert(ubigint("0") * ubigint("1473829347382934738291343782934756382947382934758329347583920485732910") == ubigint("0"));
	assert(ubigint("0") * ubigint("23") == ubigint("0"));
	assert(ubigint("1") * ubigint("11232132112070402010507020101") == ubigint("11232132112070402010507020101"));
	assert(ubigint("3058149") * ubigint("95017") == ubigint("290576143533"));
	assert(ubigint("1") * ubigint("1") * ubigint("1") * ubigint("1") == ubigint("1"));
	assert(ubigint("2") * ubigint("2") == ubigint("4"));
	assert(ubigint("3") * ubigint("4") == ubigint("12"));
	assert(ubigint("9") * ubigint("5") == ubigint("45"));
	assert(ubigint("99999999999999999999999999999999999999999999999999999999999999999999999999999999999") * ubigint("1") * ubigint("1") * ubigint("1") == ubigint("99999999999999999999999999999999999999999999999999999999999999999999999999999999999"));
	assert(ubigint("783265096274793940943") * ubigint("3725096592838348945892377642") == ubigint("2917738141422436272725283756412559956189601596406"));


	/* < test */
	assert(ubigint("12") < ubigint("13") == true);
	assert(ubigint("13") < ubigint("13") == false);
	assert(ubigint("1") < ubigint("13") == true);
	assert(ubigint("133") < ubigint("13") == true);
	assert(ubigint("23342") < ubigint("13") == false);
	assert(ubigint("232332") < ubigint("0") == false);
	assert(ubigint("168754382974i582389472983892389") < ubigint("168754382974i582389472983892390") == true);
	assert(ubigint("168754382974i582389472983892389") < ubigint("168754382974i582389472983892389") == false);

	/* > test */
	assert(ubigint("12") < ubigint("13") == false);
	assert(ubigint("13") < ubigint("13") == true);
	assert(ubigint("1") < ubigint("13") == false);
	assert(ubigint("133") < ubigint("13") == false);
	assert(ubigint("23342") < ubigint("13") == true);
	assert(ubigint("232332") < ubigint("0") == true);
	assert(ubigint("168754382974i582389472983892389") < ubigint("168754382974i582389472983892390") == false);
	assert(ubigint("168754382974i582389472983892389") < ubigint("168754382974i582389472983892389") == true);

	cout << "Passed all bigint tests.\n";
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

	cout << "Passed all util tests.\n";
}
