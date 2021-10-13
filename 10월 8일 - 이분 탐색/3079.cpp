#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int n;
vector<int> t;

// 심사 시간이 mid일 때, 심사받을 수 있는 사람 수
ll pass(int mid) {
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        if(mid < t[i]) return cnt;
        cnt += (mid / t[i]);
    }
    return cnt;
}

ll minTime(ll left, ll right, int m) { // 최소 심사 시간 반환
    ll sec = right;

    while(left <= right) {
        ll mid = (left + right) / 2;
        ll cnt = pass(mid);

        if(cnt < m) left = mid + 1; // 모든 사람 통과하지 못함 -> 심사 시간 늘리기
        else if(cnt >= m) {         // 모든 사람 통과 -> 심사 시간 줄이기
            sec = mid;
            right = mid - 1;
        }
    }
    return sec;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m;
    cin >> n >> m;

    t.assign(n, 0);
    for(int i = 0 ; i < n; i++)
        cin >> t[i];
    sort(t.begin(), t.end());

    // left : 심사 소요 시간 최솟값 / right : 심사 소요 시간 최댓값
    cout << minTime(t[0], t[n-1] * m, m);
    return 0;
}