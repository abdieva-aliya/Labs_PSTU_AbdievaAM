#include <iostream>
#include <cstring>  // Для strlen, strcpy
#include <cctype>   // Для isalnum, tolower
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");

    char str[255];       // Исходная строка
    char clean_str[255]; // Очищенная строка (только буквы и цифры)
    
    cout << "Введите строку (до 255 символов, в конце точка):" << endl;
    cin.getline(str, 255); // Ввод строки с пробелами (аналог gets)

    int len = strlen(str);
    int k = 0; // Индекс для clean_str

    // 1. Очищаем строку от пробелов, точек и приводим к нижнему регистру
    for (int i = 0; i < len; i++) {
        // Если символ является буквой или цифрой (игнорируем пробелы и точку)
        if (isalnum(str[i])) {
            clean_str[k] = tolower(str[i]); // Приводим к нижнему регистру
            k++;
        }
    }
    clean_str[k] = '\0'; // Закрываем новую строку нуль-терминатором

    // 2. Проверяем на палиндром
    int left = 0;
    int right = k - 1; // Длина clean_str - 1
    bool is_palindrome = true;

    while (left < right) {
        if (clean_str[left] != clean_str[right]) {
            is_palindrome = false;
            break; // Нашли несовпадение — дальше можно не проверять
        }
        left++;
        right--;
    }

    // 3. Вывод результата
    if (k == 0) {
        cout << "Строка не содержит букв или цифр." << endl;
    } else if (is_palindrome) {
        cout << "Строка является палиндромом." << endl;
    } else {
        cout << "Строка НЕ является палиндромом." << endl;
    }

    return 0;
}