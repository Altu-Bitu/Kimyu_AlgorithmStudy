#include <iostream>

using namespace std;
const int N = 50, P = 9;

int score = 0, turn;
int order[P+1];  // 선수 출전 순서
bool check[P+1]; // 선수 출전 여부
int result[N+1][P+1];

int move(bool base[4], int hit) { // 주자 이동
    int m = 0;
    for(int i = 3; i >= 1; i--) {
        if(base[i]) { // 주자 있는 경우
            if(i + hit >= 4) m++; // 홈으로 들어오는 경우
            else base[i+hit] = base[i];
            base[i] = false;
        }
    }
    return m;
}

int baseball(int inning) { // (이닝별 점수 반환)
    int out = 0, s = 0;
    bool base[4] = { false, }; // 1 : 1루 / 2 : 2루 / 3 : 3루

    while(out < 3) { // 삼진 아웃 전까지
        int hit = result[inning][order[turn]];
        if(!hit) out++; // 아웃
        else {
            s += move(base, hit);  // 주자 이동
            if(hit == 4) s++;      // 홈런
            else base[hit] = true; // 안타 (1루타 / 2루타 / 3루타)
        }
        turn = turn == P ? 1 : turn+1; // 타순 변경
    }
    return s;
}

void backtracking(int cnt, int n) {
    if(cnt > P) { // 기저 조건: 선수 출전 순서 다 정해짐
        turn = 1;
        int temp = 0;
        for(int i = 1; i <= n; i++) // 경기 시작
            temp += baseball(i);
        score = max(score, temp);
        return;
    }

    if(cnt == 4) backtracking(cnt + 1, n); // (4번 선수 정해졌기 때문)
    else {
        for (int i = 1; i <= P; i++) { // i: 선수
            if (!check[i]) { // 출전하지 않은 선수 -> 출전
                order[cnt] = i;
                check[i] = true;
                backtracking(cnt + 1, n);
                check[i] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    order[4] = 1; // 4번 타자 == 1번 선수
    check[1] = true; // (1번 선수 순서 결정 완료)

    for(int i = 1; i <= n; i++) { // (i : 이닝)
        for(int j = 1; j <= P; j++) // (j : 선수)
            cin >> result[i][j];
    }

    backtracking(1, n);
    cout << score;
    return 0;
}