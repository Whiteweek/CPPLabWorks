#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int n;
	int k;
	cout << "Введите количество строк: ";
	cin >> n;
	cout << "Введите количество столбцов: ";
	cin >> k;

	vector<vector<char>> mas(n, vector<char>(k));
	cout << "Введите элементы массива:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> mas[i][j];
		}
	}

	cout << "Символы в углах: ";
	cout << mas[0][0] << mas[0][k - 1] << mas[n - 1][0] << mas[n - 1][k - 1] << endl;

	return 0;
}