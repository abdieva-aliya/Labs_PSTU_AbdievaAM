#include <iostream>
#include <string>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    wstring word;
    wcout << L"Введите слово: ";
    wcin >> word;

    // Проверяем длину (считаются именно буквы, а не байты)
    if (word.length() > 5) {
        word[0] = L'X'; // Меняем первую букву
    } else {
        word[word.length() - 1] = L'X'; // Меняем последнюю букву
    }

    // Выводим справа налево
    wcout << L"Результат: ";
    for (int i = word.length() - 1; i >= 0; i--) {
        wcout << word[i];
    }
    wcout << endl;

    return 0;
}