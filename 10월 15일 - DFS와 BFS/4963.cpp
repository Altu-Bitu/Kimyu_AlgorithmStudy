#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> cor;
int w, h;
// 상, 하, 좌, 우, 좌하향, 좌상향, 우하향, 우상향
int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1}, dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

vector<vector<int>> i_map;

void dfs(int row, int col) {
    i_map[row][col] = 0; // 방문 체크

    for(int i = 0; i < 8; i++) {
        int new_row = row + dy[i];
        int new_col = col + dx[i];
        
        // 경계 조건을 만족하고 방문하지 않은 땅인 경우
        if(new_row >= 0 && new_row < h && new_col >= 0 && new_col < w && i_map[new_row][new_col])
            dfs(new_row, new_col);
    }
}

int main() {

    while(true) {
        cin >> w >> h;
        if(!w && !h) break;

        i_map.assign(h, vector<int>(w, 0));

        for(int i = 0; i < h; i++) // 지도 입력
            for(int j = 0; j < w; j++)
                cin >> i_map[i][j];

        int cnt = 0;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(i_map[i][j]) { cnt++; dfs(i, j); } // 땅
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}