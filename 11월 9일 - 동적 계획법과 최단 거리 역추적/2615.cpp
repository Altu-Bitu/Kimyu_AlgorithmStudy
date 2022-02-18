#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 19;
typedef pair<int, int> ci;

// ����, ����, ������, ������
int dx[4] = {1, 0, -1, 1}, dy[4] = {0, 1, 1, 1};
bool finish = true; // �º� ���� ����
vector<ci> path; // �� ��ġ �����ϴ� ����
int board[SIZE][SIZE];
bool visited[SIZE][SIZE][4];

void dfs(int row, int col, int direction, vector<ci> &dp) {
    visited[row][col][direction] = true; // �湮 üũ
    dp.push_back({row, col}); // ��� ����

    int new_row = row + dy[direction];
    int new_col = col + dx[direction];

    // ���� ��尡 ���� ������ ���� ���
    if(new_row >= 0 && new_row < SIZE && new_col >= 0 && new_col < SIZE && board[row][col] == board[new_row][new_col])
        dfs(new_row, new_col, direction, dp);
}

void omok(queue<ci> &q) { // queue: ��� or ������ �� ��ġ
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) { // i: ����
            if(!visited[row][col][i]) { // �湮���� ���� ���
                vector<ci> dp;
                dfs(row, col, i, dp);
                if (dp.size() == 5) { // ���������� �ټ��� ���� ���
                    path = dp;
                    return;
                }
            }
        }
    }
    finish = false; // �º� �������� ����
}

int main() {
    queue<ci> q; // �� ��ġ �����ϴ� ť

    for(int i = 0; i < SIZE; i++) { // �ٵ��� �Է�
        for(int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
            if(board[i][j]) q.push({i, j}); // �� �߰�
        }
    }

    // ��� ���
    omok(q); // ���
    if(!finish) { // �º� �������� ���� ���
        cout << 0;
        return 0;
    }
    // ���� ���� �ٵϾ� ��ġ
    int row = path[0].first;
    int col = path[0].second;
    int win = board[row][col]; // �̱� �� ����

    cout << win << '\n';
    cout << row + 1 << ' ' << col + 1;
    return 0;
}