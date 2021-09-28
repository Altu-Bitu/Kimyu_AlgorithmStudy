#include <iostream>

using namespace std;
const int SIZE = 9;

bool complete = false; // 스도쿠 판 채울 수 있는지 저장하는 변수
int count = 0; // 비어있는 칸 개수 저장
pair<int, int> blank[SIZE*SIZE]; // 비어있는 칸의 행, 열 번호 저장하는 배열
int sudoku[SIZE][SIZE]; // 스도쿠 저장하는 배열

void printSudoku() { // 완성된 스도쿠 출력
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }
}

bool possible(int row, int col) {
    int row_range = 3 * (row/3), col_range = 3 * (col/3);

    for(int i = 0; i < SIZE; i++) {
        // 1. 행 검사 (열 위치 다르면서 값 같은 경우)
        if(sudoku[row][i] == sudoku[row][col] && i != col) return false;
        // 2. 열 검사 (행 위치 다르면서 값 같은 경우)
        if(sudoku[i][col] == sudoku[row][col] && i != row) return false;
    }

    for(int i = row_range; i < row_range+3; i++) {
        for(int j = col_range; j < col_range+3; j++) {
            // 3. 3x3 정사각형 검사 (위치 다르면서 값 같은 경우)
            if(sudoku[i][j] == sudoku[row][col] && i != row && j != col) return false;
        }
    }
    return true;
}

void backtracking(int cnt) {

    if(cnt == count) {
        printSudoku();
        complete = true;
        return;
    }

    int row = blank[cnt].first, col = blank[cnt].second;
    for(int i = 1; i <= SIZE; i++) {
        sudoku[row][col] = i;
        if(possible(row, col)) backtracking(cnt+1);
        if(complete) return;
    }
    sudoku[row][col] = 0; // 원상 복구
}

int main() {

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cin >> sudoku[i][j];
            if(!sudoku[i][j]) blank[count++] = {i, j};
        }
    }
    backtracking(0);
    return 0;
}