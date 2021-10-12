#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

// 구간 점수 최댓값이 mid일 때, 구간 수
int divide(int mid) {
    int cnt = 1, min_num, max_num; // 첫번째 구간 할당
    min_num = max_num = v[0];

    for(int i = 1; i < n; i++) {
        min_num = min(min_num, v[i]);
        max_num = max(max_num, v[i]);
        if(max_num - min_num > mid) { // 새로운 구간
            cnt++;
            min_num = max_num = v[i];
        }
    }
    return cnt;
}

int findMin(int left, int right, int m) { // 구간 점수 최댓값의 최솟값 출력
    int min_num = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int cnt = divide(mid);

        if(cnt > m) left = mid + 1; // 구간 개수 초과 -> 구간 최댓값 늘리기
        else if(cnt <= m) {         // 구간 개수 이하 -> 구간 최댓값 줄이기
            min_num = mid;
            right = mid - 1;
        }
    }
    return min_num;
}

int main() {
    int m, max_num = 0;
    cin >> n >> m;

    v.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        max_num = max(max_num, v[i]);
    }

    // left: 구간 점수 최댓값의 최솟값 / right: 구간 점수 최댓값의 최댓값
    cout << findMin(0, max_num, m);
    return 0;
}