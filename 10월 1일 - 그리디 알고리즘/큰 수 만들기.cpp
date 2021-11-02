#include <iostream>
#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length()-k, idx = 0; // 문자열 길이, 탐색 시작할 위치

    for(int i = 0; i < len; i++) {
        char max_num = 0;
        int max_idx = idx;
        for(int j = idx; j <= k+i; j++) { // (탐색) 가장 큰 수 찾기
            if(max_num < number[j]) {
                max_num = number[j];
                max_idx = j;
            }
        }
        idx = max_idx + 1;
        answer += number[max_idx]; // 가장 큰 수 정답에 추가
    }
    return answer;
}

int main() {
    string number = "1231234";
    int k = 3;

    cout << solution(number, k);
    return 0;
}