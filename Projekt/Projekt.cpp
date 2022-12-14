#include <iostream>
#include <locale.h>
#include "windows.h";
#include <string>

using namespace std;

string yearChecker(int monthInt, string yearFull, string year) {
	if (monthInt > 20 && monthInt <= 32) {
		return yearFull = to_string(20) + year;
	}
	else if (monthInt > 40 && monthInt <= 52) {
		return yearFull = to_string(21) + year;
	}
	else if (monthInt > 60 && monthInt <= 72) {
		return yearFull = to_string(22) + year;
	}
	else {
		return yearFull = to_string(19) + year;
	}
}


string monthChecker(int monthInt, string monthFull) {
	if (monthInt > 20 && monthInt <= 32) {
		if (monthInt < 30) {
			return monthFull = to_string(0) + to_string(monthInt - 20);
		}
		else {
			return monthFull = to_string(monthInt - 20);
		}
	}
	else if (monthInt > 40 && monthInt <= 52) {
		if (monthInt < 50) {
			return monthFull = to_string(0) + to_string(monthInt - 40);
		}
		else {
			return monthFull = to_string(monthInt - 40);
		}
	}
	else if (monthInt > 60 && monthInt <= 72) {
		if (monthInt < 70) {
			return monthFull = to_string(0) + to_string(monthInt - 60);
		}
		else {
			return monthFull = to_string(monthInt - 60);
		}
	}
	else {
		if (monthInt < 10) {
			return monthFull = to_string(0) + to_string(monthInt);
		}
		else {
			return monthFull = to_string(monthInt);
		}
	}
}

string sexChecker(int tenthN, string sex) {
	if (tenthN % 2 == 0) {
		return sex = "kobieta";
	}
	else {
		return sex = "mężczyzna";
	}
}

int peselSizeWriter(string PESEL) {
	return PESEL.size();
}

void errorAlert() {
	cout << "Podany PESEL jest niepoprawny!";
	Sleep(2000);
	system("cls");
}

int controlSumCalculator(int controlSum, int first, int second, int third, int fourth, int fifth, int sixth, int seventh, int eighth, int ninth, int tenth, int eleventh) {
	return controlSum = (first * 1) + (second * 3) + (third * 7) + (fourth * 9) + (fifth * 1) + (sixth * 3) + (seventh * 7) + (eighth * 9) + (ninth * 1) + (tenth * 3) + (eleventh * 1);
}

string stringConverter(string PESEL, int index, int countOfElements) {
	return PESEL.substr(index, countOfElements);
}

void peselManager() {
	setlocale(LC_CTYPE, "Polish");
	string PESEL;
	cout << "Podaj swój PESEL: ";
	cin >> PESEL;

	int peselLen = peselSizeWriter(PESEL);

	int firstN = stoi(stringConverter(PESEL, 0, 1)),
		secondN = stoi(stringConverter(PESEL, 1, 1)),
		thirdN = stoi(stringConverter(PESEL, 2, 1)),
		fourthN = stoi(stringConverter(PESEL, 3, 1)),
		fifthN = stoi(stringConverter(PESEL, 4, 1)),
		sixthN = stoi(stringConverter(PESEL, 5, 1)),
		seventhN = stoi(stringConverter(PESEL, 6, 1)),
		eighthN = stoi(stringConverter(PESEL, 7, 1)),
		ninthN = stoi(stringConverter(PESEL, 8, 1)),
		tenthN = stoi(stringConverter(PESEL, 9, 1)),
		eleventhN = stoi(stringConverter(PESEL, 10, 1)),

		controlSum = (firstN * 1) + (secondN * 3) + (thirdN * 7) + (fourthN * 9) + (fifthN * 1) + (sixthN * 3) + (seventhN * 7) + (eighthN * 9) + (ninthN * 1) + (tenthN * 3) + (eleventhN * 1);


	if (peselLen < 11 || peselLen > 11) {
		errorAlert();
		peselManager();
	}
	else if (controlSum % 10 != 0) {
		errorAlert();
		peselManager();
	}
	else {
		string year = stringConverter(PESEL, 0, 2),
			month = stringConverter(PESEL, 2, 2),
			day = stringConverter(PESEL, 4, 2),
			yearFull,
			dayFull,
			monthFull,
			sex,
			dateOfBirth;

		int monthInt = stoi(month),
			yearInt = stoi(year),
			dayInt = stoi(day),
			check = 0;

		yearFull = yearChecker(monthInt, yearFull, year);
		monthFull = monthChecker(monthInt, monthFull);
		dayFull = day;

		dateOfBirth = dayFull + "." + monthFull + "." + yearFull;
		sex = sexChecker(tenthN, sex);
		

		printf("Twoja data urodzenia: %s ", dateOfBirth.c_str());
		printf("Twoja płeć: %s ", sex.c_str());

		cout << endl;

		cout << "Co chcesz zrobić dalej? (1 - ponowne uruchomienie programu, inna liczba - zakończenie programu): ";
		cin >> check;

		cout << endl;

		if (check == 1) {
			Sleep(1000);
			system("cls");
			peselManager();
		}
		else{
			cout << "Do zobaczenia :)";
			Sleep(1000);
		}
	}
}


int main()
{
	peselManager();
}


