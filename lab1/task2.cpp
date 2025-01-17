#include "pch.h"
#include <iostream>

int main() {
	setlocale(LC_ALL, "russian");
	int A = 1, B = 0, C = 1; // В этом случае работать с int будет легче

	// Логические операторы:
	// && = AND
	// || = OR
	// ! = NOT

	bool resultA = A || !(A && B) || C; // bool нужна как логическая переменная, определяющая true/false
	bool resultB = A || C && !(B || C);
	bool resultC = (A || B && !C) || A;

	std::cout << "Результат A: " << resultA << std::endl;
	std::cout << "Результат Б: " << resultB << std::endl;
	std::cout << "Результат В: " << resultC << std::endl;

	return 0;
}