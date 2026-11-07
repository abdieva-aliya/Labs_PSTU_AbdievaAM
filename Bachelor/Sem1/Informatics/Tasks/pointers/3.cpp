#include <iostream>
using namespace std;

int main()
{
    int a = 4;
    int b = 9;
    int* p = &a;
    cout << *p << endl;
    int* q = p;
    cout << *q << endl;
    int& r = *p;
    cout << r << endl;
    p = &b;
    cout << p << endl;
    *q += *p;
    cout << *q << endl;
    *p = r - 3;
    cout << *p << endl;
    q = p;
    cout << q << endl;
    *q += r;
    cout << *q << endl;
    cout << a << " " << b << " " << r;
}