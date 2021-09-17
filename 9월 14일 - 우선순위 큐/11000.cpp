#include <iostream>
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
    }
    return room.size();
}

int main() {
    int n, start, end;
    cin >> n;

    while(n--) { // 강의실 시간표 입력
        cin >> start >> end;
        time.push({start, end});
    }
    
    cout << count_room();
    return 0;
}