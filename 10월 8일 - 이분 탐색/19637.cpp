#include <iostream>
#include <map>

using namespace std;
map<int, string> grade;

string printPower(int power) { // 칭호 리턴
    auto iter = grade.lower_bound(power);
    return iter->second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, power;
    string g;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> g >> power;
        if(grade.find(power) != grade.end()) continue;
        grade[power] = g;
    }

    while(m--) { // 캐릭터 전투력 입력
        cin >> power;
        cout << printPower(power) << '\n';
    }
    return 0;
}