#include <iostream>
#include <queue>

using namespace std;
priority_queue<long long, vector<long long>, greater<>> pq;

long long card_game(int m) { // 카드 합체
    long long card1, card2, sum;
    while(m--) {
        card1 = pq.top(); pq.pop(); // x번 카드
        card2 = pq.top(); pq.pop(); // y번 카드
        sum = card1 + card2;
        pq.push(sum); pq.push(sum); // 두 장에 덮어쓰기
    }
    sum = 0;
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    return sum; // 가장 작은 점수 반환
}

int main() {
    int n, m, num;
    cin >> n >> m;

    while(n--) {
        cin >> num;
        pq.push(num);
    }
    cout << card_game(m);
    return 0;
}