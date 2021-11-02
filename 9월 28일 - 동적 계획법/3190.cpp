#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 100;

int n;
int board[SIZE+1][SIZE+1]; // (사과 : 1 / 뱀 : 2)
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; // (상 좌 하 우)
char change[SIZE*SIZE+1];
queue<pair<int, int>> snake;

int changeDirection(int time, int dir) {
    if(change[time] == 'L') return (dir+1) % 4;
    if(change[time] == 'D') return (dir-1 < 0 ? 3 : dir-1) % 4;
    return dir;
}

int dummyGame() {
    int time = 0, row, col, dir = 3;

    snake.push({1, 1}); // 초기 위치
    while(true) {
        time++;

        row = snake.back().first + dy[dir]; // 몸 (back)
        col = snake.back().second + dx[dir];
        if(row < 1 || row > n || col < 1 || col > n || board[row][col] == 2) break; // 벽이나 자기 자신의 몸과 부딪히는 경우

        if(board[row][col] == 0) { // 사과 없음 -> 꼬리 줄이기
            board[snake.front().first][snake.front().second] = 0; // 꼬리 (front)
            snake.pop();
        }
        snake.push({row, col}); // 몸 PUSH
        board[row][col] = 2;
        dir = changeDirection(time, dir); // 방향 변환
    }
    return time;
}

int main() {
    int k, l, row, col, x;
    char c;

    cin >> n;
    cin >> k;

    while(k--) { // 사과 위치 입력
        cin >> row >> col;
        board[row][col] = 1;
    }

    cin >> l;
    while(l--) { // 방향 변환 정보 입력
        cin >> x >> c;
        change[x] = c;
    }

    cout << dummyGame();
    return 0;
}