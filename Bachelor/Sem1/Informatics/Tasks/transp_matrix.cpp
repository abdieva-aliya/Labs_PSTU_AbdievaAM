#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");

    int x = 5;
    int y = 5;

    int** a = new int*[x];
    for (int i = 0; i < x; i++) {
        a[i] = new int[y];
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            a[i][j] = i * y + j;
        }
    }

    int** t = new int*[y];
    for (int i = 0; i < y; i++) {
        t[i] = new int[x];
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            t[j][i] = a[i][j];
        }
    }

    cout << "Исходная матрица (" << x << "x" << y << "):";
    cout << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Транспонированная матрица (" << y << "x" << x << "):";
    cout << endl;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < x; i++) delete[] a[i];
    delete[] a;

    for (int i = 0; i < y; i++) delete[] t[i];
    delete[] t;

    return 0;
}