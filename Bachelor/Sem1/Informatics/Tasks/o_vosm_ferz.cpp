#include <iostream>
#include <cstdlib>
#include <clocale>
using namespace std;

int pos[8];        
int count_res = 0; 
bool f = false; 
int saved[5][8];   

void draw() {
    for (int i = 0; i < 30; i++) {
        cout << endl;
    }
    cout << "  1 2 3 4 5 6 7 8" << endl;
    
    for (int i = 0; i < 8; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 8; j++) {
            if (pos[i] == j) {
                cout << "Q ";
            } else {
                bool f = false;
                for (int r = 0; r < 8; r++) {
                    if (pos[r] != -1) { 
                        if (pos[r] == j || r == i || abs(r - i) == abs(pos[r] - j)) {
                            f = true;
                        }
                    }
                }
                if (f) cout << "x ";
                else cout << ". ";
            }
        }
        cout << endl;
    }
    cout << "Нажмите Enter...";
    cin.get();
}

void print(int board[8]) {
    cout << "  1 2 3 4 5 6 7 8" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 8; j++) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (pos[i] == col || abs(i - row) == abs(pos[i] - col)) {
            return false;
        }
    }
    return true;
}

void solve(int row) {
    if (row == 8) {
        count_res++;
        if (count_res == 1) {
            f = true;
            draw(); 
        } else {
            if (count_res > 1 && count_res <= 6) {
            for (int i = 0; i < 8; i++) {
                saved[count_res - 2][i] = pos[i];
            }
        }
        }
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (safe(row, col)) {
            pos[row] = col; 
            if (!f && row < 7) draw(); 
            
            solve(row + 1); 
            
            if (!f && row > 0) {
                pos[row] = -1; 
                draw(); 
            } else {
                pos[row] = -1; 
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < 8; i++) {
        pos[i] = -1;
    }
    cout << "Нажмите Enter для старта...";
    cin.get();
    
    solve(0); 
    
    cout << "Еще 5 найденных решений" << endl;
    for (int k = 0; k < 5; k++) {
        cout << "Решение №" << k + 2 << ":" << endl;
        print(saved[k]);
    }
    
    cout << "Всего найдено решений: " << count_res << endl;
    return 0;
}