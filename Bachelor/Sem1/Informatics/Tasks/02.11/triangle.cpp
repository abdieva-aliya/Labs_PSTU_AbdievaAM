#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "Ошибка" << endl;
        return 0;
    }

    for (int i = 0; i <= n / 2; i++) {
        for (int j = 0; j < n / 2 - i; j++)
            cout << " ";
        for (int j = 0; j <= 2 * i; j++)
            cout << "*";
        cout << endl;
    }

    return 0;
}