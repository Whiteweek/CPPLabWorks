#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int n;

	cout << "Введите кол-во элементов в массиве: ";
	cin >> n;

	if (n <= 0) {
		cout << "Число элементов должно быть положительным." << endl;
		return 1;
	}

	vector<int> a(n);

	cout << "Введите " << n << " элемент(а/ов):" << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int FNI = -1; // first negative index
	int LPI = -1; // last positive index

	for (int i = 0; i < n; i++) {
		if (a[i] < 0 && FNI == -1) {
			FNI = i;
		}
		if (a[i] > 0) {
			LPI = i;
		}
	}

	if (FNI != -1) {
		cout << "Первый отрицательный элемент: " << a[FNI]
			<< ", который был введён " << FNI + 1 << "-ым." << endl;
	}
	else {
		cout << "Отрицательных элементов не найдено." << endl;
	}

	if (LPI != -1) {
		cout << "Последний положительный элемент: " << a[LPI]
			<< ", который был введён " << LPI + 1 << "-ым." << endl;
	}
	else {
		cout << "Положительных элементов не обнаружено." << endl;
	}

	return 0;
}
