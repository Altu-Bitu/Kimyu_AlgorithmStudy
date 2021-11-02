#include <iostream>
<<<<<<< HEAD
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<pair<int, int>> time_table;

int countRoom() { // 강의실 개수 세기
    int idx = 0, time_cnt = time_table.size();
    priority_queue<int, vector<int>, greater<>> room;
    room.push(time_table[idx++].second); // 초기 강의실 세팅

    while(idx < time_cnt) {
        if(room.top() <= time_table[idx].first) // (강의실 시간 갱신)
            room.pop();
        room.push(time_table[idx++].second); // 새로운 강의실
=======
#include <queue>

using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> time;
priority_queue<int, vector<int>, greater<>> room;

int count_room() { // 강의실 개수 세기
    room.push(time.top().second); // 초기 강의실 세팅
    time.pop();
    
    while(!time.empty()) {
        if(room.top() <= time.top().first) { // 강의실 시간 갱신
            room.pop();
            room.push(time.top().second);
        }
        else room.push(time.top().second); // 새로운 강의실
        time.pop();
>>>>>>> main
    }
    return room.size();
}

int main() {
    int n, start, end;
    cin >> n;

    while(n--) { // 강의실 시간표 입력
        cin >> start >> end;
<<<<<<< HEAD
        time_table.push_back({start, end});
    }
    sort(time_table.begin(), time_table.end());

    cout << countRoom();
=======
        time.push({start, end});
    }
    
    cout << count_room();
>>>>>>> main
    return 0;
}