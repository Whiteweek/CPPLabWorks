#include "pch.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int n;
	int c, d;

	cout << "Введите размер массива (n): ";
	cin >> n;

	int* arr = new int[n];

	cout << "Введите " << n << " элемент(а/ов) массива:" << endl;
	for (int i = 0; i < n; ++i) {
		cin >> *(arr + i);
	}

	cout << "Введите диапазон [c, d] (c < d): ";
	cin >> c >> d;

	if (c >= d) {
		cout << "Неверный диапазон. Убедитесь, что c < d." << endl;
		delete[] arr;
		return 1;
	}

	int count = 0;
	for (int i = 0; i < n; ++i) {
		int value = *(arr + i);
		if (value < c || value > d) {
			++count;
		}
	}

	cout << "Количество элементов вне диапазона [" << c << ", " << d << "]: " << count << endl;

	delete[] arr;

	return 0;
}