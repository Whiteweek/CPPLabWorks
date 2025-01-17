#include "pch.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	int day;
	cout << "Введите порядковый номер дня недели (между 1 и 7): ";
	cin >> day;

	switch (day) {
	case 1:
		cout << "Понедельник: A, C";
		break;
	case 2:
		cout << "Вторник: B, D";
		break;
	case 3:
		cout << "Среда: E, F";
		break;
	case 4:
		cout << "Четверг: G, H";
		break;
	case 5:
		cout << "Пятница: I, J";
		break;
	case 6:
		cout << "Суббота: Отдых";
		break;
	case 7:
		cout << "Воскресенье: Отдых";
		break;
	default:
		cout << "Неправильный номер дня недели";
		break;
	}

	return 0;
}
