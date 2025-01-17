#include "pch.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	int k;
	cout << "Введите номер дня: ";
	cin >> k;

	bool isvalid = (k >= 1) && (k <= 365);
	if (!isvalid) {
		std::cout << "Ошибка: недействительный день года" << std::endl;
		return 1;
	}

	int dow = (k % 7); // day of week

	if (dow == 1) {
		cout << "Это понедельник" << endl;
	}
	else if (dow == 2) {
		cout << "Это вторник" << endl;
	}
	else if (dow == 3) {
		cout << "Это среда" << endl;
	}
	else if (dow == 4) {
		cout << "Это четверг" << endl;
	}
	else if (dow == 5) {
		cout << "Это пятница" << endl;
	}
	else if (dow == 6) {
		cout << "Это суббота" << endl;
	}
	else if (dow == 0) {
		cout << "Это воскресенье" << endl;
	}

	return 0;
}
