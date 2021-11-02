#include <iostream>

using namespace std;
const int N = 100;

bool s[N+1];
pair<int, int> st[N];

void printSwitch(int n) { // 스위치 상태 출력
    for(int i = 1; i <= n; i++) {
        cout << s[i] << ' ';
        if(!(i%20)) cout << '\n';
    }
}

void male(int n, int my_num) { // 남학생: 스위치 번호가 자신의 배수인 경우 스위치 변환
    for(int i = 1; i <= n; i++)
        if(!(i%my_num)) s[i] = !s[i];
}

void female(int n, int left, int right) { // 여학생: 자신을 중심으로 좌우 대칭인 구간의 스위치 변환
    if(left < 1 || right > n) return;
    if(s[left] == s[right]) {
        s[left] = !s[left]; s[right] = !s[right];
        female(n, left-1, right+1);
    }
}

void onOff(int n, int student) {
    for(int i = 0; i < student; i++) {
        switch (st[i].first) {
            case 1: // 남학생
                male(n, st[i].second);
                break;
            case 2: // 여학생
                s[st[i].second] = !s[st[i].second]; // 자기 자신 반전
                female(n, st[i].second - 1, st[i].second + 1);
                break;
        }
    }
}

int main() {
    int n, student;

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> s[i];

    cin >> student;
    for(int i = 0; i < student; i++)
        cin >> st[i].first >> st[i].second;

    onOff(n, student);
    printSwitch(n);
    return 0;
}