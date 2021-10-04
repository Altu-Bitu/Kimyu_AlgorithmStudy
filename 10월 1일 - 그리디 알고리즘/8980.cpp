#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2000, M = 10000;
typedef struct info {
    int from, to, box;
}info;

info t[M];

bool cmp(info &i1, info &i2) {
    if(i1.to != i2.to) return i1.to < i2.to; // 받는 마을 오름차순
    return i1.from < i2.from;                // 보내는 마을 오름차순
}

int countBox(int c, int m) {
    int box = 0;
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