#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Введите " << n << " элементов массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int del_num;
    cout << "Введите номер элемента для удаления: ";
    cin >> del_num;
    
    int del_ind = del_num - 1;
    for (int i = del_ind; i < n - 1; i++) {
        arr[i] = arr[i + 1]; // Сдвигаем элементы влево
    }
    n--; // Уменьшаем размер

    cout << "После удаления: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int add_num, new_n;
    cout << "Введите номер для вставки нового элемента: ";
    cin >> add_num;
    cout << "Введите значение нового элемента: ";
    cin >> new_n;

    int add_ind = add_num - 1;
    for (int i = n; i > add_ind; i--) {
        arr[i] = arr[i - 1]; // Сдвигаем элементы вправо
    }
    arr[add_ind] = new_n; // Вставляем новый элемент
    n++; // Увеличиваем размер

    cout << "После добавления: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}