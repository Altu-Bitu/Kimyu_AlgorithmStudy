#include <iostream>

using namespace std;
const int N = 100, K = 10000;

int coin[N+1];
int dp[K+1];  // 동전 가치에 해당하는 동전 개수

int countCoin(int n, int k) { // 동전 최소 개수 구하기
    for(int i = 1; i <= k; i++) // dp 초기화
        dp[i] = K+1;

    for(int j = 1; j <= n; j++) { // (j: 코인)
        // 코인 값이 최종 가치보다 작은 경우
        for(int i = coin[j]; i <= k; i++)
            dp[i] = min(dp[i], dp[i-coin[j]]+1);
    }
    return (dp[k] == K+1) ? -1 : dp[k];
}

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        cin >> coin[i];
    cout << countCoin(n, k);
    return 0;
}