#include <iostream>

using namespace std;
const int N = 1000;

int cost[N+1][3];
int dp[N+1][3];

int minCost(int n, int color) { // (color: 1번째 집 색상)
    int min_cost = N*N+1;

    // 같은 색상 연달아 나오지 않도록
    for(int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }
    // n번째 집
    for(int i = 0; i < 3; i++)
        if(i != color) min_cost = min(min_cost, dp[n][i]); // 1번 집 색상과 겹치지 않는 경우
    return min_cost;
}

int main() {
    int n, result = N*N+1;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    for(int i = 0; i < 3; i++) { // i: 1번째 집 색상
        for(int j = 0; j < 3; j++) {
            if(i == j) dp[1][j] = cost[1][j];
            else dp[1][j] = N*N+1;
        }
        result = min(result, minCost(n, i)); // (1번째 집이 i 색상일 때 최솟값)
    }
    cout << result;
    return 0;
}