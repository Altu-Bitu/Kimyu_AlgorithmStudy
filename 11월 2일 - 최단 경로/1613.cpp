#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> event;

void setRelation(int n) { // (플로이드-워셜 알고리즘 이용하여 순서 세팅)
    for(int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(event[i][k] == -1 && event[k][j] == -1) { // i -> k -> j
                    event[i][j] = -1; // 앞순서
                    event[j][i] = 1;  // 뒷순서
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, s, pre, next;
    cin >> n >> k;

    event.assign(n+1, vector<int> (n+1, 0)); // 유추 불가 상태로 초기화
    while(k--) { // 사건 순서 입력
        cin >> pre >> next;
        event[pre][next] = -1; // 앞순서
        event[next][pre] = 1;  // 뒷순서
    }
    setRelation(n);

    cin >> s;
    while(s--) {
        cin >> pre >> next;
        cout << event[pre][next] << '\n';
    }
    return 0;
}