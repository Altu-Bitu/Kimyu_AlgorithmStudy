#include <iostream>
#include <queue>

using namespace std;
queue<int> idx;

void findK(string num) { // K 위치 찾기
    for(int i = 0; i < num.length(); i++)
        if(num[i] == 'K') idx.push(i);
}

string maxNumber(string num) { // 최댓값 : 마지막이 k이면 끊어주기
    string answer = "";

    if(idx.empty()) { // K가 하나도 없는 경우 -> 모두 1
        for(int i = 0; i < num.length(); i++) answer += '1';
    }
    else { // K가 하나라도 있는 경우
        int m = 0, k;
        while(!idx.empty()) {
            answer += '5';
            k = idx.front(); idx.pop();
            for(int i = m; i < k; i++) answer += '0';
            m = k + 1;
        }
        for(int i = k + 1; i < num.length(); i++) answer += '1';
    }
    return answer;
}

string minNumber(string num) { // 최솟값 : k마다 끊어주기
    string answer = "";

    if(idx.empty()) { // K가 하나도 없는 경우 -> 첫자리만 1
        answer += '1';
        for(int i = 0; i < num.length()-1; i++) answer += '0';
    }
    else { // K가 하나라도 있는 경우
        int m = 0, k;
        while(!idx.empty()) {
            k = idx.front(); idx.pop();
            if(k-m) answer += '1';
            for(int i = m + 1; i < k; i++) answer += '0';
            answer += '5';
            m = k + 1;
        }
        if(m < num.length()) {
            answer += '1';
            for(int i = m + 1; i < num.length(); i++) answer += '0';
        }
    }
    return answer;
}

int main() {
    string num;
    cin >> num;

    findK(num);
    cout << maxNumber(num) << '\n';
    findK(num);
    cout << minNumber(num);
    return 0;
}