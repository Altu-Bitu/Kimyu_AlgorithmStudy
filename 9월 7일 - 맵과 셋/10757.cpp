#include <iostream>
#include <string>
#include <stack>

using namespace std;

void addLargeNum(const string &a, const string &b) { // 더하기
    stack<int> result;
    int tmp, remain; // (tmp: 연산용, remain 올림용)
    int p1 = a.length()-1, p2 = b.length()-1; // (일의 자리부터 계산하기 위함)

    bool flag = false; // 올림 여부 표시
    while(p1 >= 0 && p2 >= 0) {
        tmp = a[p1]-'0' + b[p2]-'0';
        if(flag) {
            tmp += remain;
            flag = false;
            remain = 0;
        }
        if(tmp/10) {
            flag = true;
            remain = (int) tmp/10;
        }
        result.push(tmp%10);
        p1--; p2--;
    }

    while(p1>=0) { // a에 아직 숫자가 더 남아있는 경우
        tmp = a[p1] - '0';
        if(flag) {
            tmp += remain;
            flag = false;
            remain = 0;
        }
        if(tmp/10) {
            flag = true;
            remain = (int) tmp/10;
        }
        result.push(tmp%10);
        p1--;
    }

    while(p2>=0) { // b에 아직 숫자가 더 남아있는 경우
        tmp = b[p2] - '0';
        if(flag) {
            tmp += remain;
            flag = false;
            remain = 0;
        }
        if(tmp/10) {
            flag = true;
            remain = (int) tmp/10;
        }
        result.push(tmp%10);
        p2--;
    }
    if(flag) result.push(remain);

    while(!result.empty()) { // 덧셈 결과 출력
        cout << result.top();
        result.pop();
    }
}

int main() {
    string a, b;
    cin >> a >> b;
    addLargeNum(a,b);
    return 0;
}