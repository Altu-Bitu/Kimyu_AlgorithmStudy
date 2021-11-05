#include <iostream>
#include <vector>

using namespace std;
const int MAX_SIZE = 100;

int x, y;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1}; // 방향
bool board[MAX_SIZE+1][MAX_SIZE+1];

// 0세대 : 0
// 1세대 : 0 1                (0 -> 1)
// 2세대 : 0 1 2 1            (1 -> 2, 0 -> 1)
// 3세대 : 0 1 2 1 2 3 2 1    (1 -> 2, 2 -> 3, 0 -> 1)
void dragonCurve(vector<int> &dir) { // g세대 드래곤 커브 그리기
    int curve_size = dir.size();
    for(int i = curve_size-1; i >= 0; i--) {
        int d = (dir[i] + 1) % 4;
        x += dx[d];
        y += dy[d];
        board[y][x] = true;
        dir.push_back(d);
    }
}

int countDragonCurve() { // 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 정사각형 개수 구하기
    int count = 0;
    for(int i = 0; i <= MAX_SIZE; i++) {
        for(int j = 0; j <= MAX_SIZE; j++) {
            if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1])
                count++;
        }
    }
    return count;
}

int main() {
    int n, d, g;
    cin >> n;

    while(n--) {
        // 시작점, 시작 방향, 세대
        cin >> x >> y >> d >> g;

        // 0세대 드래곤 커브 (선분)
        board[y][x] = true;
        x += dx[d];
        y += dy[d];
        board[y][x] = true;

        vector<int> dir;
        dir.push_back(d);

        // 1~g세대 드래곤 커브 그리기
        while(g--) dragonCurve(dir);
    }

    cout << countDragonCurve();
    return 0;
}