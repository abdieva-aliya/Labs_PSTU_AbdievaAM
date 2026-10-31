// Сумма элементов строк массива (матрицы)

#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int a[2][3];

    for (int i = 0; i < 2; i++) {
        cout << "Строка " << i + 1 << " (3 числа): ";
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }

    int max_len = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            int x = a[i][j], len = 0;
            if (x < 0) {
                len = 1; x = -x;
            }
            if (x == 0)
            len = 1;
            else
            while (x > 0) {
                len++;
                x = x / 10;
            }
            if (len > max_len)
            max_len = len;
        }
    }

    int sum1 = 0, sum2 = 0;

    cout << "Матрица:";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(max_len + 1) << a[i][j];
            if (i == 0) 
            sum1 = sum1 + a[i][j];
            else
            sum2 = sum2 + a[i][j];
        }
        cout << endl;
    }

    cout << "Сумма 1-й строки: " << sum1 << endl;
    cout << "Сумма 2-й строки: " << sum2 << endl;

    return 0;
}

// setw задаёт ширину поля для следующего вывода


