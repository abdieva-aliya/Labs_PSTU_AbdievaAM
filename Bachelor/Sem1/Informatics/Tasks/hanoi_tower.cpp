#include <iostream>
#include <clocale>
using namespace std;

void han(int n, int a, int c, int b)
{
    if (n <= 0)
        return;
    han(n-1, a, b, c);
    cout << a << " -> " << c << endl;
    han(n-1, b, c, a);
}
int main()
{
    setlocale(LC_ALL, ".65001");
    int n;
    cout << "Введите количество колец: ";
    cin >> n;
    han(n, 1, 3, 2);
    return 0;
}