#include <iostream>
#include <cstdlib>
#include <clocale>
using namespace std;

int pos[8]; // Номер столбца для ферзя в строке i
int count_res = 0; // Счетчик решений
int first_pos[8]; // Массив для сохранения первого найденного решения

// Функция проверки: бьет ли новый ферзь уже стоящих
bool safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Проверка столбца и диагоналей
        if (pos[i] == col || abs(i - row) == abs(pos[i] - col)) {
            return false;
        }
    }
    return true;
}

// Расстановка
void solve(int row) {
    // Если дошли до 8-й строки — нашли решение
    if (row == 8) {
        count_res++;
        
        // Сохраняем первое решение
        if (count_res == 1) {
            for (int i = 0; i < 8; i++) {
                first_pos[i] = pos[i];
            }
        }
        return;
    }

    // Пробуем поставить ферзя в каждый столбец текущей строки
    for (int col = 0; col < 8; col++) {
        if (safe(row, col)) {
            pos[row] = col; // Ставим ферзя
            solve(row + 1); // Переходим к следующей строке
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    solve(0); // Запускаем алгоритм с 0-й строки
    
    cout << "Всего найдено решений: " << count_res << "\n\n";
    
    // Визуализация первого решения
    cout << "  1 2 3 4 5 6 7 8"; // Номера столбцов
    for (int i = 0; i < 8; i++) {
        cout << i + 1 << " "; // Номер строки
        for (int j = 0; j < 8; j++) {
            if (first_pos[i] == j) cout << "Q ";
            else cout << ". ";
        }
        cout << "\n";
    }

    return 0;
}