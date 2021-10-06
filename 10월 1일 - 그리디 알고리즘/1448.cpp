#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> side;

int biggestTriangle(int n) { // 세 변의 길이의 합의 최댓값 구하기
    for(int i = 0; i < n-2; i++) {
        if(side[i] < side[i+1] + side[i+2])
            return side[i] + side[i+1] + side[i+2];
    }
    return -1; // 삼각형 만들 수 없는 경우
}

int main() {
    int n;
    cin >> n;

    side.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> side[i];
    sort(side.begin(), side.end(), greater<>()); // 길이 내림차순 정렬

    cout << biggestTriangle(n);
    return 0;
}