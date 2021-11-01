#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> cor;
int w, h;
// 상, 하, 좌, 우, 좌하향, 좌상향, 우하향, 우상향
int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1}, dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

vector<vector<int>> i_map;
vector<vector<bool>> visited;

void dfs(int row, int col) {
    visited[row][col] = true;

    for(int i = 0; i < 8; i++) {
        int new_row = row + dy[i];
        int new_col = col + dx[i];
        
        // 경계 조건을 만족하고 방문하지 않은 땅인 경우
        if(new_row >= 0 && new_row < h && new_col >= 0 && new_col < w && i_map[new_row][new_col] && !visited[new_row][new_col])
            dfs(new_row, new_col);
    }
}

int countIsland(queue<cor> q) {
    int cnt = 0;

    while(!q.empty()) {
        if(visited[q.front().first][q.front().second]) { q.pop(); continue; } // 이미 방문한 좌표인 경우
        dfs(q.front().first, q.front().second);
        cnt++;
    }
    return cnt;
}

int main() {

    while(true) {
        cin >> w >> h;
        if(!w && !h) break;

        queue<cor> q;
        i_map.assign(h, vector<int>(w, 0));
        visited.assign(h, vector<bool>(w, false));
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> i_map[i][j];
                if(i_map[i][j]) q.push({i, j}); // 땅 push
            }
        }
        cout << countIsland(q) << '\n';
    }

    return 0;
}