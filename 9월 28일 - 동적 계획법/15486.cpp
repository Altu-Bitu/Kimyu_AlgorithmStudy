#include <iostream>

using namespace std;
const int SIZE = 1500000;

typedef struct consult{
    int time, pay; // 시간, 급여
}consult;
consult c[SIZE+1];
long long dp[SIZE+51];

long long maxProfit(int n) { // 최대 수익 구하기
    int day;
    for(int i = 1; i <= n; i++) {
        dp[i] = max(dp[i-1], dp[i]); // (금일까지의 수익은 전날까지의 수익보다 커야 함)
        day = i-1 + c[i].time;
        dp[day] = max(dp[day], dp[i-1] + c[i].pay);
    }
    return dp[n]; // n일까지의 최대 수익 반환
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> c[i].time >> c[i].pay;

    cout << maxProfit(n);
    return 0;
}