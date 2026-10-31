// Проверка последовательности на возрастание

#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int a, b;
    bool f = false;

    cin >> a;

    if (a == 0) {
        cout << "Ошибка";
        return 0;
    }

    cin >> b;
    while ((b != 0) && !f) {
        if (a < b) {
            a = b;
            cin >> b;
        }
        else {
            f = true;
        }
    }

    if (f)
        cout << "Последовательность не упорядочена";
    else
        cout << "Последовательность упорядочена";

    return 0;
}