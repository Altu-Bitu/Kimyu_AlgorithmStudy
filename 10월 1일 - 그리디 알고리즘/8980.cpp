#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2000, M = 10000;
typedef struct info {
    int from, to, box;
}info;

info t[M];
int capacity[N];

bool cmp(info &i1, info &i2) {
    if(i1.to != i2.to) return i1.to < i2.to; // 받는 마을 오름차순
    return i1.from < i2.from;                // 보내는 마을 오름차순
}

int countBox(int c, int m) {
    int box = 0;
    for(int i = 0; i < m; i++) {
        int temp = t[i].box; // 실을 짐 무게
        for(int j = t[i].from; j < t[i].to; j++) // 얼마나 실을 수 있는가
            if(capacity[j] + temp > c) temp = c - capacity[j]; // 트럭 수용량을 초과한 경우 양 줄이기

        for(int j = t[i].from; j < t[i].to; j++) // 짐 싣기
            capacity[j] += temp;
        box += temp;
    }
    return box;
}

int main() {
    int n, c, m;
    cin >> n >> c;
    cin >> m;

    for(int i = 0; i < m; i++)
        cin >> t[i].from >> t[i].to >> t[i].box;
    sort(t, t+m, cmp);

    cout << countBox(c, m);
    return 0;
}