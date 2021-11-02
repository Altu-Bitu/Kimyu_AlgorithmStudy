#include <iostream>
#include <deque>

using namespace std;
deque<int> d[2], g[2]; // 덱 & 그라운드 (0: 도도 / 1: 수연)

bool isDodoWinner() {
    // 가장 위에 위치한 카드에 5가 나오는 경우
    if((!g[0].empty() && g[0].front() == 5) ||
    (!g[1].empty() && g[1].front() == 5)) return true;
    return false;
}

bool isSuyeonWinner() {
    // 가장 위에 위치한 카드의 숫자 합이 5가 되는 경우
    if(!g[0].empty() && !g[1].empty() &&
        g[0].front() + g[1].front() == 5) return true;
    return false;
}

void emptyGround(int deq, int ground) { // 그라운드 비우기
    while(!g[ground].empty()) {
        // 그라운드 카드 뒤집어서 (상하반전) 자신의 덱 아래로 합치기 (push back)
        d[deq].push_back(g[ground].back());
        g[ground].pop_back();
    }
}

void groundCheck() {
    int winner = -1, loser = -1;
    // 3. 종을 칠 수 있는가
    if(isDodoWinner()) winner = 0;
    else if(isSuyeonWinner()) winner = 1;
    if(winner == -1) return; // 종 칠 수 없는 경우

    // 4. 카드 합치기
    loser = winner ? 0 : 1;
    emptyGround(winner, loser);  // 상대방 그라운드 비우기
    emptyGround(winner, winner); // 자신의 그라운드 비우기
}

void game(int m) { // 할리 갈리 게임
    int turn = 0; // (도도 : 0 / 수연 : 1)

    while(m--) {
        g[turn].push_front(d[turn].front()); // 2번
        d[turn].pop_front();
        if(d[turn].empty()) { // 게임 진행 도중에 덱 소진한 경우 상대방 승리
            if(!turn) cout << "su";
            else cout << "do";
            return;
        }
        groundCheck(); // 3번 & 4번
        turn = !turn;  // turn 바뀜
    }
    if(d[0].size() > d[1].size()) cout << "do";
    else if(d[0].size() < d[1].size()) cout << "su";
    else cout << "dosu";
}

int main() {
    int n, m, d_card, s_card;
    cin >> n >> m;

    // 1번 : 덱 배분 받기
    for(int i = 0; i < n; i++) { // 맨 아래 위치한 카드부터 입력
        cin >> d_card >> s_card;
        d[0].push_front(d_card);
        d[1].push_front(s_card);
    }

    game(m);
    return 0;
}