#include <iostream>

using namespace std;
const int SIZE = 20;

int n, difference = 40000; // 인원 수, 능력치 차이 저장하는 변수
bool check[SIZE+1];    // 스타트팀 배정 여부 저장하는 배열
int s[SIZE+1][SIZE+1]; // 능력치 저장하는 배열

int computeSkillScore() { // 능력치 계산
    int start_skill = 0, link_skill = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(check[i] && check[j]) start_skill += s[i][j];
            else if(!check[i] && !check[j]) link_skill += s[i][j];
        }
    }
    return abs(start_skill - link_skill); // 능력치 차이 재설정
}

void backtracking(int idx) {
    if(idx == n) { // 기저 조건: idx 마지막 원소 도착
        difference = min(difference, computeSkillScore());
        return;
    }

    for(int i = idx; i <= n; i++) { // 팀 배정
        if(!check[i]) {
            check[i] = true;
            backtracking(i);
            check[i] = false; // 원상 복구
        }
    }
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) { // 능력치 입력
        for(int j = 1; j <= n; j++)
            cin >> s[i][j];
    }

    backtracking(1);
    cout << difference;
    return 0;
}