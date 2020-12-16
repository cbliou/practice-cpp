#pragma once
#include <vector>
#include <string>

using namespace std;

// making some unsigned bigint functionality b/c problem 13 is impossible
class ubigint {

private:
	string number;

public:
	// constructors
	ubigint() {
		number = "";
	}

	// for now, just stick w strings.
	ubigint(string s) {
		number = s;
	}
	
	// operators
	ubigint operator+(const ubigint& right) {
		ubigint tmp;
		tmp.number = add(this->number, right.number);
		return tmp;
	}

	friend bool operator==(const ubigint& left, const ubigint& right) {
		if (left.number.size() != right.number.size()) {
			return false;
		}

		for (int i = 0; i < left.number.size(); ++i) {
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

		for (int i = 0; i < left.number.size(); ++i) {
			if (left.number[i] != right[i]) {
				cout << left.number << "\n";
				cout << right << "\n";
				return false;
			}
		}

		return true;
	}

	friend void operator<<(ostream& stream, const ubigint& i) {
		stream << i.number;
	}

private:
	/*
	internal func to add
	add two numbers like we learned in grade school: r to l
	*/
	string add(string left, string right) {
		int leftlen = left.size() - 1;
		int rightlen = right.size() - 1;
		int carry = 0;
		string sum = "";

		// edge case
		if (left.size() == 1 && right.size() == 1) {
			return to_string(left[0] - 48 + right[0] - 48);
		}

		while (leftlen >= 0 && rightlen >= 0) {
			cout << sum << '\n';
			int s = left[leftlen] - 48 + right[rightlen] - 48 + carry;
			carry = s / 10;
			sum.insert(0, to_string(s % 10));
			--leftlen;
			--rightlen;
		}

		// carry is still in scope here
		while (leftlen >= 0) {
			cout << sum << '\n';
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
		cout << i << '\n';
		while (i[0] == '0') {
			i.erase(i.begin());
		}
		return i;
	}


};