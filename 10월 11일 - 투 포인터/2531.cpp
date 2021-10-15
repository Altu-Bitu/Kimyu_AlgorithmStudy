#include <iostream>
#include <vector>

using namespace std;
const int N = 30000;

bool sushi[N+1];
vector<int> belt;

int countSushi(int n, int k, int c) {
    int s = 0;
    for(int i = 0; i < n; i++) {
        int kind = 0;
        // i부터 k개 검사
        for(int j = i; j < i + k; j++) {
            if(sushi[belt[j % n]]) continue;
            // 스시 카운트
            sushi[belt[j % n]] = true; kind++;
        }
        if(!sushi[c]) kind++; // 쿠폰에 적힌 스시가 포함되지 않은 경우 쿠폰 사용
        s = max(s, kind);

        // 스시 초기화
        for(int j = i; j < i + k; j++)
            sushi[belt[j % n]] = false;
    }
    return s;
}

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    belt.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> belt[i];

    cout << countSushi(n, k, c);
    return 0;
}