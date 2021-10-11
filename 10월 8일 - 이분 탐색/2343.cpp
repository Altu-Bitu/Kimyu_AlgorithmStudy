#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> lecture;

// 블루레이 길이가 len일 때, 블루레이 개수
int divide(int len) {
    int cnt = 1, sum = lecture[0]; // 첫번째 블루레이 카운트

    for(int i = 1; i < n; i++) {
        sum += lecture[i];
        if(sum > len) { cnt++; sum = lecture[i]; }
    }
    return cnt;
}

// 블루레이 최소 길이 반환
int bluelay(int left, int right, int m) {
    int len = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int tmp = divide(mid); // 길이가 mid일 때 블루레이 개수

        if(tmp > m) left = mid + 1; // 블루레이 개수 초과 -> 길이 늘리기
        else if(tmp <= m) { // 블루레이 개수 만족 -> 길이 줄이기
            len = mid;
            right = mid - 1;
        }
    }
    return len;
}

int main() {
    int m;
    cin >> n >> m;

    lecture.assign(n, 0);
    for(int i = 0; i < n; i++) // 강의 길이 입력
        cin >> lecture[i];
    sort(lecture.begin(), lecture.end());

    // left : 블루레이 최소 길이 / right : 블루레이 최대 길이
    cout << bluelay(lecture[n-1], lecture[n-1] * n, m);
    return 0;
}