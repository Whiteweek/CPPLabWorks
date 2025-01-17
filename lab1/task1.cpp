#include "pch.h"
#include <iostream>

int main() {
	setlocale(LC_ALL, "russian");
	double r, v, c;
	std::cout << "Введите значение сопротивления и напряжения (через пробел): ";
	std::cin >> r >> v;
	c = v / r;
	std::cout << "Сила тока I = " << c << std::endl;
	return 0;
}
