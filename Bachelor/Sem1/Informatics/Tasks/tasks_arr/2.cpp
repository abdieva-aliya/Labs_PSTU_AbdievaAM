#include <iostream>
#include <clocale>
using namespace std;

int main() {
    int n;
    int a[100];

    cout << "Введите размер массива: ";
    cin >> n;

    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    bool f = false;
    
    int i = 0;
    while ((i < (n - 1)) && !f) {
        if (a[i] >= a[i + 1])
            f = true;
        else
        i++;
    }
    
    if (f)
        cout << "Массив не упорядочен" << endl;
    else
        cout << "Массив упорядочен" << endl;
    
    return 0;
}