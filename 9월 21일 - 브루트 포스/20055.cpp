#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, bool>> a; // 내구도, 로봇 여부

int countZero(int n) { // 내구도 0인 칸 세기
    int cnt = 0;
    for(int i = 1; i <= 2*n; i++)
        if(a[i].first == 0) cnt++;
    return cnt;
}

void rotate(int n) { // 1. 한 칸 회전
    a[0] = a[2*n];
    for(int i = 2*n-1; i >= 1; i--) // 한 칸씩 이동
        a[i+1] = a[i];
    a[1] = a[0];
    a[n].second = false; // 내리기 (로봇 삭제)
}

void move(int n) { // 2. 이동
    for(int i = n; i >= 2; i--) {
        // 로봇 없음 && 내구도 남아있음 && 직전 칸 로봇 있음
        if(!a[i].second && a[i].first && a[i-1].second) {
            // 로봇 이동
            a[i].second = true;
            a[i-1].second = false;
            a[i].first--; // 내구도 삭제
        }
    }
    a[n].second = false; // 내리기 (로봇 삭제)
}

void lift() { // 3. 올리기
    if(a[1].first) {
        a[1].second = true;
        a[1].first--;
    }
}

int belt(int n, int k) {
    int level = 0;

    while(countZero(n) < k) {
        level++;
        rotate(n); // 1. 한 칸 회전
        move(n); // 2. 이동
        lift(); // 3. 올리기
    }
    return level;
}

int main() {
    int n, k;
    cin >> n >> k;

    a.assign(2*n+1, {0, false});
    for(int i = 1; i <= 2*n; i++)
        cin >> a[i].first;
    cout << belt(n, k); // 단계 출력
    return 0;
}