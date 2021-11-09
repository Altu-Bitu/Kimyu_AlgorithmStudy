#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 125 * 9 + 1;

typedef pair<int, pair<int, int>> node;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}; // 상 하 좌 우

int loseRupee(int n, vector<vector<int>> cave) { // (0, 0)부터 (n-1, n-1)까지 최단 경로 반환
    vector<vector<int>> dist(n, vector<int> (n, INF));
    priority_queue<node, vector<node>, greater<>> pq;

    // 시작 위치 지정
    dist[0][0] = cave[0][0];
    pq.push({dist[0][0], {0, 0}});

    while(!pq.empty()) {
        int weight = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if(weight > dist[row][col]) continue;

        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i];
            int new_col = col + dx[i];
            if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= n) continue;

            int new_weight = weight + cave[new_row][new_col];
            if(dist[new_row][new_col] > new_weight) { // 더 짧은 경로 가능한 경우
                dist[new_row][new_col] = new_weight;
                pq.push({new_weight, {new_row, new_col}});
            }
        }
    }
    return dist[n-1][n-1];
}

int main() {
    int n; // 동굴 크기

    int num = 0;
    while(true) {
        cin >> n;
        num++;
        if(!n) break;

        vector<vector<int>> cave(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) { // 도둑루피 크기 입력
            for(int j = 0; j < n; j++)
                cin >> cave[i][j];
        }
        cout << "Problem " << num << ": " << loseRupee(n, cave) << '\n';
    }
    return 0;
}