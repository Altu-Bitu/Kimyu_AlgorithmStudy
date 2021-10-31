#include <iostream>
#include <vector>

using namespace std;

int n, m;
int max_num = 0;
vector<vector<int>> t, visited;

void backtracking(int row, int col, int sum, int len) { // 백트래킹
    if(len == 4) { // 정사각형 4개 이어붙인 경우
        max_num = max(max_num, sum);
        return;
    }

    int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}; // 상 하 좌 우
    for(int i = 0; i < 4; i++) {
        int new_row = row + dx[i];
        int new_col = col + dy[i];

        if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= m) continue; // 경계 넘어가는 경우
        if(visited[new_row][new_col]) continue; // 이미 방문한 경우

        visited[new_row][new_col] = true;
        backtracking(new_row, new_col, sum + t[new_row][new_col], len+1);
        visited[new_row][new_col] = false;
    }
}

void checkPink(int row, int col, int first) { // 핑크색 블록 모양 확인
    // 경계 설정
    bool r_boundary1 = (row + 1 < n), r_boundary2 = (row + 2 < n), r_boundary3 = (row - 1 >= 0);
    bool c_boundary1 = (col + 1 < m), c_boundary2 = (col + 2 < m), c_boundary3 = (col - 1 >= 0);

    int sum;
    if(r_boundary1 && c_boundary2) { // ㅜ 모양 (경계 벗어나지 않는 경우만)
        sum = first + t[row][col + 1] + t[row][col + 2] + t[row + 1][col + 1];
        max_num = max(max_num, sum);
    }
    if(r_boundary2 && c_boundary1) { // ㅏ 모양 (경계 벗어나지 않는 경우만)
        sum = first + t[row + 1][col] + t[row + 2][col] + t[row + 1][col + 1];
        max_num = max(max_num, sum);
    }
    if(r_boundary3 && c_boundary2) { // ㅗ 모양 (경계 벗어나지 않는 경우만)
        sum = first + t[row][col + 1] + t[row][col + 2] + t[row - 1][col + 1];
        max_num = max(max_num, sum);
    }
    if(r_boundary2 && c_boundary3) { // ㅓ 모양 (경계 벗어나지 않는 경우만)
        sum = first + t[row + 1][col] + t[row + 2][col] + t[row + 1][col - 1];
        max_num = max(max_num, sum);
    }
}

void findMax() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = true; // 시작 블록
            backtracking(i, j, t[i][j], 1);
            visited[i][j] = false;
            checkPink(i, j, t[i][j]); // 핑크색 블록 모양 확인
        }
    }
}

int main() {
    cin >> n >> m;

    t.assign(n, vector<int> (m, 0));
    visited.assign(n, vector<int> (m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> t[i][j];
    }

    findMax();
    cout << max_num;
    return 0;
}