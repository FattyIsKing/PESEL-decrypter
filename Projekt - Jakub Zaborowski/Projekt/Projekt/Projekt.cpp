#include <iostream>
#include <locale.h>
#include "windows.h"
#include <string>
using namespace std;




/*
	Autor: Jakub Zaborowski
	Temat: Projekt semestralny - PESEL decrypter
	Data: 03.01.2023
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
string genderChecker(int number) {
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






//funkcja tworząca odpowiedni rodzaj daty zależnie od wprowadzonej zmiennej sprawdzającej (1 - data liczbowa, inna liczba - data z tekstem)
string dateBuilder(string day, string month, string year, int check) {
	if (check == 1) {
		return day + "." + month + "." + year;
	}
	else {
		return to_string(stoi(day)) + " " + month + " " + year;
	}
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
	default: return "nieznany miesiąc"; break;
	}
}










//funkcja pobierająca i zwracająca podany PESEL
string setPESEL() {
	string PESEL;
	cout << "Podaj swój PESEL: ";
	cin >> PESEL;
	return PESEL;
}





//funkcja ustalająca rodzaj roku urodzenia z PESEL-u (zwyczajny czy przestępny)
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






//funkcja ustawiająca kolor czcionki zależnie spełnionego warunku
void colorChecker(string text) {
	if (text == "przestępny" || text == "kobieta") {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}
	else if (text == "normalny" || text == "mężczyzna") {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
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







//funkcja wypisująca wszystkie dane pobrane z PESEL-u
void dataWriter(string text, string data) {
	cout << text;
	colorChecker(data);
	cout << data << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}







//funkcja wyświetlająca komunikat o zakończeniu programu
void endOfApp() {
	cout << "Do zobaczenia :)";
	Sleep(4000);
	cout << endl << endl;
}




//funkcja zwracająca długość podanego PESELU
int peselSizeBuilder(string PESEL) {
	return PESEL.length();
}










//funkcja zwracająca liczbę 1 w celu sprawdzenia poprawności PESELU
int peselChecker(int peselLen, int controlSum) {
	if (peselLen < 11 || peselLen > 11 || controlSum % 10 != 0) {
		return 1;
	}
	else {
		return 0;
	}
}









//funkcja zwracająca sumę kontrolną 
int controlSumCalculator(int tab[]) {
	int controlSum = 0;
	
	for (int i = 0; i < 11; i++) {
		if (i == 0 || i == 4 || i == 8 || i == 10) {
			controlSum += tab[i] * 1;
		}
		else if (i == 1 || i == 5 || i == 9) {
			controlSum += tab[i] * 3;
		}
		else if (i == 2 || i == 6) {
			controlSum += tab[i] * 7;
		}
		else if (i == 3 || i == 7) {
			controlSum += tab[i] * 9;
		}
	}
	return controlSum;
}





//funkcja zapisująca cyfry z PESEL-u w tablicy
int* arrayFill(string PESEL) {
	
	static int array[11]{};

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


	int controlSum = controlSumCalculator(peselArray);
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
			gender,


			//pełna data gotowa do wyświetlenia
			dateOfBirth;



		string yearType = yearTypeChecker(stoi(year));




		yearFull = yearChecker(stoi(month), year);
		monthFull = monthChecker(stoi(month));



		monthText = monthToText(stoi(monthFull));

		cout << endl;


		dateOfBirth = dateBuilder(day, monthFull, yearFull, 1);
		dataWriter("Twoja data urodzenia (używając tylko liczb): ", dateOfBirth);



		dateOfBirth = dateBuilder(day, monthText, yearFull, 2);
		dataWriter("Twoja data urodzenia: ", dateOfBirth);



		gender = genderChecker(peselArray[9]);
		dataWriter("Twoja płeć: ", gender);


		dataWriter("Rodzaj roku, w którym się urodziłeś (normalny/przestępny): ", yearType);

		endOfApp();
	}
}