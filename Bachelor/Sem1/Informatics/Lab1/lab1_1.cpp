#include <iostream> //операторы для ввода и вывода данных
#include <cmath> //аналог math.h
#include <locale> //локализация

using namespace std; //для использования без префикса

int main() {
    setlocale(LC_ALL, ".65001"); //подключение кириллицы
    
    // решение для float
    float a_f = 1000.0f; // a
    float b_f = 0.0001f; // b
    float sum_f = a_f + b_f; // a + b
    float sq_f = pow(sum_f, 2.0f); // (a + b)^2
    float a_sq_f = pow(a_f, 2.0f); // a^2
    float ab_f = 2.0f * a_f * b_f; // 2ab
    float num_f = sq_f - (a_sq_f + ab_f); 
    float den_f = pow(b_f, 2.0f); // b^2
    float res_f = num_f / den_f;
    cout << "a + b = " << sum_f << endl;
    cout << "(a + b)^2 = " << sq_f << endl;
    cout << "a^2 = " << a_sq_f << endl;
    cout << "2ab = " << ab_f << endl;
    cout << "Числитель = " << num_f << endl;
    cout << "Знаменатель = " << den_f << endl;
    cout << "Результат float: " << res_f << endl; //вывод

    // решение для double
    double a_d = 1000.0;
    double b_d = 0.0001;
    double sum_d = a_d + b_d;
    double sq_d = pow(sum_d, 2.0);
    double a_sq_d = pow(a_d, 2.0);
    double ab_d = 2.0 * a_d * b_d;
    double num_d = sq_d - (a_sq_d + ab_d);
    double den_d = pow(b_d, 2.0);
    double res_d = num_d / den_d;
    cout << "a + b = " << sum_d << endl;
    cout << "(a + b)^2 = " << sq_d << endl;
    cout << "a^2 = " << a_sq_d << endl;
    cout << "2ab = " << ab_d << endl;
    cout << "Числитель = " << num_d << endl;
    cout << "Знаменатель = " << den_d << endl;
    cout << "Результат double: " << res_d << endl; //вывод

    return 0; //для успешного завершения
}

//Результат float: 6.25e+06
//Результат double: 1.00117

/*Причина расхождения результатов - потеря точности.
Тип float хранит только 7 значащих цифр. Числа в вычислениях имеют порядок 10⁶, поэтому дробная часть не помещается в разрядную сетку и теряется.
Это приводит к катастрофической потере точности — итог далёк от 1.
Тип double хранит 15 значащих цифр, чего достаточно, чтобы сохранить дробную часть чисел порядка 10⁶.
Поэтому вычитание близких чисел проходит корректно, и результат близок к математически правильному 1.
Небольшое отклонение (1.00117) объясняется погрешностью функции pow.*/