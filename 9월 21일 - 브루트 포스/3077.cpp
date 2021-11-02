#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
map<string, int> answer; // 답안과 순서 저장하는 맵
vector<string> hyun;     // 현우 답안 저장하는 벡터

int score(int n) { // 점수 계산하기
    int result = 0, pos1, pos2;
    for(int i = 0; i < n-1; i++) {
        for(int j = i; j < n; j++) {
            pos1 = answer[hyun[i]];
            pos2 = answer[hyun[j]];
            if(pos1 < pos2) result++; // 순서가 올바른 경우 점수 부여
        }
    }
    return result;
}

int main() {
    int n;
    string input;
    cin >> n;

    for(int i = 0; i < n; i++) { // 답안 입력
        cin >> input;
        answer[input] = i; // 전투 순서 설정
    }
    hyun.assign(n, "");
    for(int i = 0; i < n; i++) // 현우 답안 입력
        cin >> hyun[i];

    cout << score(n) << '/' << n*(n-1)/2; // 점수 출력
    return 0;
}