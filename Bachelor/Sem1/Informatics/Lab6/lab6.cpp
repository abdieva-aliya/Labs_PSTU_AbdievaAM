#include <iostream>
#include <cstring>
#include <cctype>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");

    char str[255];
    cout << "Введите строку (в конце точка): ";
    cin.getline(str, 255);

    int left = 0;                // Начало строки
    int right = strlen(str) - 1; // Конец строки
    bool f = true;               // Флажок палиндрома

    while (left < right && f == true) {
        
        // Если слева пробел или точка — сдвигаем левый индекс вправо
        if (str[left] == ' ' || str[left] == '.') {
            left++;
        }
        // Если справа пробел или точка — сдвигаем правый индекс влево
        else if (str[right] == ' ' || str[right] == '.') {
            right--;
        }
        else {
            // Приводим английские буквы к нижнему регистру и сравниваем
            char c1 = tolower(str[left]);
            char c2 = tolower(str[right]);

            if (c1 != c2) {
                f = false;
            }

            // Сдвигаем оба индекса навстречу друг другу
            left++;
            right--;
        }
    }

    if (f) {
        cout << "Палиндром!" << endl;
    } else {
        cout << "Не палиндром!" << endl;
    }
    return 0;
}