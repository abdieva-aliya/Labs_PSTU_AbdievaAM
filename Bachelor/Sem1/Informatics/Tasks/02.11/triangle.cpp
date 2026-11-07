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

    for (int r = 0; r < (n + 1) / 2; r++) {
        for (int s = 0; s < (n + 1) / 2 - 1 - r; s++)
            cout << " ";
        for (int s = 0; s < 2 * r + 1; s++)
            cout << "*";
        cout << endl;
    }

    return 0;
}