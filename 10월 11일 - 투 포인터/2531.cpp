#include <iostream>
#include <vector>

using namespace std;
const int N = 30000;

int cnt = 0; // 구간별 서로 다른 스시 종류 개수 저장하는 변수
int sushi[N+1];
vector<int> belt;

void removeSushi(int left) {
    if(sushi[belt[left]] == 1) cnt--; // (해당 종류의 스시 아예 사라짐)
    sushi[belt[left]]--;
}

void addSushi(int right) {
    if(!sushi[belt[right]]) cnt++; // (새로운 종류의 스시)
    sushi[belt[right]]++;
}

int maxSushi(int n, int k, int c) {
    int max_sushi = 0;
    sushi[c] = 1; cnt++; // 쿠폰 적용

    for(int i = 0; i < k; i++) // 첫번째 구간 탐색
        addSushi(i);
    max_sushi = max(max_sushi, cnt); // 최댓값 갱신

    // left: 이번 벨트에서 제거되는 스시 / right: 이번 벨트에서 추가되는 스시
    int left = 0, right = k;
    while(true) {
        removeSushi(left); // 스시 제거
        addSushi(right);   // 스시 추가
        max_sushi = max(max_sushi, cnt); // 최댓값 갱신

        // 한 칸씩 이동
        right = (right + 1) % n;
        if(right == k) break; // (모든 구간 탐색 완료)
        left = (left + 1) % n;
    }
    return max_sushi;
}

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    belt.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> belt[i];

    cout << maxSushi(n, k, c);
    return 0;
}