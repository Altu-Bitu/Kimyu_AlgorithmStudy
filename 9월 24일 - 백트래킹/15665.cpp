#include <iostream>
#include <set>

using namespace std;
const int SIZE = 7;

int n, m;
set<int> temp; // 사용자 숫자 입력값 저장하는 셋
int num[SIZE]; // 수열 저장하는 배열

void backtracking(int cnt) { // cnt: 수열 길이
    if(cnt == m) { // 기저 조건
        for(int i = 0; i < m; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }

    for(auto iter = temp.begin(); iter != temp.end(); iter++) {
        num[cnt] = *iter;
        backtracking(cnt+1); // (중복 허용)
    }
}

int main() {
    int input;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> input;
        temp.insert(input);
    }

    backtracking(0);
    return 0;
}