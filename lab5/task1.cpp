#include "pch.h"
#include <iostream>
#include <limits>

int main() {
	setlocale(LC_ALL, "RU");
	int n;
	std::cout << "Введите кол-во элементов в последовательности: ";
	std::cin >> n;

	if (n <= 0) {
		std::cout << "Последовательность должна содержать хотя-бы один элемент." << std::endl;
		return 0;
	}

	double* a = new double[n];

	std::cout << "Введите элементы последовательности: ";
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	double sml = std::numeric_limits<double>::max();
	double lrg = std::numeric_limits<double>::lowest();

	for (int i = 0; i < n; ++i) {
		if (a[i] < sml) {
			sml = a[i];
		}
		if (a[i] > lrg) {
			lrg = a[i];
		}
	}

	double smlsqr = sml * sml;
	double lrgsqr = lrg * lrg;

	for (int i = 0; i < n; ++i) {
		if (a[i] >= 0) {
			a[i] *= smlsqr;
		}
		else {
			a[i] *= lrgsqr;
		}
	}

	std::cout << "Изменённая последовательность: ";
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	delete[] a;

	return 0;
}
