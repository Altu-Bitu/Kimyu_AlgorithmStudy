#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> consult; // time, pay 쌍

int getProfit(int day, int last) { // 최대 이익 구하기
    if(day >= last) return 0; // 기한 초과한 경우
    else if(day+ consult[day].first -1 >= last) return getProfit(day+1, last);

    int a = consult[day].second + getProfit(day + consult[day].first, last); // 오늘 일하는 경우
    int b = getProfit(day+1, last); // 오늘 일하지 않는 경우
    return max(a, b);
}

int main() {
    int n;
    cin >> n;

    consult.assign(n, {0, 0});
    for(int i = 0; i < n; i++)
        cin >> consult[i].first >> consult[i].second;
    cout << getProfit(0, n);
    return 0;
}