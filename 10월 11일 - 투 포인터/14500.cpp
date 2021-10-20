#include <iostream>
#include <vector>

using namespace std;

int n, m;
int max_num = 0;
vector<vector<int>> t, visited;

void dfs(int row, int col, int sum, int len) {
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
        dfs(new_row, new_col, sum + t[new_row][new_col], len+1);
        visited[new_row][new_col] = false;
    }
}

int findMax() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = true;
            dfs(i, j, t[i][j], 1);
            visited[i][j] = false;
        }
    }
    return max_num;
}

int main() {
    cin >> n >> m;

    t.assign(n, vector<int> (m, 0));
    visited.assign(n, vector<int> (m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> t[i][j];
    }
    cout << findMax();
    return 0;
}