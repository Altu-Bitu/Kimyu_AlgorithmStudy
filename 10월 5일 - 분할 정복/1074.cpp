#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int idx = 0; // 순서 저장하는 변수
vector<vector<int>> arr;

void order(int row, int col, int size) { // 순서 정하기
    if(size == 2) { // conquer
        for(int i = row; i < row + 2; i++) {
            for(int j = col; j < col + 2; j++) {
                arr[i][j] = idx++;
            }
        }
        return;
    }

    // divide (z모양 순서대로)
    order(row, col, size/2);
    order(row, col + size/2, size/2);
    order(row + size/2, col, size/2);
    order(row + size/2, col + size/2, size/2);
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    int size = pow(2, n);
    arr.assign(size, vector<int>(size, 0));
    order(0, 0, size); // 순서 정하기

    cout << arr[r][c]; // 해당 칸의 순서 출력하기
    return 0;
}