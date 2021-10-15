#include <iostream>
#include <vector>

using namespace std;

// 도둑이 붙잡하지 않고 m개의 집을 고르는 방법 수 (슬라이딩 윈도우)
int steal(vector<int> house, int n, int m, int k) {
    int cnt =0, money = 0;

    for(int i = 0; i < m; i++)
        money += house[i];
    if(money < k) cnt++;

    if(n == m) return cnt; // (다른 경우 없음)

    for(int i = 1; i < n; i++) {
        money -= house[i-1];
        money += house[(i-1+m) % n];
        if(money < k) cnt++;
    }
    return cnt;
}

int main() {
    int t, n, m, k;
    cin >> t;

    while(t--) {
        cin >> n >> m >> k;

        vector<int> house (n, 0);
        for(int i = 0; i < n; i++)
            cin >> house[i];
        cout << steal(house, n, m, k) << '\n';
    }
    return 0;
}