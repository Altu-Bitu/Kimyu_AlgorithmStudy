#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 9;

int k;
char sign[SIZE];    // 부등호 저장하는 배열
int num [SIZE + 1]; // 수열 저장하는 배열
bool check[SIZE + 1];
vector<string> result; // 부등호 조건을 만족하는 수열 저장하는 벡터

void backtracking(int cnt, int start, int end) {
    if(cnt == k+1) { // 기저 조건 : 부등호 개수가 k개 -> 숫자는 k+1개
        string temp = "";
        for(int i = 0; i < cnt; i++)
            temp += to_string(num[i]);
        result.push_back(temp);
        return;
    }

    for(int i = start; i <= end; i++) {
        if(!check[i]) {
            num[cnt] = i;
            check[i] = true;
            if(sign[cnt] == '<') backtracking(cnt+1, i+1, SIZE); // 부등호가 < 인 경우: 큰 숫자만 탐색
            else backtracking(cnt+1, 0, i-1);               // 부등호가 >인 경우: 작은 숫자만 탐색
            check[i] = false; // 원상 복구
        }
    }
}

int main() {
    cin >> k;
    for(int i = 0; i < k; i++)
        cin >> sign[i];

    backtracking(0, 0, SIZE);
    cout << result[result.size()-1] << '\n';
    cout << result[0];
    return 0;
}