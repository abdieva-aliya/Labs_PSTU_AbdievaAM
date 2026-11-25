#include <iostream>
#include <string>
using namespace std;

struct Data {
    string FIO;
    int days;
    double pay;
    double bonus;
};

int main() {
    setlocale(LC_ALL, "Russian");

    Data w;

    cout << "Введите ФИО работника: ";
    getline(cin, w.FIO);

    cout << "Введите количество отработанных дней: ";
    cin >> w.days;

    cout << "Введите оплату за один день: ";
    cin >> w.pay;

    cout << "Введите размер премии: ";
    cin >> w.bonus;

    double money = w.days * w.pay + w.bonus;

    cout << "Расчет заработной платы:" << endl;
    cout << "ФИО работника:      " << w.FIO << endl;
    cout << "Отработано дней:    " << w.days << endl;
    cout << "Оплата за день:     " << w.pay << " руб." << endl;
    cout << "Премия:             " << w.bonus << " руб." << endl;
    cout << "Итого к выплате:    " << money << " руб." << endl;

    return 0;
}