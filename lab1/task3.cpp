#include "pch.h"
#include <iostream>

int main() {
	setlocale(LC_ALL, "russian");
	double R1, R2, S1, S2, S3;
	const double pi = 3.14;

	std::cout << "Введите радиус R1: ";
	std::cin >> R1;
	std::cout << "Введите радиус R2: ";
	std::cin >> R2;

	S1 = pi * R1 * R1;
	S2 = pi * R2 * R2;
	S3 = S1 - S2;

	std::cout << "Площадь круга S1: " << S1 << std::endl;
	std::cout << "Площадь круга S2: " << S2 << std::endl;
	std::cout << "Площадь кольца S3: " << S3 << std::endl;

	return 0;
}
