#include <iostream>
#include <clocale>
using namespace std;

int main(){
    setlocale(LC_ALL, ".65001");

    int x, y;
    
    cout << "Введите количество строк и столбцов: ";
    cin >> x >> y;
    
    int a[100][100];
    int t[100][100];

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            t[j][i] = a[i][j];
        }
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    for(int i = 0; i < n; i++){
        delete[] t[i];
    }
    delete[] t;
    return 0;

}