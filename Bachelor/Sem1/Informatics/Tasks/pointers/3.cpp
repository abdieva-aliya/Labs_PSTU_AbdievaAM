#include <iostream>
using namespace std;

int main()
{
    int a = 4;
    int b = 9;
    int* p = &a;
    int* q = p;
    int& r = *p;
    p = &b;
    *q += *p;
    *p = r - 3;  // ВОПРОС!
    q = p;
    *q += r;
    cout << a << " " << b << " " << r;
}

// Вывод: 13 23 13
/* В конце "p" и "q" указывают на переменную "b".
"r" обозначает ссылку на переменную "a". */