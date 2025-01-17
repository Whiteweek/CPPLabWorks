#include "pch.h"
#include <iostream>

int main() {
	setlocale(LC_ALL, "russian");
	int number;
	std::cout << "Введите трехзначное число: ";
	std::cin >> number;

	if (number < 100 || number > 999) {
		std::cout << "Ошибка: введено не трехзначное число" << std::endl;
		return 1;
	}

	int ones = number % 10;
	int tens = (number / 10) % 10;
	int hundreds = number / 100;

	int nunumber = hundreds * 100 + ones * 10 + tens;
	std::cout << "Число после перестановки: " << nunumber << std::endl;

	return 0;
}
