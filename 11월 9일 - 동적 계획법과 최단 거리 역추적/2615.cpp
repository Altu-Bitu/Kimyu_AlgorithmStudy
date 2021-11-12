#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 19;
typedef pair<int, int> ci;

// 우향, 하향, 좌하향, 우하향
int dx[4] = {1, 0, -1, 1}, dy[4] = {0, 1, 1, 1};
bool finish = true; // 승부 결정 여부
vector<ci> path; // 돌 위치 저장하는 벡터
int board[SIZE][SIZE];
bool visited[SIZE][SIZE][4];

void dfs(int row, int col, int direction, vector<ci> &dp) {
    visited[row][col][direction] = true; // 방문 체크
    dp.push_back({row, col}); // 경로 저장

    int new_row = row + dy[direction];
    int new_col = col + dx[direction];

    // 다음 노드가 같은 색상의 돌인 경우
    if(new_row >= 0 && new_row < SIZE && new_col >= 0 && new_col < SIZE && board[row][col] == board[new_row][new_col])
        dfs(new_row, new_col, direction, dp);
}

void omok(queue<ci> &q) { // queue: 흰색 or 검은색 돌 위치
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) { // i: 방향
            if(!visited[row][col][i]) { // 방문하지 않은 노드
                vector<ci> dp;
                dfs(row, col, i, dp);
                if (dp.size() == 5) { // 연속적으로 다섯알 놓인 경우
                    path = dp;
                    return;
                }
            }
        }
    }
    finish = false; // 승부 결정나지 않음
}

int main() {
    queue<ci> q; // 돌 위치 저장하는 큐

    for(int i = 0; i < SIZE; i++) { // 바둑판 입력
        for(int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
            if(board[i][j]) q.push({i, j}); // 돌 발견
        }
    }

    // 결과 출력
    omok(q); // 경로
    if(!finish) { // 승부 결정나지 않은 경우
        cout << 0;
        return 0;
    }
    // 가장 왼쪽 바둑알 위치
    int row = path[0].first;
    int col = path[0].second;
    int win = board[row][col]; // 이긴 돌 색상

    cout << win << '\n';
    cout << row + 1 << ' ' << col + 1;
    return 0;
}