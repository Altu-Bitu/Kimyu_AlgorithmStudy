#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> t;

int main() {
    int n, m;
    cin >> n >> m;

    t.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> t[i][j];
    }
    return 0;
}