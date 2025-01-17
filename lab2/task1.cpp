#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	int num1, num2, num3;
	cout << "Введите три числа: ";
	cin >> num1 >> num2 >> num3;

	int avg;
	if (num1 >= num2 && num1 >= num3) {
		if (num2 >= num3) {
			avg = num2;
		}
		else {
			avg = num3;
		}
	}
	else if (num2 >= num1 && num2 >= num3) {
		if (num1 >= num3) {
			avg = num1;
		}
		else {
			avg = num3;
		}
	}
	else {
		if (num1 >= num2) {
			avg = num1;
		}
		else {
			avg = num2;
		}
	}

	cout << "Среднее значение: " << avg << endl;

	return 0;
}