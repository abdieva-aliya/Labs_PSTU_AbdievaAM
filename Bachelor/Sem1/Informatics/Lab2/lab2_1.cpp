#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int sum = 0;

    for (int i = 3; i < 200; i += 3)
    {
        sum += i;
    }

    cout << "Сумма положительных чисел, кратных 3 и меньших 200: " << sum << endl;

    return 0;
}