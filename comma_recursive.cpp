#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string comma_str(int num);

int main() {
	int num;

	cout << "Type an integer (0 to quit): ";
	while (cin >> num && num > 0) {
		cout << comma_str(num) << endl;
		cout << "Type an integer (0 to quit): ";
	}
}

string comma_str(int num) {
	ostringstream oss;

	int quotient = num / 1000;
	int remainder = num % 1000;

	if (quotient == 0) {
		oss << remainder;
		return oss.str();
		// return to_string(remainder);
	} else {
		oss << setfill('0') << setw(3) << remainder;
		return comma_str(quotient) + "," + oss.str();
		// return comma_str(quotient) + "," + to_string(remainder);
	}
}
