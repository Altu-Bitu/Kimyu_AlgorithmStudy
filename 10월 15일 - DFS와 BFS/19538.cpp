#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

queue<pair<int, int>> q; // (first: 전파자, second: 전파 시간)
vector<int> time, believer; // 루머 믿는 데 걸리는 시간, 루머 믿는 사람
vector<vector<int>> people; // 주변인 저장

vector<pair<int, int>> simultaneousSpreader() { // 동시 전파자 리턴
    vector<pair<int, int>> simultaneous_spreader; // 동시 전파자 저장하는 큐
    simultaneous_spreader.push_back(q.front());
    q.pop();

    while(!q.empty()) { // 동시 전파자 있는가
        if(simultaneous_spreader.front().second != q.front().second) break; // 동시 전파자 더이상 없음
        simultaneous_spreader.push_back(q.front());
        q.pop();
    }
    return simultaneous_spreader;
}

set<int> findNeighbor(int simul_cnt, vector<pair<int, int>> simultaneous_spreader) { // 주변인 리턴
    set<int> neighbor;
    for(int i = 0; i < simul_cnt; i++) {
        int spreader = simultaneous_spreader[i].first; // 전파자

        for (int j = 0; j < people[spreader].size(); j++) {
            int near = people[spreader][j];
            believer[near]++;
            if(time[near] == -1) neighbor.insert(near); // 루머 믿지 않는 주변인만 고려
        }
    }
    return neighbor;
}

void spreadRumor(queue<pair<int, int>> &temp) { // 루머 전파
    while(!temp.empty()) {
        int new_spreader = temp.front().first;
        int new_spread_time = temp.front().second;
        temp.pop();

        time[new_spreader] = new_spread_time + 1;
        q.push({new_spreader, time[new_spreader]}); // 새로운 유포자 추가
    }
}

bool trust(int near) { return (double) believer[near] >= (double) people[near].size() / 2; }

void bfs() {
    while(!q.empty()) {
        vector<pair<int, int>> simultaneous_spreader = simultaneousSpreader(); // 동시 전파자
        int simul_cnt = simultaneous_spreader.size(); // 동시 전파자 수
        if(!simul_cnt) continue;

        set<int> neighbor = findNeighbor(simul_cnt, simultaneous_spreader); // 주변인
        int spread_time = simultaneous_spreader[0].second; // 전파 시간

        queue<pair<int, int>> temp; // 전파 대상 임시 저장
        for(auto iter = neighbor.begin(); iter != neighbor.end(); iter++) // 주변인 중 전파 대상 탐색
            if(trust(*iter)) temp.push({*iter, spread_time});

        spreadRumor(temp); // 루머 전파 (동시 전파자의 전파 대상 파악 후 동시 전파)
    }
}

void printAnswer(int n) { // 결과 출력
    for(int i = 1; i <= n; i++)
        cout << time[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, person;

    cin >> n;
    time.assign(n+1, -1);
    believer.assign(n+1, 0);
    people.assign(n+1, vector<int>());

    for(int i = 1; i <= n; i++) { // 주변인 입력
        while(true) {
            cin >> person;
            if(!person) break;
            people[i].push_back(person);
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++) { // 최초 유포자 입력
        cin >> person;
        time[person] = 0;
        q.push({person, time[person]});
    }

    bfs();
    printAnswer(n);
    return 0;
}