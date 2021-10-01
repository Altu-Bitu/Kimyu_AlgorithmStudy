#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 100;

vector<pair<int, int>> cable; // (A 전깃줄 번호, B 전깃줄 번호)
int dp[SIZE+1]; // 증가 수열 저장하는 배열

int removeCable(int n) { // 없애야 하는 전깃줄 최소 개수 구하기
    int result = 0, start = cable[1].second; // (start: start 시점의 B 전깃줄 번호)
    dp[1] = 1;

    for(int i = 2; i <= n; i++) { // 케이블에서 증가 수열 찾기
        // 직전 케이블보다 작은 경우
        if(cable[i].second < cable[i-1].second && start < cable[i].second) dp[i] = dp[i-1]; // start 시점의 값보다는 큰 경우
        else if(cable[i].second < cable[i-1].second && start > cable[i].second) { // start 시점의 값보다 작은 경우
            dp[i] = 1;
            start = cable[i].second;
        }
        // 직전 케이블보다 큰 경우
        else dp[i] = dp[i-1] + 1;
        result = max(result, dp[i]);
    }
    return n - result;
}

int main() {
    int n;
    cin >> n;

    cable.assign(n+1, {0, 0});
    for(int i = 1; i <= n; i++)
        cin >> cable[i].first >> cable[i].second;
    sort(cable.begin()+1, cable.end());

    cout << removeCable(n);
    return 0;
}