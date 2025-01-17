#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

void sasn(std::vector<std::vector<int>>& matrix) { // sort after second negative 
	int rc = matrix.size(); // row count
	int cc = matrix[0].size(); // column count

	int nc = 0; // negative count
	bool fsn = false; // found second negative?
	std::vector<int> ets; // elements to sort

	for (int i = 0; i < rc; ++i) {
		for (int j = 0; j < cc; ++j) {
			if (matrix[i][j] < 0) {
				nc++;
			}
			if (nc == 2) {
				fsn = true;
				for (int k = i; k < rc; ++k) {
					int sc = (k == i) ? (j + 1) : 0; 
					for (int l = sc; l < cc; ++l) {
						ets.push_back(matrix[k][l]);
					}
				}
				break;
			}
		}
		if (fsn) {
			break;
		}
	}

	std::sort(ets.begin(), ets.end(), std::greater<int>());

	if (fsn) {
		int index = 0;
		for (int i = 0; i < rc; ++i) {
			for (int j = 0; j < cc; ++j) {
				if (nc == 2 && index < ets.size()) {
					if (matrix[i][j] == ets[0]) {
						index++;
					}
				}
				if (index < ets.size()) {
					if (matrix[i][j] != ets[0]) {
						matrix[i][j] = ets[index++];
					}
				}
			}
			if (index >= ets.size()) {
				break;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	std::vector<std::vector<int>> matrix = {
		{3, -1, 7, 2},
		{4, -2, 1, 10},
		{5, 6, -3, -4},
		{8, 15, 9, 0}
	};

	std::cout << "Первоначальная матрица:\n";
	for (const auto& row : matrix) {
		for (int val : row) {
			std::cout << val << " ";
		}
		std::cout << "\n";
	}

	sasn(matrix);

	std::cout << "\nМатрица после сортировки элементов после второго отрицательного числа:\n";
	for (const auto& row : matrix) {
		for (int val : row) {
			std::cout << val << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
