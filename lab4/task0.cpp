#include "pch.h"
#include <iostream>
#include <vector>

void transformarray(char a[], int k) {
	std::vector<char> nums;
	std::vector<char> others;

	for (int i = 0; i < k; ++i) {
		if (isdigit(a[i])) {
			nums.push_back(a[i]);
		}
		else {
			others.push_back(a[i]);
		}
	}

	int index = 0;
	for (char num : nums) {
		a[index++] = num;
	}
	for (char other : others) {
		a[index++] = other;
	}
}

int main() {
	setlocale(LC_ALL, "RU");

	char a[] = {'a', '1', 'c', '3', 'b', '4', 'd', '2'};
	int k = sizeof(a) / sizeof(a[0]);

	transformarray(a, k);

	std::cout << "Преобразованный массив: ";
	for (int i = 0; i < k; ++i) {
		std::cout << a[i] << ' ';
	}

	return 0;
}
