#include <iostream>

using namespace std;
const int N = 1000;

int cost[N][3];

int main() {
    int n, r, g, b;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> r >> g >> b;
        // 0 : r / 1 : g / 2 : b
        cost[i][0] = min(cost[i-1][1], cost[i-1][2]) + r;
        cost[i][1] = min(cost[i-1][0], cost[i-1][2]) + g;
        cost[i][2] = min(cost[i-1][0], cost[i-1][1]) + b;
    }
    cout << min(cost[n][2], min(cost[n][1], cost[n][0]));
    return 0;
}