#include <iostream>

using std::cout;
using std::cin;
using std::endl;

unsigned int dateToDays(unsigned int dateSec, unsigned int dateMinute, unsigned int dateHour,
	unsigned int dateDay, unsigned int dateMonth, unsigned int dateYear);
unsigned int dateToSeconds(unsigned int dateSec, unsigned int dateMinute, unsigned int dateHour);
bool isDataValid(unsigned int dateSec, unsigned int dateMinute, unsigned int dateHour,
	unsigned int dateDay, unsigned int dateMonth, unsigned int dateYear);
bool isLeapYear(int year);
unsigned int absolute(int a);

int main()
{
	int firstDay, firstMonth, firstYear, firstHour, firstMinute, firstSecond,
		secondDay, secondMonth, secondYear, secondHour, secondMinute, secondSecond,
		newHour, newMinute, newSecond;
	int firstDateDays, secondDateDays, diffDays;
	int firstDateSeconds, secondDateSeconds;

	//parsing format dd.mm.yyyy HH:MM:SS
	(void)scanf_s("%d.%d.%d %d:%d:%d", &firstDay, &firstMonth, &firstYear, &firstHour, &firstMinute, &firstSecond);
	(void)scanf_s("%d.%d.%d %d:%d:%d", &secondDay, &secondMonth, &secondYear, &secondHour, &secondMinute, &secondSecond);

	if (!isDataValid(firstSecond, firstMinute, firstHour, firstDay, firstMonth, firstYear) ||
		!isDataValid(secondSecond, secondMinute, secondHour, secondDay, secondMonth, secondYear)) {
		cout << "Invalid date/time" << endl;
		return -1;
	}

	firstDateDays = dateToDays(firstSecond, firstMinute, firstHour, firstDay, firstMonth, firstYear);
	secondDateDays = dateToDays(secondSecond, secondMinute, secondHour, secondDay, secondMonth, secondYear);

	firstDateSeconds = dateToSeconds(firstSecond, firstMinute, firstHour);
	secondDateSeconds = dateToSeconds(secondSecond, secondMinute, secondHour);

	diffDays = absolute(firstDateDays - secondDateDays);

	newSecond = (firstDateSeconds - secondDateSeconds);
	if ((firstDateDays - secondDateDays) > 0) {
		if (newSecond < 0) {
			newSecond += 24 * 3600;
			diffDays -= 1;
		}
	}

	newHour = newSecond / (60 * 60);
	if (newHour) {
		newSecond = newSecond - (newHour * 60 * 60);
	}

	newMinute = newSecond / 60;
	if (newMinute) {
		newSecond -= newMinute * 60;
	}

	diffDays = absolute(diffDays);
	newHour = absolute(newHour);
	newMinute = absolute(newMinute);
	newSecond = absolute(newSecond);

	//if difference between HH:MM:SS is < 0 than we need to remove 1 day from diff days
	if (firstHour - secondHour <= 0 && firstMinute - secondMinute <= 0 && firstSecond - secondSecond < 0) {  
		diffDays -= 1;
	}

	((diffDays != 0 && diffDays >= 0) ? (cout << diffDays << "-") : (cout << ""));

	((newHour <= 9) && (newHour >= 0)) ? (cout << "0" << newHour) : cout << newHour;
	cout << ":";
	((newMinute <= 9) && (newMinute >= 0)) ? (cout << "0" << newMinute) : cout << newMinute;
	cout << ":";
	((newSecond <= 9) && (newSecond >= 0)) ? (cout << "0" << newSecond) : cout << newSecond;
	cout << endl;

	return 0;
}

unsigned int dateToDays(unsigned int dateSec, unsigned int dateMinute, unsigned int dateHour,
	unsigned int dateDay, unsigned int dateMonth, unsigned int dateYear) {

	unsigned int result = 0;
	result = (dateYear * 365) + (((dateYear) / 4) - ((dateYear - 1) / 100) + ((dateYear - 1) / 400)) + dateDay;

	switch (dateMonth - 1) {
	case 1:
		result += 31;
		break;
	case 2:
		result += 60; // month 1 + month 2
		break;
	case 3:
		result += 91; // month 1 + month 2 + month 3
		break;
	case 4:
		result += 121;
		break;
	case 5:
		result += 152;
		break;
	case 6:
		result += 182;
		break;
	case 7:
		result += 213;
		break;
	case 8:
		result += 244;
		break;
	case 9:
		result += 274;
		break;
	case 10:
		result += 305;
		break;
	case 11:
		result += 335;
		break;
	case 12:
		result += 366;
		break;
	}
	if ((dateYear % 4 == 0) && (dateYear % 100 != 0)) {

	}
	else {
		result -= 1;
	}

	if ((dateYear % 4 == 0) && (dateYear % 100 != 0)) {
		if ((dateHour <= 23) && (dateMinute < 59) && (dateSec < 59)) {
			result -= 1;
		}
	}

	return result;
}

unsigned int dateToSeconds(unsigned int dateSec, unsigned int dateMinute, unsigned int dateHour) {
	unsigned int result = 0;

	result += (dateHour * 60 * 60) + (dateMinute * 60) + dateSec;

	return result;
}

bool isDataValid(unsigned int dateSec, unsigned int dateMinute, unsigned int dateHour,
	unsigned int dateDay, unsigned int dateMonth, unsigned int dateYear) {
	bool status = true;

	if (dateYear < 0 || dateYear > 9999) {
		status = false;
	}

	if (dateMonth % 2 == 0) {
		if (dateMonth == 2) {
			if (isLeapYear(dateYear)) {
				if (dateDay > 29 || dateDay < 0) {
					status = false;
				}
			}
			else {
				if (dateDay > 28 || dateDay < 0) {
					status = false;
				}
			}
		}
		else if (dateMonth == 8) {
			if (dateDay > 31 || dateDay < 0) {
				status = false;
			}
		}
		else {
			if (dateDay > 30 || dateDay < 0) {
				status = false;
			}
		}
	}
	else {
		if (dateDay > 31 || dateDay < 0) {
			status = false;
		}
	}


	return status;
}

bool isLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0) {
		return 1;
	}
	else {
		return 0;
	}
}

unsigned int absolute(int a) {
	if (a < 0) {
		return a * (-1);
	}
	else {
		return a;
	}
}