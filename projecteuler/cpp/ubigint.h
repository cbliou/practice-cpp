#pragma once
#include <string>
#include <iostream>

using namespace std;

// making some unsigned bigint functionality b/c problem 13 is impossible
/*
notes: you can return a 
*/
class ubigint {

private:
	string number;

public:
	/* constructors */
	ubigint() {
		number = "";
	}

	ubigint(string s) {
		number = s;
	}

	ubigint(int s) {
		number = to_string(s);
	}
	
	// operators
	ubigint operator+(const ubigint& right) {
		ubigint tmp;
		tmp.number = add(this->number, right.number);
		return tmp;
	}

	// guess we gotta do * due to problem 16
	ubigint operator*(const ubigint& right) {
		ubigint tmp;
		tmp.number = multiply(this->number, right.number);
		return tmp;
	}

	friend bool operator==(const ubigint& left, const ubigint& right) {
		if (left.number.size() != right.number.size()) {
			return false;
		}

		for (unsigned int i = 0; i < left.number.size(); ++i) {
			if (left.number[i] != right.number[i]) {
				return false;
			}
		}

		return true;
	}

	friend bool operator==(const ubigint& left, string right) {
		if (left.number.size() != right.size()) {
			return false;
		}

		for (unsigned int i = 0; i < left.number.size(); ++i) {
			if (left.number[i] != right[i]) {
				return false;
			}
		}

		return true;
	}

	friend void operator<<(ostream& stream, const ubigint& i) {
		stream << i.number;
	}

	/* unsigned int comparisons, assumes no leading zeroes */
	friend bool operator < (const ubigint& left, const ubigint& right) {
		/* vacuous truth */
		if (left.number.size() == 0 && right.number.size() == 0) {
			return true;
		}
		else if (left.number.size() > right.number.size()) {
			return false;
		}
		else if (left.number.size() < right.number.size()) {
			return true;
		}
		for (size_t idx = 0; idx < left.number.size(); ++idx) {
			if (left.number[idx] < right.number[idx])
				return true;
			else if (left.number[idx] > right.number[idx])
				return false;
		}

		return false;

	}

	friend bool operator > (const ubigint& left, const ubigint& right) {
		/* vacuous truth */
		if (left.number.size() == 0 && right.number.size() == 0) {
			return true;
		}
		else if (left.number.size() > right.number.size()) {
			return true;
		}
		else if (left.number.size() < right.number.size()) {
			return false;
		}
		for (size_t idx = 0; idx < left.number.size(); ++idx) {
			if (left.number[idx] < right.number[idx])
				return false;
			else if (left.number[idx] > right.number[idx])
				return true;
		}

		return false;

	}

	ubigint factorial(void) {
		ubigint accumulator ("1");
		int num = stoi(this->number);
		while (num > 0) {
			accumulator = accumulator * ubigint(num);
			--num;
		}
		return accumulator;
	}

	unsigned int sumDigits(void) {
		unsigned int sum = 0;
		for (unsigned int i = 0; i < this->number.size(); ++i) {
			sum += this->number[i] - 48;
		}
		return sum;
	}

private:
	/*
	internal func to add
	add two numbers like we learned in grade school: r to l
	*/
	string add(const string left, const string right) {
		int leftlen = left.size() - 1;
		int rightlen = right.size() - 1;
		int carry = 0;
		string sum = "";

		// edge case
		if (left.size() == 1 && right.size() == 1) {
			return to_string(left[0] - 48 + right[0] - 48);
		}

		while (leftlen >= 0 && rightlen >= 0) {
			int s = left[leftlen] - 48 + right[rightlen] - 48 + carry;
			carry = s / 10;
			sum.insert(0, to_string(s % 10));
			--leftlen;
			--rightlen;
		}

		// carry is still in scope here
		while (leftlen >= 0) {
			int s = left[leftlen] - 48 + carry;
			carry = s / 10;
			sum.insert(0, to_string(s % 10));
			--leftlen;
		}
		while (rightlen >= 0) {
			int s = right[rightlen] - 48 + carry;
			carry = s / 10;
			sum.insert(0, to_string(s % 10));
			--rightlen;
		}

		// don't forget the last possible carry
		if (carry == 1) {
			sum.insert(0, to_string(1));
		}

		return removeLeadingZeroes(sum);

	}

	string removeLeadingZeroes(string i) {
		while (i[0] == '0' && i.size() > 1) {
			i.erase(i.begin());
		}
		return i;
	}

	// grade school type multiplication..
	string multiply(string left, string right) {
		string result = "0";

		for (int i = left.size() - 1; i >= 0; --i) {
			// string (size_t n, char c);
			string tmp((unsigned int) abs(i - (int)left.size() + 1), 48);
			int carry = 0;
			for (int j = right.size() - 1; j >= 0; --j) {
				int s = (left[i] - 48) * (right[j] - 48) + carry;
				carry = s / 10;
				// if at end, just insert the entire result
				if (j == 0) {
					tmp.insert(0, to_string(s));
				}
				else {
					tmp.insert(0, to_string(s % 10));
				}

			}
			result = add(result, tmp);
		}
		return removeLeadingZeroes(result);
	}


};