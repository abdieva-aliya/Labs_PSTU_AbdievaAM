#include <iostream>
using namespace std;

int main()
{
    int a = 12;
    int* ptr = &a;
    int copy = *ptr;

    (*ptr)++;
    cout << a << " " << copy;

    return 0;
}