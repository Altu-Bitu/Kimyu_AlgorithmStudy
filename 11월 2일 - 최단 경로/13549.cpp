#include <iostream>
#include <queue>

using namespace std;

const int MAX_TIME = 100000;
bool visited[MAX_TIME+1];

int bfs(int n, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, n}); // 시작 위치 삽입
    visited[n] = true;

    while(!pq.empty()) {
        int x_time = pq.top().first; // 소요 시간
        int x = pq.top().second;     // 탐색 위치
        pq.pop();

        if(x == k) return x_time; // 소요 시간 반환

        // 1. 걷기
        int walk1 = x - 1, walk2 = x + 1;
        if(walk1 >= 0 && !visited[walk1]) { // 왼쪽으로 한 칸
            pq.push({x_time + 1, walk1});
            visited[walk1] = true;
        }
        if(walk2 <= MAX_TIME && !visited[walk2]) { // 오른쪽으로 한 칸
            pq.push({x_time + 1, walk2});
            visited[walk2] = true;
        }
        // 2. 순간이동
        int teleport = x * 2;
        if(teleport <= MAX_TIME && !visited[teleport]) {
            pq.push({x_time, teleport});
            visited[teleport] = true;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << bfs(n, k);
    return 0;
}