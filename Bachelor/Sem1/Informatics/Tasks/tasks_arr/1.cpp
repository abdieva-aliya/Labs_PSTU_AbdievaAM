#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int n;
    int a[100];

    cout << "Введите размер массива: ";
    cin >> n;

    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int max = a[0];
    int min = a[0];

    for (int i = 0; i < n; i++) {
        if (a[i] > max)
        max = a[i];
        if (a[i] < min)
        min = a[i];
    }

    int max_ind = -1;
    int min_ind = -1;
    int max_cnt = 0;
    int min_cnt = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == max) {
            if (max_ind == -1)
            max_ind = i;
            max_cnt++;
        }
        if (a[i] == min) {
            if (min_ind == -1)
            min_ind = i;
            min_cnt++;
        }
    }

    cout << "Максимум = " << max << endl;
    cout << "Минимум  = " << min << endl;
    cout << "Первый максимум: индекс " << max_ind << " (номер " << max_ind + 1 << "), всего таких: " << max_cnt << endl;
    cout << "Первый минимум:  индекс " << min_ind << " (номер " << min_ind + 1 << "), всего таких: " << min_cnt << endl;

    return 0;
}