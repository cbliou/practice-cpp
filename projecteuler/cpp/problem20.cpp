#include "stdafx.h"

int problem20(void) {

	ubigint x("100");
	ubigint y = x.factorial();
	cout << y;

	return y.sumDigits();

}