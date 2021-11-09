#include <iostream>
#include <map>

using namespace std;

int r_king, c_king, r_stone, c_stone;
// R L B T RT LT RB LB
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1}, dy[8] = {0, 0, 1, -1, -1, -1, 1, 1};
map<string, int> direction = {{"L", 1}, {"B", 2}, {"T", 3}, {"RT", 4},
                              {"LT", 5}, {"RB", 6}, {"LB", 7}};

// 체스판을 벗어나는가
bool isOut(int row, int col) { return (row < 0 || row >= 8 || col < 0 || col >= 8); }
// 체스말 위치 갱신
void renewPosition(int &row, int &col, int new_row, int new_col) { row = new_row; col = new_col; }

void move(string cmd) {
    int dir = direction[cmd];

    int new_r_king = r_king + dy[dir];
    int new_c_king = c_king + dx[dir];
    if(isOut(new_r_king, new_c_king)) return; // 체스판 벗어나는 경우

    if(new_r_king == r_stone && new_c_king == c_stone) { // 돌과 같은 곳에 위치하는 경우
        int new_r_stone = r_stone + dy[dir];
        int new_c_stone = c_stone + dx[dir];
        if(isOut(new_r_stone, new_c_stone)) return; // 체스판 벗어나는 경우
        renewPosition(r_stone, c_stone, new_r_stone, new_c_stone);
    }
    renewPosition(r_king, c_king, new_r_king, new_c_king);
}

int main() {
    string king, stone, d;
    int n;

    cin >> king >> stone >> n;
    c_king = king[0] - 'A'; r_king = '8' - king[1];
    c_stone = stone[0] - 'A'; r_stone = '8' - stone[1];

    for(int i = 0; i < n; i++) {
        cin >> d;
        move(d);
    }
    cout << (char)(c_king + 'A') << 8 - r_king << '\n';
    cout << (char) (c_stone + 'A') << 8 - r_stone;
    return 0;
}