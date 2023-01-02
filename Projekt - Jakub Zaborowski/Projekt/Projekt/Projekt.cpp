#include <iostream>
#include <locale.h>
#include "windows.h";
#include <string>
using namespace std;




/*
	Autor: Jakub Zaborowski
	Temat: Projekt semestralny - PESEL decrypter
	Data: 02.01.2023
*/





//funkcja zwracająca pełny rok z podanego PESELU
string yearChecker(int monthInt, string year) {
	if (monthInt > 20 && monthInt <= 32) {
		return  to_string(20) + year;
	}
	else if (monthInt > 40 && monthInt <= 52) {
		return  to_string(21) + year;
	}
	else if (monthInt > 60 && monthInt <= 72) {
		return  to_string(22) + year;
	}
	else {
		return  to_string(19) + year;
	}
}







//funkcja zwracająca odpowiednio zformatowany miesiąc z podanego PESELU
string monthChecker(int monthInt) {
	if (monthInt > 20 && monthInt <= 32) {
		if (monthInt < 30) {
			return to_string(0) + to_string(monthInt - 20);
		}
		else {
			return to_string(monthInt - 20);
		}
	}
	else if (monthInt > 40 && monthInt <= 52) {
		if (monthInt < 50) {
			return to_string(0) + to_string(monthInt - 40);
		}
		else {
			return to_string(monthInt - 40);
		}
	}
	else if (monthInt > 60 && monthInt <= 72) {
		if (monthInt < 70) {
			return to_string(0) + to_string(monthInt - 60);
		}
		else {
			return to_string(monthInt - 60);
		}
	}
	else {
		if (monthInt < 10) {
			return to_string(0) + to_string(monthInt);
		}
		else {
			return to_string(monthInt);
		}
	}
}







//funkcja zwracjąca płeć z podanego PESELU
string sexChecker(int number) {
	if (number % 2 == 0) {
		return "kobieta";
	}
	else {
		return "mężczyzna";
	}
}







//funkcja zwracająca odpowiedni wycinek tekstu z podanego PESELU
string stringConverter(string PESEL, int index, int countOfElements) {
	return PESEL.substr(index, countOfElements);
}









//funkcja budująca i zwracająca pełną datę używającą tylko liczb
string numberDateBuilder(string day, string month, string year) {
	return day + "." + month + "." + year;
}










//funkcja budująca i zwracająca pełną datę
string textDateBuilder(int day, string month, string year) {
	return to_string(day) + " " + month + " " + year;
}










//funkcja zwracająca miesiąc w formie tekstu
string monthToText(int month) {
	switch (month) {
	case 1: return "styczeń"; break;
	case 2: return "luty"; break;
	case 3: return "marzec"; break;
	case 4: return "kwiecień"; break;
	case 5: return "maj"; break;
	case 6: return "czerwiec"; break;
	case 7: return "lipiec"; break;
	case 8: return "sierpień"; break;
	case 9: return "wrzesień"; break;
	case 10: return "październik"; break;
	case 11: return "listopad"; break;
	case 12: return "grudzień"; break;
	}
}










//funkcja pobierająca i zwracająca podany PESEL
string setPESEL() {
	string PESEL;
	cout << "Podaj swój PESEL: ";
	cin >> PESEL;
	return PESEL;
}





string yearTypeChecker(int year) {
	if (year % 400 == 0) {
		return "przestępny";
	}
	else if (year % 100 == 0) {
		return "normalny";
	}
	else if (year % 4 == 0) {
		return "przestępny";
	}
	else {
		return "normalny";
	}
}





//funkcja ustawiająca odpowiednio sformatowaną czcionkę dla całego programu
void setFont() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 18;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}









//funkcja ustawiająca język całego programu (w tym przypadku polski)
void setLanguage() {
	setlocale(LC_CTYPE, "Polish");
}










//funkcja wyświetlająca komunikat o błędzie
void errorAlert() {
	cout << "Podany PESEL jest niepoprawny!";
	Sleep(2000);
	system("cls");
}









//funkcja wyświetlająca odpowiednio sformatowaną stylistycznie datę
void numberDateWriter(string date) {
	cout << endl << "Twoja data urodzenia (data używając samych liczb): ";
	
	//funkcja zmieniająca kolor czcionki (w tym przypadku na zielony)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << date;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << endl << endl;
}





//funkcja wyświetlająca odpowiednio sformatowaną stylistycznie datę
void sexWriter(string sex) {
	cout << "Twoja płeć: ";
	if (sex == "mężczyzna") {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}
	cout << sex;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << endl << endl;
}








//funkcja wyświetlająca odpowiednio sformatowaną stylistycznie płeć
void textDateWriter(string date) {
	cout << "Twoja data urodzenia: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << date;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << endl << endl;
}








//funkcja wyświetlająca komunikat o zakończeniu programu
void endOfApp() {
	cout << "Do zobaczenia :)";
	Sleep(4000);
	cout << endl << endl;
}





//funkcja sprawdzająca i zwracająca rodzaj roku urodzenia
void yearTypeWriter(string yearType) {
	cout << "Rodzaj roku, w którym się urodziłeś: ";
	if (yearType == "normalny") {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}
	cout << yearType;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << endl << endl;
}











//funkcja zwracająca długość podanego PESELU
int peselSizeBuilder(string PESEL) {
	return PESEL.length();
}










//funkcja zwracająca liczbę 1 w celu sprawdzenia poprawności PESELU
int peselChecker(int peselLen, int controlSum) {
	if (peselLen < 11 || peselLen > 11 || controlSum % 10 != 0) {
		;
		return 1;
	}
	else {
		return 0;
	}
}









//funkcja zwracająca sumę kontrolną 
int controlSumCalculator(int first, int second, int third, int fourth, int fifth, int sixth, int seventh, int eighth, int ninth, int tenth, int eleventh) {
	return (first * 1) + (second * 3) + (third * 7) + (fourth * 9) + (fifth * 1) + (sixth * 3) + (seventh * 7) + (eighth * 9) + (ninth * 1) + (tenth * 3) + (eleventh * 1);
}







//funkcja zapisująca cyfry z PESEL-u w tablicy
int* arrayFill(string PESEL) {
	static int array[11];

	for (int i = 0; i < 11; i++) {
		array[i] = stoi(stringConverter(PESEL, i, 1));
	}

	return array;
}





int main() {

	//wywołanie funkcji
	setFont();

	setLanguage();

	string PESEL;
	PESEL = setPESEL();


	int peselLen = peselSizeBuilder(PESEL);


	//tablica przechowująca cyfry z PESEL-u
	int* peselArray = arrayFill(PESEL);


	int controlSum = controlSumCalculator(peselArray[0], peselArray[1], peselArray[2], peselArray[3], peselArray[4], peselArray[5], peselArray[6], peselArray[7], peselArray[8], peselArray[9], peselArray[10]);
	int checker = peselChecker(peselLen, controlSum);



	//funkcja warunkowa sprawdzająca poprawność PESEL-u
	if (checker == 1) {
		errorAlert();
		main();
	}
	else {
		
		string year = stringConverter(PESEL, 0, 2),
			month = stringConverter(PESEL, 2, 2),
			day = stringConverter(PESEL, 4, 2),
			
			
			//zmienne oznaczające dane gotowe do utworzenia daty
			yearFull,
			monthFull,


			monthText,
			sex,

			//pełne daty gotowe do wyświetlenia (number - data z samych liczb, text - liczby z tekstem
			numberDateOfBirth,
			textDateOfBirth;




		int monthInt = stoi(month),
			yearInt = stoi(year),
			dayInt = stoi(day);


		string yearType = yearTypeChecker(yearInt);


		yearFull = yearChecker(monthInt, year);
		monthFull = monthChecker(monthInt);


		monthText = monthToText(stoi(monthFull));


		numberDateOfBirth = numberDateBuilder(day, monthFull, yearFull);
		textDateOfBirth = textDateBuilder(dayInt, monthText, yearFull);
		
		
		sex = sexChecker(peselArray[9]);
		

		numberDateWriter(numberDateOfBirth);
		textDateWriter(textDateOfBirth);
		sexWriter(sex);
		yearTypeWriter(yearType);


		endOfApp();
	}
}




