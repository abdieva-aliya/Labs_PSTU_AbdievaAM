#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int sum = 0;

    for (int i = 3; i < 200; sum += 3)
    {
        sum += i;
    }

    cout << "Сумма положительных чисел, кратных 3 и меньших 200: " << sum << endl;

    return 0;
}