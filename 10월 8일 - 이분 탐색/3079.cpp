#include <iostream>
#include <queue>

using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> t; // (first : 심사대 비는 시간 / second : 소요 시간)

int minTime(int m) { // 최소 심사 시간 반환
    int sec = 0, pass = 0;
    while(true) {
        sec++;
        while(!t.empty()) {
            if(t.top().first == sec) { // 심사대가 비어있는 경우
                pass++;
                if(pass == m) return sec; // 모두 통과한 경우 시간 반환
                t.push({sec + t.top().second, t.top().second}); t.pop();
            }
            else break; // 심사대가 비어있지 않은 경우
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, time;
    cin >> n >> m;

    for(int i = 0 ; i < n; i++) {
        cin >> time;
        t.push({time, time});
    }

    cout << minTime(m);
    return 0;
}