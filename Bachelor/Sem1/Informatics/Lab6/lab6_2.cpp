#include <iostream>
#include <string>
#include <algorithm> // для reverse
using namespace std;

int main() {
    string str;
    cout << "Введите строку (в конце точка): ";
    getline(cin, str);

    // 1. Очищаем от пробелов и точки
    string clean = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ' && str[i] != '.') {
            clean += str[i];
        }
    }

    // 2. Переворачиваем
    string rev = clean;
    reverse(rev.begin(), rev.end());

    // 3. Сравниваем
    if (clean == rev) {
        cout << "Строка является палиндромом." << endl;
    } else {
        cout << "Строка не является палиндромом." << endl;
    }

    return 0;
}