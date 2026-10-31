// Проверка последовательности на возрастание

#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    bool f = false;

    int n, i = 1, a;

    cin >> n;

    while((i <= n) && !f){
        cin >> a;
        if (a == 0)
        i = i + 1;
        else
        f = true;
    }
    if (f == true){
        if (a > 0)
        cout << "Число положительное";
        else
        cout << "Число отрицательное";
    }
    else
    cout << "Последовательность состоит из нулей";

    return 0;
}