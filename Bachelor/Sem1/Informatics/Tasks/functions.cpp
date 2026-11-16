#include <iostream>
#include <clocale>
using namespace std;

void sum(int, int);
int main(){
    setlocale(LC_ALL, ".65001");
    int a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    sum(a, b);
    return 0;
}
void sum(int a, int b){
    cout << "Результаты суммы: " << a + b << endl;
}