#include <iostream>
#include <clocale>
using namespace std;

int tselye(int a, int b) {
    return a + b;
}

// a и b - части первого числа, c и d - части второго
void complex(int a, int b, int c, int d) {
    cout << (a + c) << " + " << (b + d) << "i" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int x, y;
    cout << "Введите два целых числа: ";
    cin >> x >> y;
    cout << "Сумма целых: " << tselye(x, y) << endl;

    int a, b, c, d;
    cout << "Введите действительную и мнимую часть первого комплексного числа: ";
    cin >> a >> b;
    cout << "Введите действительную и мнимую часть второго комплексного числа: ";
    cin >> c >> d;
    
    cout << "Сумма комплексных чисел: ";
    complex(a, b, c, d);
    
    return 0;
}