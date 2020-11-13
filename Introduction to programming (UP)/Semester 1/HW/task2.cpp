#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::min;
using std::abs;

int main()
{
	const int MAX_HOUR_24 = 23;
	const int MIN_HOUR_24 = 0;
	const int MAX_HOUR_12 = 11;
	const int MIN_HOUR_12 = 0;
	const int MAX_MINUTES = 59;
	const int MIN_MINUTES = 0;

	const int parsingMask = 63; // 0..0..111111
	const int secondDigitHourParse = (15 << 6); // 0000 00 1111 000000
	const int firstDigitHourParse = (3 << 10); // 0000 11 0000 000000
	const int timeFormatDigitParse = 1 << 12; // 0001 00 0000 000000

	int firstTime, secondTime, firstTimeMinutes = 0, firstTimeHours = 0,
		secondTimeMinutes = 0, secondTimeHours = 0;

	cin >> firstTime >> secondTime;

	firstTimeHours = (10 * ((firstDigitHourParse & firstTime) >> 10)) +
		((secondDigitHourParse & firstTime) >> 6);
	firstTimeMinutes = firstTime & (parsingMask);

	secondTimeHours = (10 * ((firstDigitHourParse & secondTime) >> 10)) +
		((secondDigitHourParse & secondTime) >> 6);
	secondTimeMinutes = secondTime & (parsingMask);

	if ((firstTime & timeFormatDigitParse) >> 12) {
		if (firstTimeHours < MIN_HOUR_24 || firstTimeHours > MAX_HOUR_24) {
			cout << "Incorrect time format." << endl;
			return -1;
		}
	}
	else {
		if (firstTimeHours < MIN_HOUR_12 || firstTimeHours > MAX_HOUR_12) {
			cout << "Incorrect time format." << endl;
			return -1;
		}
	}

	if ((secondTime & timeFormatDigitParse) >> 12) {
		if (secondTimeHours < MIN_HOUR_24 || secondTimeHours > MAX_HOUR_24) {
			cout << "Incorrect time format." << endl;
			return -1;
		}
	}
	else {
		if (secondTimeHours < MIN_HOUR_12 || secondTimeHours > MAX_HOUR_12) {
			cout << "Incorrect time format." << endl;
			return -1;
		}
	}

	if (firstTimeMinutes > MAX_MINUTES || firstTimeMinutes < MIN_MINUTES) {
		cout << "Incorrect time format." << endl;
		return -1;
	}

	cout << firstTimeHours << ":" << firstTimeMinutes << "\n" << secondTimeHours << ":" << secondTimeMinutes << "\n";

	if (abs(firstTimeMinutes - secondTimeMinutes >= 0 && abs(firstTimeMinutes - secondTimeMinutes <= 9))) {
		cout << "diff " << abs(firstTimeHours - secondTimeHours) << ":" << "0" << abs(firstTimeMinutes - secondTimeMinutes) << endl;
	}
	else {
		cout << "diff " << abs(firstTimeHours - secondTimeHours) << ":" << abs(firstTimeMinutes - secondTimeMinutes) << endl;
	}

	return 0;
}

