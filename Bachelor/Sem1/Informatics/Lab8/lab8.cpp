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

// Функция добавления новой записи в конец файла
void add(const char* filename) {
    FILE *f = fopen(filename, "ab"); // "ab" - добавить в конец бинарного файла
    if (f == NULL) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    Abiturient a;
    cout << "ФИО: ";
    cin.ignore();
    cin.getline(a.fio, 100);
    cout << "Год рождения: ";
    cin >> a.year;
    cout << "3 оценки: ";
    cin >> a.marks[0] >> a.marks[1] >> a.marks[2];
    a.sredniy = (a.marks[0] + a.marks[1] + a.marks[2]) / 3.0;

    fwrite(&a, sizeof(Abiturient), 1, f); // Записываем структуру в файл
    fclose(f);
    cout << "Запись добавлена." << endl;
}

// Функция печати всего файла
void print_file(const char* filename) {
    FILE *f = fopen(filename, "rb"); // "rb" - читать бинарный файл
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

// Функция удаления по номеру
void delete_number(const char* filename, int num) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) return;

    Abiturient arr[100]; // Массив для временного хранения всех записей
    int count = 0; // Сколько прочитали
    
    while (fread(&arr[count], sizeof(Abiturient), 1, f) == 1) {
        count++;
    }
    fclose(f);

    // Перезаписываем файл заново (wb очищает старый файл)
    f = fopen(filename, "wb"); 
    for (int i = 0; i < count; i++) {
        if (i != num - 1) { // Пропускаем удаляемый элемент
            fwrite(&arr[i], sizeof(Abiturient), 1, f);
        }
    }
    fclose(f);
    cout << "Элемент удален." << endl;
}

// Функция добавления после заданной фамилии
void add_after_fio(const char* filename, const char* target) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) return;

    Abiturient arr[100];
    int count = 0;
    
    // Читаем файл в массив
    while (fread(&arr[count], sizeof(Abiturient), 1, f) == 1) {
        count++;
    }
    fclose(f);

    // Ищем нужную фамилию
    int k = -1;
    for (int i = 0; i < count && k == -1; i++) {
        // Копируем ФИО, чтобы не испортить оригинал
        char temp[100];
        strcpy(temp, arr[i].fio);
        
        // Отрезаем фамилию (до первого пробела)
        char* surname = strtok(temp, " ");
        
        // Сравниваем только фамилию
        if (surname != NULL && strcmp(surname, target) == 0) {
            k = i; // Запоминаем индекс
        }
    }

    if (k == -1) {
        cout << "Фамилия не найдена!" << endl;
        return;
    }

    Abiturient new_a;
    cout << "Новое ФИО: ";
    cin.ignore();
    cin.getline(new_a.fio, 100);
    cout << "Год: ";
    cin >> new_a.year;
    cout << "3 оценки: ";
    cin >> new_a.marks[0] >> new_a.marks[1] >> new_a.marks[2];
    new_a.sredniy = (new_a.marks[0] + new_a.marks[1] + new_a.marks[2]) / 3.0;

    // Перезаписываем файл со вставкой
    f = fopen(filename, "wb");
    for (int i = 0; i < count; i++) {
        fwrite(&arr[i], sizeof(Abiturient), 1, f);
        if (i == k) { // Вставляем сразу после найденной фамилии
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

    add(file);
    add(file);
    print_file(file);

    int num;
    cout << "Введите номер элемента для удаления: ";
    cin >> num;
    delete_number(file, num);
    print_file(file);

    char target[100];
    cout << "Введите фамилию, после которой добавить: ";
    cin.ignore(); // Очищаем буфер после ввода номера
    cin.getline(target, 100);
    add_after_fio(file, target);
    print_file(file);

    return 0;
}