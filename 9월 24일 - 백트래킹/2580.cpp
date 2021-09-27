#include <iostream>

using namespace std;
const int SIZE = 9;

// (1차원: 행/열/정사각형 개수, 2차원: 숫자)
bool check_row[SIZE][SIZE+1], check_col[SIZE][SIZE+1], check_sub[SIZE][SIZE+1];
int sudoku[SIZE][SIZE]; // 스도쿠 저장하는 배열

int getSubNumber(int row, int col) { return (row/3)*3 + col/3; } // 몇번째 정사각형인가

void printSudoku() { // 완성된 스도쿠 출력
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }
}

void backtracking(int idx) {
    if(idx == SIZE*SIZE) {
        printSudoku();
        return;
    }

    int row = idx/SIZE, col = idx%SIZE;
    if(sudoku[row][col]) backtracking(idx+1);
    else { // 비어있는 칸 발견
        for(int i = 1; i <= SIZE; i++) {
            // 1. 행 검사  2. 열 검사  3. 정사각형 검사
            if(!check_row[row][i] && !check_col[col][i] && !check_sub[getSubNumber(row, col)][i]) {
                check_row[row][i] = true;
                check_col[col][i] = true;
                check_sub[getSubNumber(row, col)][i] = true;
                sudoku[row][col] = i; // 비어있는 칸에 숫자 삽입

                backtracking(idx+1);

                // 원상 복구
                check_row[row][i] = false;
                check_col[col][i] = false;
                check_sub[getSubNumber(row, col)][i] = false;
                sudoku[row][col] = 0;
            }
        }
    }
}

int main() {

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cin >> sudoku[i][j];

            if(sudoku[i][j]) { // visited
                check_row[i][sudoku[i][j]] = true;
                check_col[i][sudoku[i][j]] = true;
                check_sub[getSubNumber(i, j)][sudoku[i][j]] = true;
            }
        }
    }

    backtracking(0);
    return 0;
}