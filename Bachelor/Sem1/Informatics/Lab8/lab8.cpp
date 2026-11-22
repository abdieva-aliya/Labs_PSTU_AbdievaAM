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
    FILE *f = fopen(filename, "ab"); 
    if (f == NULL) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    Abiturient a;
    cout << "ФИО: ";
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
    FILE *f = fopen(filename, "rb"); 
    if (f == NULL) {
        return;
    }

    Abiturient a;
    int i = 1;
    cout << "Список абитуриентов:" << endl;
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
    if (f == NULL) {
        return;
    }

    Abiturient arr[100]; 
    int count = 0; 
    while (fread(&arr[count], sizeof(Abiturient), 1, f) == 1) {
        count++;
    }
    fclose(f);

    f = fopen(filename, "wb"); 
    for (int i = 0; i < count; i++) {
        if (i != num - 1) {
            fwrite(&arr[i], sizeof(Abiturient), 1, f);
        }
    }
    fclose(f);
    cout << "Элемент удален." << endl;
}

// Функция добавления после заданной фамилии
void add_after_fio(const char* filename, const char* target) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        return;
    }

    Abiturient arr[100];
    int count = 0;
    while (fread(&arr[count], sizeof(Abiturient), 1, f) == 1) {
        count++;
    }
    fclose(f);

    // Ищем нужную фамилию
    int k = -1;
    for (int i = 0; i < count && k == -1; i++) {
        char temp[100];
        strcpy(temp, arr[i].fio);
        char* surname = strtok(temp, " ");
        
        if (surname != NULL && strcmp(surname, target) == 0) {
            k = i; 
        }
    }

    if (k == -1) {
        cout << "Фамилия не найдена!" << endl;
        return;
    }

    Abiturient new_a;
    cout << "Новое ФИО: ";
    cin.getline(new_a.fio, 100);
    cout << "Год: ";
    cin >> new_a.year;
    cout << "3 оценки: ";
    cin >> new_a.marks[0] >> new_a.marks[1] >> new_a.marks[2];
    new_a.sredniy = (new_a.marks[0] + new_a.marks[1] + new_a.marks[2]) / 3.0;

    f = fopen(filename, "wb");
    for (int i = 0; i < count; i++) {
        fwrite(&arr[i], sizeof(Abiturient), 1, f);
        if (i == k) {
            fwrite(&new_a, sizeof(Abiturient), 1, f); 
        }
    }
    fclose(f);
    cout << "Элемент добавлен." << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const char* file = "data.dat";

    FILE *f = fopen(file, "wb"); fclose(f);

    cin.ignore(); // Очищаем буфер перед первым вводом
    add(file);
    
    cin.ignore(); // Очищаем буфер перед вторым вводом
    add(file);
    
    print_file(file);

    int num;
    cout << "Введите номер элемента для удаления: ";
    cin >> num;
    delete_number(file, num);
    print_file(file);

    char target[100];
    cout << "Введите фамилию, после которой добавить: ";
    cin.ignore(); // Очищаем буфер после ввода числа
    cin.getline(target, 100);
    add_after_fio(file, target);
    
    print_file(file);

    return 0;
}