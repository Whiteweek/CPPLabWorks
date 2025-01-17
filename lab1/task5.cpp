#include "pch.h"
#include <iostream>

int main() {
	setlocale(LC_ALL, "russian");
	int A, B;

	std::cout << "Введи число A: ";
	std::cin >> A;
	std::cout << "Введи число B: ";
	std::cin >> B;

	if ((A % 2 == 0 && B % 2 == 0) || (A % 2 != 0 && B % 2 != 0)) {
		std::cout << "У чисел A и B одинаковая чётность.";
	}
	else {
		std::cout << "У чисел A и B неодинаковая чётность.";
	}

	return 0;
}