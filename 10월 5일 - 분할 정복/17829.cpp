#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1024;

int matrix[N][N]; // 행렬

int pulling(int row, int col) { // 2번째로 큰 수 반환
    int temp[4];
    int idx = 0;
    for(int i = row; i < row+2; i++) { // 2x2 부분
        for(int j = col; j < col+2; j++)
            temp[idx++] = matrix[i][j];
    }
    sort(temp, temp+4, greater<>()); // 내림차순 정렬
    return temp[1];
}

void cnn(int n) {
    if(n == 1) return; // conquer: 풀링 완료

    for(int i = 0; i < n; i+=2) {
        for(int j = 0; j < n; j+=2)
            matrix[i/2][j/2] = pulling(i, j);
    }
    cnn(n/=2); // divide
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    cnn(n);
    cout << matrix[0][0];
    return 0;
}
