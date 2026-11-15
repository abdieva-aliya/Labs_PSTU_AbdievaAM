#include <iostream>
#include <cstring>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    char str[255];
    cout << "Введите строку (в конце точка): ";
    cin.getline(str, 255);

    int left = 0;                // Начало строки
    int right = strlen(str) - 1; // Конец строки
    bool f = true;   // Флажок: изначально думаем, что это палиндром

    // Цикл работает, пока индексы не встретились и пока это палиндром
    while (left < right && f == true) {
        
        // Если слева пробел или точка — сдвигаем левый индекс вправо
        if (str[left] == ' ' || str[left] == '.') {
            left++;
        }
        // Если справа пробел или точка — сдвигаем правый индекс влево
        else if (str[right] == ' ' || str[right] == '.') {
            right--;
        }
        else{
            // Если буквы разные — это не палиндром
            if (str[left] != str[right]) {
                f = false;
            }

            // Сдвигаем оба индекса навстречу друг другу
            left++;
            right--;
        }
    }

    if (f) {
        cout << "Строка является палиндромом." << endl;
    } else {
        cout << "Строка не является палиндромом." << endl;
    }
    return 0;
}