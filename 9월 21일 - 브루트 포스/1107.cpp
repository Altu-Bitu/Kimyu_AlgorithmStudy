#include <iostream>

using namespace std;
const int CHANNEL = 100; // 현재 채널
const int MAX_CHANNEL = 500000;
bool breakdown[10] = {false, }; // 고장난 버튼

bool possible(int num) { // 리모컨으로 누를 수 있는 채널인가
    string temp = to_string(num);
    for(char t : temp)
        if (breakdown[t - '0']) return false; // 고장난 버튼인 경우
    return true;
}

int pushButton(int n) { // 최소 클릭 수
    int temp, count = n - CHANNEL;

    for(int i = 0; i <= MAX_CHANNEL; i++) {
        if(possible(i)) {
            // '+' 누르는 횟수 + 숫자 직접 입력
            if(n >= i) temp = n-i + to_string(i).length();
            else temp = i-n + to_string(i).length();
            count = min(count, temp);
        }
    }
    return count;
}

int main() {
    int n, m, temp;
    cin >> n;
    cin >> m;

    while(m--) {
        cin >> temp;
        breakdown[temp] = true;
    }
    cout << pushButton(n);
    return 0;
}