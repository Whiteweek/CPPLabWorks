#include "pch.h"
#include <iostream>
#include <string>

const int passgrade = 50;

struct Discipline {
	std::string name;
	int grade;
};

struct Student {
	std::string fullname;
	Discipline* disciplines;
	int numofdisc;
};

bool nodebt(const Student& student) {
	for (int i = 0; i < student.numofdisc; ++i) {
		if (student.disciplines[i].grade < passgrade) {
			return false;
		}
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "RU");
	int numofstudents;

	std::cout << "Введите кол-во студентов: ";
	std::cin >> numofstudents;

	Student* students = new Student[numofstudents];

	for (int i = 0; i < numofstudents; ++i) {
		std::cin.ignore();
		std::cout << "Введите ФИО студента " << i + 1 << ": ";
		std::getline(std::cin, students[i].fullname);

		std::cout << "Введите кол-во дисциплин для " << students[i].fullname << ": ";
		std::cin >> students[i].numofdisc;

		students[i].disciplines = new Discipline[students[i].numofdisc];

		for (int j = 0; j < students[i].numofdisc; ++j) {
			std::cin.ignore();
			std::cout << "Введите название дисциплины " << j + 1 << ": ";
			std::getline(std::cin, students[i].disciplines[j].name);

			std::cout << "Введите оценку за " << students[i].disciplines[j].name << ": ";
			std::cin >> students[i].disciplines[j].grade;
		}
	}

	int swnd = 0; // students with no debt
	for (int i = 0; i < numofstudents; ++i) {
		if (nodebt(students[i])) {
			++swnd;
		}
	}

	std::cout << "Число студентов без задолженностей: " << swnd << std::endl;

	for (int i = 0; i < numofstudents; ++i) {
		delete[] students[i].disciplines;
	}
	delete[] students;

	return 0;
}
