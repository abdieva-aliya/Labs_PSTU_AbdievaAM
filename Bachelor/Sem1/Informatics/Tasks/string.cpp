#include <iostream>
#include <string>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");
    
    string word;

    cout << "Введите слово: ";
    cin >> word;

    // Проверяем длину
    if (word.length() > 5) {
        word[0] = 'X'; // Меняем первую букву
    } else {
        word[word.length() - 1] = 'X'; // Меняем последнюю букву
    }

    // Выводим справа налево
    cout << "Результат: ";
    for (int i = word.length() - 1; i >= 0; i--) {
        cout << word[i];
    }
    cout << endl;

    return 0;
}