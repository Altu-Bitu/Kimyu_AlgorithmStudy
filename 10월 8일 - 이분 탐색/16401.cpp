#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> l;

// 과자 길이가 len일 때, 나눠줄 수 있는 조카 수
int divide(int len) {
    int nephew = 0;
    for(int i = 0; i < n; i++) {
        if(l[i] < len) return nephew; // 사용할 수 없는 과자
        nephew += (l[i] / len);
    }
    return nephew;
}

// 막대 과자 최대 길이 반환
int cookie(int left, int right, int m) {
    int len = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int nephew = divide(mid); // 과자 길이가 mid 나눠줄 수 있는 조카 수

        if(nephew < m) right = mid - 1; // 모든 조카에게 나눠줄 수 없음 -> 과자 길이 줄이기
        else if(nephew >= m) { // 모든 조카에게 나눠줄 수 있음 -> 길이 늘리기
            len = mid;
            left = mid + 1;
        }
    }
    return len;
}

int main() {
    int m;
    cin >> m >> n;

    l.assign(n, 0);
    for(int i = 0; i <n; i++)
        cin >> l[i];
    sort(l.begin(), l.end(), greater<>()); // 내림차순 정렬

    // left : 쿠키 최소 길이 / right: 쿠키 최고 길이
    cout << cookie(1, l[0], m);
    return 0;
}