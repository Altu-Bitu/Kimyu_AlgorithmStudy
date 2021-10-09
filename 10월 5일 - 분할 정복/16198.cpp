#include <iostream>
#include <vector>

using namespace std;

int max_energy = 0;
vector<int> w; // 에너지 저장하는 벡터

void backtracking(int energy) {
    if(w.size() == 2) { // 기저 조건 : 첫번째와 마지막 에너지 구슬은 제거할 수 없음
        max_energy = max(max_energy, energy);
        return;
    }

    for(int i = 1; i < w.size() - 1; i++) { // (i: 에너지 구슬)
        int save = w[i];
        energy += w[i-1] * w[i+1]; // 에너지 모으기
        w.erase(w.begin() + i);    // 에너지 구슬 제거
        backtracking(energy);

        w.insert(w.begin() + i, save); // 원상복구
        energy -= w[i-1] * w[i+1];
    }
}

int main() {
    int n;
    cin >> n;

    w.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> w[i];

    backtracking(0);
    cout << max_energy;
    return 0;
}