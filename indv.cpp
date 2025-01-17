#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double a = 0.1;
    double b = 1;
    double h = (b - a) / 10;

    // Вычисляем значения функции и ее разложения в ряд
    for (double x = a; x <= b; x += h) {
        double y = sin(x);
        double s = x;
        int n = 1;

        // Вычисляем члены разложения в ряд
        while (n <= 160) {
            s += (-1) * pow(x, 2 * n + 1) / tgamma(2 * n + 2);
            n++;
        }

        // Выводим значения на экран
        cout << "x = " << x << "; Y(x) = " << y << "; S(x) = " << s << endl;
    }

    return 0;
}