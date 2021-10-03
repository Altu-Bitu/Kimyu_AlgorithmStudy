#include <iostream>
#include <vector>

using namespace std;
vector<vector<vector<int>>> matrix; // (0 : A 행렬 / 1 : B 행렬)

bool change(int row, int col, int n, int m) { // 행렬 바꿀 수 있는가
    if(row >= n-2 || col >= m-2) return false;
    // 행렬 바꾸기
    for(int i = row; i < row+3; i++) {
        for(int j = col; j < col+3; j++)
            matrix[0][i][j] = !matrix[0][i][j]; // 원소 뒤집기
    }
    return true;
}

int countChange(int n, int m) { // 행렬 바꾸는 횟수 세기
    int result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[0][i][j] != matrix[1][i][j]) {
                if(!change(i, j, n, m)) return -1; // B와 같아질 수 없는 경우
                result++;
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    string input;
    cin >> n >> m;

    matrix.assign(2, vector<vector<int>> (n, vector<int> (m, 0)));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> input;
            for(int k = 0; k < m; k++)
                matrix[i][j][k] = input[k]-'0';
        }
    }

    cout << countChange(n, m);
    return 0;
}