﻿#include "pch.h"
#include <iostream>

int main() {
	setlocale(LC_ALL, "russian");
	int day;

	std::cout << "Введите день месяца: ";
	std::cin >> day;

	switch (day) {
	case 1:
		std::cout << "Сегодня привезут молочные продукты, хлеб";
		break;
	case 2:
		std::cout << "Сегодня привезут молочные продукты";
		break;
	case 3:
		std::cout << "Сегодня привезут молочные продукты, хлеб";
		break;
	case 4:
		std::cout << "Сегодня привезут молочные продукты";
		break;
	case 5:
		std::cout << "Сегодня привезут молочные продукты, хлеб, овощи/фрукты";
		break;
	case 6:
		std::cout << "Сегодня привезут молочные продукты, бакалею";
		break;
	case 7:
		std::cout << "Сегодня привезут молочные продукты, хлеб";
		break;
	case 8:
		std::cout << "Сегодня привезут молочные продукты";
		break;
	case 9:
		std::cout << "Сегодня привезут молочные продукты, хлеб";
		break;
	case 10:
		std::cout << "Сегодня привезут молочные продукты, овощи/фрукты";
		break;
	case 11:
		std::cout << "Сегодня привезут молочные продукты, хлеб";
		break;
	case 12:
		std::cout << "Сегодня привезут молочные продукты, бакалею";
		break;
	case 13:
		std::cout << "Сегодня привезут молочные продукты, хлеб";
		break;
	case 14:
		std::cout << "Сегодня привезут молочные продукты";
		break;
	case 15:
		std::cout << "Сегодня привезут молочные продукты, хлеб, овощи/фрукты";
		break;
	case 16:
		std::cout << "Сегодня привезут молочные продукты";
		break;
	case 17:
		std::cout << "Сегодня привезут молочные продукты, хлеб";
		break;
	case 18:
		std::cout << "Сегодня привезут молочные продукты, бакалею";
		break;
	case 19:
		std::cout << "Сегодня привезут молочные продукты, хлеб";
		break;
	case 20:
		std::cout << "Сегодня привезут молочные продукты, овощи/фрукты";
		break;
	case 21:
		std::cout << "Сегодня привезут молочные продукты, хлеб";
		break;
	case 22:
		std::cout << "Сегодня привезут молочные продукты";
		break;
	case 23:
		std::cout << "Сегодня привезут молочные продукты, хлеб";
		break;
	case 24:
		std::cout << "Сегодня привезут молочные продукты, бакалею";
		break;
	case 25:
		std::cout << "Сегодня привезут молочные продукты, хлеб, овощи/фрукты";
		break;
	case 26:
		std::cout << "Сегодня привезут молочные продукты";
		break;
	case 27:
		std::cout << "Сегодня привезут молочные продукты, хлеб";
		break;
	case 28:
		std::cout << "Сегодня привезут молочные продукты";
		break;
	case 29:
		std::cout << "Сегодня привезут молочные продукты, хлеб";
		break;
	case 30:
		std::cout << "Сегодня привезут молочные продукты, овощи/фрукты, бакалею";
		break;
	default:
		std::cout << "Сегодня ничего не привезут (выберите число между 1 и 30)";
	}

	return 0;
}