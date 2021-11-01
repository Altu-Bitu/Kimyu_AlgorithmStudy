#include <iostream>
#include <vector>

using namespace std;

int m, n;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}; // 상 하 좌 우
vector<vector<int>> s_map, dp;

int dfs(int row, int col) {
    if(row == m-1 && col == n-1) return 1; // 목적지 도착
    if(dp[row][col] != -1) return dp[row][col]; // 이미 dp값이 존재하는 경우 바로 리턴

    dp[row][col] = 0;
    for(int i = 0; i < 4; i++) {
        int new_row = row + dx[i];
        int new_col = col + dy[i];

        if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && s_map[new_row][new_col] < s_map[row][col])
            dp[row][col] += dfs(new_row, new_col); // 내리막길 찾아가기
    }
    return dp[row][col];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;
    s_map.assign(m, vector<int> (n, 0));
    dp.assign(m, vector<int> (n, -1));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cin >> s_map[i][j];
    }

    cout << dfs(0, 0);
    return 0;
}