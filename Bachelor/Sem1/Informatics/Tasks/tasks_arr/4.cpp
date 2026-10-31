#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");

    int x, y;
    
    cout << "Введите количество строк и столбцов: ";
    cin >> x >> y;
    
    int a[100][100];
    
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> a[i][j];
        }
    }
    
    int max = a[0][0];
    int max_x = 0, max_y = 0;
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
                max_x = i;
                max_y = j;
            }
        }
    }

    cout << "Максимальный элемент: " << max << endl;
    cout << "Индексы: строка = " << max_x << ", столбец = " << max_y << endl;
    
    return 0;
}