#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct Car {
	char model[50];
	float fuelcons[3];
	int maxspd;
	int power;
};

void txtobin(const string& txtfile, const string& binfile);
void processbinary(const string& inputbinfile, const string& outputbinfile);
void bintotxt(const string& binfile, const string& txtfile);

int main() {
	string txtfile = "cars.txt";
	string binfile = "cars.bin";
	string outputbinfile = "processedcars.bin";
	string outputtxtfile = "processedcars.txt";

	txtobin(txtfile, binfile);
	processbinary(binfile, outputbinfile);
	bintotxt(outputbinfile, outputtxtfile);

	return 0;
}

void txtobin(const string& txtfile, const string& binfile) {
	setlocale(LC_ALL, "RU");
	ifstream inFile(txtfile);
	ofstream outFile(binfile, ios::binary);
	if (!inFile || !outFile) {
		cerr << "Error opening file." << endl;
		return;
	}

	string line;
	while (getline(inFile, line)) {
		stringstream ss(line);
		Car car;
		string tempmodel, fuel;

		getline(ss, tempmodel, ';');
		strncpy_s(car.model, tempmodel.c_str(), sizeof(car.model) - 1);
		car.model[sizeof(car.model) - 1] = '\0';

		for (int i = 0; i < 3; ++i) {
			getline(ss, fuel, ';');
			car.fuelcons[i] = stof(fuel);
		}

		getline(ss, fuel, ';');
		car.maxspd = stoi(fuel);

		getline(ss, fuel, ';');
		car.power = stoi(fuel);

		outFile.write(reinterpret_cast<char*>(&car), sizeof(Car));
	}

	inFile.close();
	outFile.close();
}

void processbinary(const string& inputbinfile, const string& outputbinfile) {
	setlocale(LC_ALL, "RU");
	ifstream inFile(inputbinfile, ios::binary);
	ofstream outFile(outputbinfile, ios::binary);
	if (!inFile || !outFile) {
		cerr << "Error opening file." << endl;
		return;
	}

	inFile.seekg(0, ios::end);
	int count = inFile.tellg() / sizeof(Car);
	inFile.seekg(0, ios::beg);

	Car* cars = new Car[count];
	inFile.read(reinterpret_cast<char*>(cars), count * sizeof(Car));

	int choice;
	do {
		cout << "\nМеню:\n";
		cout << "1. Показать все автомобили\n";
		cout << "2. Увеличить мощность всех автомобилей на 10%\n";
		cout << "3. Сохранить изменения и выйти\n";
		cout << "Ваш выбор: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\nСписок автомобилей:\n";
			for (int i = 0; i < count; ++i) {
				cout << "Модель: " << cars[i].model << endl;
				cout << "Расход топлива (шоссе/город/смешанный): "
					<< cars[i].fuelcons[0] << ", "
					<< cars[i].fuelcons[1] << ", "
					<< cars[i].fuelcons[2] << endl;
				cout << "Максимальная скорость: " << cars[i].maxspd << " км/ч" << endl;
				cout << "Мощность: " << cars[i].power << " л.с." << endl;
			}
			break;

		case 2:
			for (int i = 0; i < count; ++i) {
				cars[i].power = static_cast<int>(cars[i].power * 1.1);
			}
			cout << "Мощность всех автомобилей увеличена на 10%.\n";
			break;

		case 3:
			cout << "Изменения сохранены.\n";
			break;

		default:
			cout << "Неверный выбор. Попробуйте снова.\n";
		}
	} while (choice != 3);

	outFile.write(reinterpret_cast<char*>(cars), count * sizeof(Car));

	delete[] cars;
	inFile.close();
	outFile.close();
}

void bintotxt(const string& binfile, const string& txtfile) {
	ifstream inFile(binfile, ios::binary);
	ofstream outFile(txtfile);
	if (!inFile || !outFile) {
		cerr << "Error opening file." << endl;
		return;
	}

	Car car;
	while (inFile.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
		outFile << car.model << ";"
			<< car.fuelcons[0] << ";"
			<< car.fuelcons[1] << ";"
			<< car.fuelcons[2] << ";"
			<< car.maxspd << ";"
			<< car.power << endl;
	}

	inFile.close();
	outFile.close();
}
