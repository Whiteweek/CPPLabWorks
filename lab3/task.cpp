#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	double a = 0.1;
	double b = 1;
	double h = (b - a) / 10;

	for (double x = a; x <= b; x += h) {
		double y = (((pow(x, 2) / 4) + (x / 2) + 1) * exp(x / 2));
		double s = x;
		int n = 1;

		while (n <= 140) {
			s += (-1) * pow(x, 2 * n + 1) / tgamma(2 * n + 2);
			n++;
		}

		cout << "x = " << x << "; Y(x) = " << y << "; S(x) = " << s << endl;
	}

	return 0;
}