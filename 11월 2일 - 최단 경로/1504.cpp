#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int n;
const int INF = 1e8 * 2 + 1;
vector<vector<ci>> graph;

int shortestPath (int start, int end) { // start부터 end까지 최단 경로
    vector<int> dist(n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq; // (first : 시작점으로부터 거리, second: 정점)

    // 시작 위치 초기화
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(weight > dist[node]) continue; // 이미 확인했던 정점

        for(int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; // 연결된 정점
            int next_weight = weight + graph[node][i].second; // 시작점으로부터 연결된 정점까지의 거리

            if(dist[next_node] > next_weight) { // 더 짧은 경로로 갈 수 있다면
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist[end];
}

int main() {
    int e, a, b, c, v1, v2;
    cin >> n >> e;

    graph.assign(n+1, vector<ci> (0)); // 인접 리스트
    while(e--) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;

    int path1 = shortestPath(1, v1) + shortestPath(v1, v2) + shortestPath(v2, n); // 1 -> v1 -> v2 -> n
    int path2 = shortestPath(1, v2) + shortestPath(v2, v1) + shortestPath(v1, n); // 1 -> v2 -> v1 -> n

    int ans = min(path1, path2); // 최단 경로 선택

    if(ans >= INF) cout << -1;
    else cout << ans;
    return 0;
}