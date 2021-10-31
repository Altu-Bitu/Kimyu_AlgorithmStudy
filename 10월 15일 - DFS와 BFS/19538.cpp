#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> q; // 유포자 저장하는 큐
vector<int> time;
vector<vector<int>> people;

bool trust(int p) { // 루머 믿을 것인가
    int believer = 0;
    for(int i : people[p]) // 주변 사람 검사
        if (time[i] != -1) believer++;
    return (double) believer >= (double) people[p].size() / 2;
}

void spreadRumor(int start, queue<int> &temp) { // 루머 전파
    while(!temp.empty()) {
        int new_spread = temp.front(); temp.pop();
        time[new_spread] = time[start] + 1;
        q.push(new_spread); // 새로운 유포자 추가
    }
}

void bfs() {
    queue<int> temp; // 전파 대상 임시 저장

    while(!q.empty()) {
        int start = q.front(); q.pop(); // 현재 유포자

        for(int i = 0; i < people[start].size(); i++) {
            int near = people[start][i]; // 전파 대상

            if(time[near] != -1) continue; // 이미 루머 믿는 사람 전파 불가
            if(trust(near)) temp.push(near); // 전파 대상 임시 저장
        }
        spreadRumor(start, temp); // 루머 전파
    }
}

int main() {
    int n, m, temp;

    cin >> n;
    time.assign(n+1, -1);
    people.assign(n+1, vector<int>());

    for(int i = 1; i <= n; i++) { // 주변인 입력
        while(true) {
            cin >> temp;
            if(!temp) break;
            people[i].push_back(temp);
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++) { // 최초 유포자 입력
        cin >> temp;
        time[temp] = 0;
        q.push(temp);
    }

    bfs();
    for(int i = 1; i <= n; i++) // 결과 출력
        cout << time[i] << ' ';
    return 0;
}