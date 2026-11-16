#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    string word;
    cout << "Введите слово: ";
    cin >> word;

    if (word.length() > 5) {
        // Заменяем первый байт на 'X', а второй удаляем.
        word.replace(0, 2, "X"); 
    } else {
        // Последняя буква: заменяем последние 2 байта на "X"
        word.replace(word.length() - 2, 2, "X");
    }

    cout << "Результат: ";
    for (int i = word.length() - 1; i >= 0; i--) {
        cout << word[i];
    }
    cout << endl;

    return 0;
}