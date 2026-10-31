// Метод вставки

#include <iostream>
#include <clocale>
#include <stdlib.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int a[100];
    int n;

    cout << "Введите размер массива: ";
    cin >> n;

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 101 - 50;
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < n; i++) {
        int y = a[i];
        bool f = false;
        int j = i - 1;

        while ((j >= 0) && !f) {
            if (a[j] > y){
                a[j + 1] = a[j];
                j--;
            }
            else{
            f = true;
            }
        }
        a[j + 1] = y;
    }
        
        cout << "Отсортированный массив: ";
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }

        cout << endl;

        return 0;
}