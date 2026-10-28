#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double a = 0.1; // Начало диапазона
    double b = 1.0;   // Конец диапазона
    int k = 10;       // Количество шагов
    double step = (b - a) / k; // Шаг (0.09)
    
    int n = 10;       // Заданное количество слагаемых
    double eps = 0.0001;  // Заданная точность
    
    double log_3 = log(3.0); // Заранее считаем логарифм тройки для формулы

    cout << "Вычисление функции y = 3^x" << endl;

    // Главный цикл: перебираем X от 0.1 до 1.0
    for (double x = a; x <= b + 0.000001; x = x + step) {

        // Считаем сумму SN
        double SN = 1.0;  // Начальная сумма
        double mn = 1.0; // Текущее слагаемое
        
        // Крутим цикл ровно 10 раз
        for (int i = 1; i <= n; i++) {
            // Вычисляем новое слагаемое по рекуррентной формуле
            mn = mn * (x * log_3) / i;
            // Добавляем его к сумме
            SN = SN + mn;
        }

        // Считаем сумму SE (с точностью eps)
        double SE = 1.0;      // Начальная сумма
        double me = 1.0; // Текущее слагаемое
        int j = 1;            // Счетчик
        
        // Крутим цикл, пока слагаемое не станет меньше eps
        while (abs(me) >= eps) {
            me = me * (x * log_3) / j;
            SE = SE + me;
            j = j + 1;
        }

        // Считаем точное значение Y
        double Y = pow(3.0, x);

        cout << "X=" << x << "  SN=" << SN << "  SE=" << SE << "  Y=" << Y << endl;
    }

    return 0;
}