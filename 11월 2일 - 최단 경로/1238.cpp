#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 1e7 + 1;

typedef pair<int, int> ci;
vector<vector<ci>> road;

int dijkstra(int start, int end, int n) {
    vector<int> dist (n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    // 시작 위치
    dist[start] = 0;
    pq.push({dist[start], start});

    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(weight > dist[node]) continue;

        for(int i = 0; i < road[node].size(); i++) {
            int next_node = road[node][i].first;
            int new_weight = weight + road[node][i].second;

            if(dist[next_node] > new_weight) { // 더 짧은 길로 갈 수 있는 경우
                dist[next_node] = new_weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    return dist[end]; // start부터 end까지의 최단거리 반환
}

vector<int> singleDestination(int end, int n) { // 한 정점에서 모든 정점까지의 거리 리턴
    vector<int> dist(n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    // 시작 위치
    dist[end] = 0;
    pq.push({dist[end], end});

    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(weight > dist[node]) continue;

        for(int i = 0; i < road[node].size(); i++) {
            int next_node = road[node][i].first;
            int new_weight = weight + road[node][i].second;

            if(dist[next_node] > new_weight) { // 더 짧은 길로 갈 수 있는 경우
                dist[next_node] = new_weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    return dist;
}

int roundTrip(int x, int n, vector<int> single_dst) { // 가장 오래 걸리는 학생의 소요시간 리턴
    vector<int> result (n+1, INF);
    for(int i = 1; i <= n; i++)
        result[i] = dijkstra(i, x, n) + single_dst[i];

    sort(result.begin()+1, result.end());
    return result[n];
}

int main() {
    int n, m, x, start, end, t;
    cin >> n >> m >> x;

    road.assign(n+1, vector<ci> ());
    while(m--) {
        cin >> start >> end >> t;
        road[start].push_back({end, t});
    }

    vector<int> single_dst = singleDestination(x, n); // x부터 모든 정점까지의 거리
    cout << roundTrip(x, n, single_dst);
    return 0;
}