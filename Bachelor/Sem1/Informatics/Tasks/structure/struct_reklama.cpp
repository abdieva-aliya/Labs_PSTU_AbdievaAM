#include <iostream>
using namespace std;

struct Advertising {
    int show;
    double click;
    double money;
};

int main() {
    setlocale(LC_ALL, "Russian");

    Advertising ad;

    cout << "Введите количество показанных объявлений: ";
    cin >> ad.show;

    cout << "Введите процент посетителей, нажавших на объявление: ";
    cin >> ad.click;

    cout << "Введите средний доход за одно нажатие: ";
    cin >> ad.money;

    double dohod = ad.show * (ad.click / 100.0) * ad.money;

    cout << "Результаты:" << endl;
    cout << "Показано объявлений: " << ad.show << endl;
    cout << "Процент кликов: " << ad.click << "%" << endl;
    cout << "Средний доход за клик: " << ad.money << endl;
    cout << "Общий доход: " << dohod << endl;

    return 0;
}