#include <iostream>
#include <windows.h>
#include <clocale>
using namespace std;

int stolb[3][10];   // диски на каждом стержне
int disk[3];       // сколько дисков на каждом стержне
int N;

// Нарисовать башню
void risovat()
{
    system("cls");

    for (int ryad = N; ryad >= 1; ryad--) {
        for (int s = 0; s < 3; s++) {
            if (disk[s] >= ryad) {
                int nomer = ryad - 1;
                int d = stolb[s][nomer];
                int shirina = 2 * d - 1;
                int probelov = (2 * N + 1 - shirina) / 2;
                for (int k = 0; k < probelov; k++) cout << " ";
                for (int k = 0; k < shirina; k++) cout << "*";
                for (int k = 0; k < probelov; k++) cout << " ";
            } else {
                for (int k = 0; k < N; k++) cout << " ";
                cout << "|";
                for (int k = 0; k < N; k++) cout << " ";
            }
            cout << "   ";
        }
        cout << endl;
    }

    for (int s = 0; s < 3; s++) {
        for (int k = 0; k < 2 * N + 1; k++) cout << "-";
        cout << "   ";
    }
    cout << endl;

    for (int s = 0; s < 3; s++) {
        for (int k = 0; k < N; k++) cout << " ";
        cout << s + 1;
        for (int k = 0; k < N; k++) cout << " ";
        cout << "   ";
    }
    cout << endl;
}

// Переложить верхний диск со стержня a на стержень c
void perelozhit(int a, int c)
{
    int from = a - 1;
    int to = c - 1;

    int d = stolb[from][disk[from] - 1];   // берём верхний
    disk[from]--;                          // убрали
    stolb[to][disk[to]] = d;               // положили
    disk[to]++;

    risovat();
    Sleep(500);
}

// Рекурсия — как в оригинале
void han(int n, int a, int c, int b)
{
    if (n > 0) {
        han(n - 1, a, b, c);
        perelozhit(a, c);
        han(n - 1, b, c, a);
    }
}

int main()
{
    setlocale(LC_ALL, ".65001");

    cout << "Введите количество колец: ";
    cin >> N;

    // кладём все диски на первый стержень: снизу большой, сверху маленький
    for (int i = 0; i < N; i++) {
        stolb[0][i] = N - i;
    }
    disk[0] = N;
    disk[1] = 0;
    disk[2] = 0;

    risovat();
    Sleep(800);

    han(N, 1, 3, 2);

    cout << "Готово!" << endl;
    return 0;
}