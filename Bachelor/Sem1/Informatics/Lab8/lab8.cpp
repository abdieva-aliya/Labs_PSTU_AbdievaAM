#include <iostream>
#include <cstdio>
#include <cstring>
#include <clocale>
using namespace std;

struct Abiturient {
    char fio[100];
    int year;
    int marks[3];
    double sredniy;
};

// 1. Функция добавления новой записи в конец файла
void add(const char* filename) {
    // Открываем файл в режиме "ab" (append binary) - добавление в конец бинарного файла
    FILE *f = fopen(filename, "ab"); 
    if (f == NULL) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    Abiturient a;
    cout << "ФИО: ";
    cin.ignore(); // Очищаем буфер от Enter, оставшегося после предыдущего ввода
    cin.getline(a.fio, 100); // Считываем строку с пробелами
    cout << "Год рождения: ";
    cin >> a.year;
    cout << "3 оценки: ";
    cin >> a.marks[0] >> a.marks[1] >> a.marks[2];
    a.sredniy = (a.marks[0] + a.marks[1] + a.marks[2]) / 3.0;

    // Записываем одну структуру в файл (адрес структуры, размер, кол-во, файл)
    fwrite(&a, sizeof(Abiturient), 1, f); 
    fclose(f); // Закрываем файл
    cout << "Запись добавлена." << endl;
}

// 2. Функция печати всего файла
void print_file(const char* filename) {
    // Открываем файл в режиме "rb" (read binary) - чтение бинарного файла
    FILE *f = fopen(filename, "rb"); 
    if (f == NULL) {
        cout << "Файл не найден!" << endl;
        return;
    }

    Abiturient a;
    int i = 1;
    cout << "Список абитуриентов:" << endl;
    
    // Читаем по одной структуре, пока fread возвращает 1
    while (fread(&a, sizeof(Abiturient), 1, f) == 1) { 
        cout << i++ << ". " << a.fio << " | Год: " << a.year 
             << " | Оценки: " << a.marks[0] << " " << a.marks[1] << " " << a.marks[2] 
             << " | Ср.балл: " << a.sredniy << endl;
    }
    fclose(f);
}

// 3. Функция удаления по номеру
void delete_number(const char* filename, int num) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) return;

    Abiturient arr[100]; // Временный массив для хранения всех записей
    int count = 0; // Количество прочитанных записей
    
    // Читаем весь файл в массив
    while (fread(&arr[count], sizeof(Abiturient), 1, f) == 1) {
        count++;
    }
    fclose(f);

    // Открываем файл заново в режиме "wb" (write binary) - полностью очищает файл
    f = fopen(filename, "wb"); 
    
    // Записываем обратно все элементы, кроме удаляемого
    for (int i = 0; i < count; i++) {
        if (i != num - 1) {
            fwrite(&arr[i], sizeof(Abiturient), 1, f);
        }
    }
    fclose(f);
    cout << "Элемент удален." << endl;
}

// 4. Функция добавления после заданной фамилии
void add_after_fio(const char* filename, const char* target) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) return;

    Abiturient arr[100];
    int count = 0;
    
    // Снова читаем весь файл в массив
    while (fread(&arr[count], sizeof(Abiturient), 1, f) == 1) {
        count++;
    }
    fclose(f);

    // Ищем индекс элемента с нужной фамилией
    int k = -1;
    for (int i = 0; i < count && k == -1; i++) {
        if (strcmp(arr[i].fio, target) == 0) {
            k = i; // Запоминаем позицию
        }
    }

    if (k == -1) {
        cout << "Фамилия не найдена!" << endl;
        return;
    }

    // Ввод данных нового абитуриента
    Abiturient new_a;
    cout << "Новое ФИО: ";
    cin.ignore();
    cin.getline(new_a.fio, 100);
    cout << "Год: ";
    cin >> new_a.year;
    cout << "3 оценки: ";
    cin >> new_a.marks[0] >> new_a.marks[1] >> new_a.marks[2];
    new_a.sredniy = (new_a.marks[0] + new_a.marks[1] + new_a.marks[2]) / 3.0;

    // Перезаписываем файл
    f = fopen(filename, "wb");
    for (int i = 0; i < count; i++) {
        fwrite(&arr[i], sizeof(Abiturient), 1, f); // Пишем текущий элемент
        
        if (i == k) {
            // Если это тот самый элемент, после которого нужно вставить, сразу же пишем нового абитуриента
            fwrite(&new_a, sizeof(Abiturient), 1, f); 
        }
    }
    fclose(f);
    cout << "Элемент добавлен." << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const char* file = "data.dat";

    // Создаем пустой файл
    FILE *f = fopen(file, "wb"); 
    fclose(f);

    // Добавление записей
    add(file); 
    add(file);
    print_file(file); // Выводим то, что получилось

    // Удаление 1-го элемента
    delete_number(file, 1); // Удаляем первую запись
    print_file(file);

    // Добавление после фамилии
    add_after_fio(file, "Петров Юрий Савельевич"); // Ищем ... и вставляем после него
    print_file(file);

    return 0;
}