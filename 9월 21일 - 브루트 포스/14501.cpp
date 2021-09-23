#include <iostream>
#include <vector>

using namespace std;
vector<int> t, p;

int getProfit(int day, int last) { // 최대 이익 구하기
    if(day >= last || day+ t[day] -1 >= last) return 0; // 기한 초과한 경우

    int a = p[day] + getProfit(day + t[day], last); // 오늘 일하는 경우
    int b = getProfit(day+1, last); // 오늘 일하지 않는 경우
    return a >= b ? a : b;
}

int main() {
    int n;
    cin >> n;

    t.assign(n, 0);
    p.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> t[i] >> p[i];
    cout << getProfit(0, n);
    return 0;
}