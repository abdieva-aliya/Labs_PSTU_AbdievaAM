#include <iostream>
#include <clocale>
using namespace std;

int sum(int count, int a[]) {
    int k = 0;
    for (int i = 0; i < count; i++) {
        k += a[i];
    }
    return k;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Сколько чисел вы хотите сложить? ";
    cin >> n;

    int a[100];

    cout << "Введите " << n << " чисел через пробел: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Сумма чисел: " << sum(n, a) << endl;

    return 0;
}