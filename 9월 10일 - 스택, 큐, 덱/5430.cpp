#include <iostream>
#include <vector>
#include <deque>

using namespace std;
vector<string> result;

void make_arr(bool reverse, deque<int> &d) { // 배열 재구성
    cout << '[';
    if(!d.empty()) {
        if (reverse) { // 역순으로 출력
            while (d.size() > 1) {
                cout << d.back() << ',';
                d.pop_back();
            }
        } else { // 원래대로 출력
            while (d.size() > 1) {
                cout << d.front() << ',';
                d.pop_front();
            }
        }
        cout << d.front();
    }
    cout << "]\n";
}

void ac_compute(string &cmd, string &arr) {
    deque<int> d;
    bool error = false, reverse = false; // 에러 여부, 역순 여부

    if(arr == "[]") error = true;
    else {
        string temp = "";
        for (char ch: arr) {
            if (ch == '[') continue;
            else if((ch == ']' || ch == ',') && temp != "") {
                d.push_back(stoi(temp)); temp = "";
                continue;
            }
            temp += ch;
        }

        for (char ch: cmd) {
            if (ch == 'R') {
                reverse = !reverse; // 순서 반대로
                continue;
            }
            if (d.empty()) { // 더이상 원소가 없는 경우 error
                error = true;
                break;
            }
            if (reverse) d.pop_back(); // 역순인 경우
            else d.pop_front();        // 역순 아닌 경우
        }
    }
    if(error) cout << "error\n";
    else make_arr(reverse, d);
}

int main() {
    int t, n;
    string p, arr;

    cin >> t;
    result.assign(t, "");
    while(t--) {
        cin >> p;
        cin >> n;
        cin >> arr;
        ac_compute(p, arr);
    }
    return 0;
}