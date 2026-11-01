#include <iostream>
#include <clocale>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int N, K;
    cout << "Введите размер массива N: ";
    cin >> N;
    cout << "Введите номер элемента для удаления K: ";
    cin >> K;

    // 1. Создаем массив a и заполняем его
    int* a = new int[N]; // выделяем память под массив из N элементов
    cout << "Исходный массив: ";
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 100 - 50;
        cout << a[i] << " ";
    }
    cout << endl;

    // 2. Удаляем элемент K (сдвигаем элементы влево)
    for (int i = K; i < N - 1; i++) {
        a[i] = a[i + 1];
    }
    int new_size = N - 1; // размер уменьшился на 1

    // 3. Подсчет четных чисел (чтобы знать размер нового массива)
    int count = 0;
    for (int i = 0; i < new_size; i++) {
        if (a[i] % 2 == 0) 
        count++;
    }

    // 4. Создаем массив b (побольше) и копируем туда данные с нулями
    int* b = new int[new_size + count];
    int j = 0; // счетчик для массива b

    for (int i = 0; i < new_size; i++) {
        b[j] = a[i]; // копируем элемент
        j++; // двигаемя дальше по массиву
        
        if (a[i] % 2 == 0) { // если число четное
            b[j] = 0; // добавляем ноль после него
            j++; // двигаемся дальше
        }
    }

    // 5. Выводим результат
    cout << "Итоговый массив: ";
    for (int i = 0; i < new_size + count; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    // 6. Чистим память
    delete[] a;
    delete[] b;

    return 0;
}