#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, bool>> a; // 내구도, 로봇 여부

int countZero(int n) { // 내구도 0인 칸 세기
    int cnt = 0;
    for(int i = 1; i <= 2 * n; i++)
        if(a[i].first == 0) cnt++;
    return cnt;
}

void rotate(int &lift_pos, int &drop_pos, int n) { // 1. 한 칸 회전
    lift_pos = lift_pos <= 1 ? 2 * n : lift_pos - 1;
    drop_pos = drop_pos <= 1 ? 2 * n : drop_pos - 1;
    a[drop_pos].second = false; // 내리기 (로봇 삭제)
}

void move(int lift_pos, int drop_pos, int n) { // 2. 이동
    int pre = 0, now = drop_pos;
    while(pre != lift_pos) {
        pre = now <= 1 ? 2 * n : now - 1;
        // 로봇 이동 : 로봇 없음 && 내구도 남아있음 && 직전 칸 로봇 있음
        if(!a[now].second && a[now].first && a[pre].second) {
            a[now].second = true;
            a[pre].second = false;
            a[now].first--; // 내구도 삭제
        }
        now = now <= 1 ? 2 * n : now - 1;
    }
    a[drop_pos].second = false; // 내리기 (로봇 삭제)
}

void lift(int lift_pos) { // 3. 올리기
    if(a[lift_pos].first) {
        a[lift_pos].second = true;
        a[lift_pos].first--;
    }
}

int belt(int n, int k) {
    int level = 0, lift_pos = 1, drop_pos = n;
    while(countZero(n) < k) {
        level++;
        rotate(lift_pos, drop_pos, n); // 1. 한 칸 회전
        move(lift_pos, drop_pos, n); // 2. 이동
        lift(lift_pos); // 3. 올리기
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