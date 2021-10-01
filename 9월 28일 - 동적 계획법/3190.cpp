#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 100;

int n;
bool apple[SIZE+1][SIZE+1], body[SIZE+1][SIZE+1];
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

        // 몸(back)
        row = snake.back().first + dy[dir];
        col = snake.back().second + dx[dir];
        if(row < 1 || row > n || col < 1 || col > n || body[row][col]) break; // 벽이나 자기 자신의 몸과 부딪히는 경우
        snake.push({row, col}); // 몸 PUSH
        body[row][col] = true;
        dir = changeDirection(time, dir); // 방향 변환

        // 꼬리 (front)
        if(apple[row][col]) apple[row][col] = false; // 사과 발견 -> 꼬리 그대로 & 사과 먹기
        else { // 사과 없음 -> 꼬리 줄이기
            body[snake.front().first][snake.front().second] = false;
            snake.pop();
        }
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
        apple[row][col] = true;
    }

    cin >> l;
    while(l--) { // 방향 변환 정보 입력
        cin >> x >> c;
        change[x] = c;
    }

    cout << dummyGame();
    return 0;
}