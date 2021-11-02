#include <iostream>
#include <cmath>

using namespace std;
int r, c, result;
int idx = 0;

void order(int row, int col, int size) { // 순서 정하기
    if(row == r && col == c) { // conquer
        result = idx;
        return;
    }

    // divide
    if((row <= r && r < row + size) && (col <= c && c < col + size)) {
        order(row, col, size/2);
        order(row, col + size/2, size/2);
        order(row + size/2, col, size/2);
        order(row + size/2, col + size/2, size/2);
    }
    else idx += size * size;
}

int main() {
    int n;
    cin >> n >> r >> c;

    int size = pow(2, n);
    order(0, 0, size); // 순서 정하기

    cout << result; // 해당 칸의 순서 출력하기
    return 0;
}