#include <iostream>
#include <deque>

using namespace std;
// 도도, 수연 덱 / 도도, 수연 그라운드
deque<int> d, s, d_ground, s_ground;

bool isDodoWinner() {
    // 가장 위에 위치한 카드에 5가 나오는 경우
    if((!d_ground.empty() && d_ground.front() == 5) ||
    (!s_ground.empty() && s_ground.front() == 5)) return true;
    return false;
}

bool isSuyeonWinner() {
    // 가장 위에 위치한 카드의 숫자 합이 5가 되는 경우
    if(!d_ground.empty() && !s_ground.empty() &&
        d_ground.front() + s_ground.front() == 5) return true;
    return false;
}

void emptyGround(deque<int> &deq, deque<int> &ground) { // 그라운드 비우기
    while(!ground.empty()) {
        // 그라운드 카드 뒤집어서 (상하반전) 자신의 덱 아래로 합치기 (push back)
        deq.push_back(ground.back());
        ground.pop_back();
    }
}

void groundCheck() { // 3. 종을 칠 수 있는가
    if(isDodoWinner()) {
        // 4. 카드 합치기
        emptyGround(d, s_ground);
        emptyGround(d, d_ground);
    }
    else if(isSuyeonWinner()) {
        // 4. 카드 합치기
        emptyGround(s, d_ground);
        emptyGround(s, s_ground);
    }
}

void game(int m) { // 할리 갈리 게임
    int cnt = 0; // 게임 진행 횟수 카운트

    while(true) {
        // 도도
        d_ground.push_front(d.front()); d.pop_front(); // 2번
        if(d.empty()) { cout << "su"; return; }
        groundCheck(); // 3번 & 4번
        if(++cnt == m) break;
        // 수연
        s_ground.push_front(s.front()); s.pop_front(); // 2번
        if(s.empty()) { cout << "do"; return; }
        groundCheck(); // 3번 & 4번
        if(++cnt == m) break;
    }

    if(d.size() > s.size()) cout << "do";
    else if(d.size() < s.size()) cout << "su";
    else cout << "dosu";
}

int main() {
    int n, m, d_card, s_card;
    cin >> n >> m;

    // 1번 : 덱 배분 받기
    for(int i = 0; i < n; i++) { // 맨 아래 위치한 카드부터 입력
        cin >> d_card >> s_card;
        d.push_front(d_card);
        s.push_front(s_card);
    }

    game(m);
    return 0;
}