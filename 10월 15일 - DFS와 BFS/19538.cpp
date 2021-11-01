#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> q; // (first: 전파자, second: 전파 시간)
vector<int> time; // 루머 믿는 데 걸리는 시간
vector<vector<int>> people; // 주변인 저장

queue<pair<int, int>> simultaneousSpreader() { // 동시 전파자 리턴
    queue<pair<int, int>> simultaneous_spreader; // 동시 전파자 저장하는 큐
    simultaneous_spreader.push(q.front());

    while(!q.empty()) { // 동시 전파자 있는가
        if(simultaneous_spreader.front().second != q.front().second) break; // 동시 전파자 더이상 없음
        simultaneous_spreader.push(q.front());
        q.pop();
    }
    return simultaneous_spreader;
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

bool trust(int p) { // 루머 믿을 것인가
    int believer = 0;
    for(int i : people[p]) // 주변 사람 검사
        if (time[i] != -1) believer++;
    return (double) believer >= (double) people[p].size() / 2;
}

void bfs() {
    while(!q.empty()) {
        queue<pair<int, int>> simultaneous_spreader = simultaneousSpreader(); // 동시 전파자
        queue<pair<int, int>> temp; // 전파 대상 임시 저장

        while(!simultaneous_spreader.empty()) {
            int spreader = simultaneous_spreader.front().first;     // 전파자
            int spread_time = simultaneous_spreader.front().second; // 전파 시간
            simultaneous_spreader.pop();

            for(int i = 0; i < people[spreader].size(); i++) { // 주변인 검사
                int near = people[spreader][i]; // 전파 대상

                if(time[near] != -1) continue;   // 이미 루머 믿는 사람 전파 불가
                if(trust(near)) temp.push({near, spread_time}); // 전파 대상 임시 저장
            }
        }
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