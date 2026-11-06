#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int a = 12;
    int* ptr = &a;
    int copy = *ptr;

    (*ptr)++;
    cout << a << " " << copy;

    return 0;
}