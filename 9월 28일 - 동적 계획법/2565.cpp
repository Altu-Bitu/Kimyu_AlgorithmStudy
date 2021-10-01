#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 100;

vector<pair<int, int>> cable; // (A 전깃줄 번호, B 전깃줄 번호)
int dp[SIZE+1]; // (해당 인덱스까지 증가 수열 길이 저장)

int removeCable(int n) { // 없애야 하는 전깃줄 최소 개수 구하기
    int inc = 1; // 증가 수열 최대 길이 저장하는 변수

    dp[1] = 1;
    for(int i = 2; i <= n; i++) { // 케이블에서 증가 수열 찾기
        int temp = 1;
        for(int j = 1; j < i; j++)
            if(cable[j].second < cable[i].second) temp = max(temp, dp[j] + 1);
        dp[i] = temp;
        inc = max(inc, dp[i]);
    }
    return n - inc;
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