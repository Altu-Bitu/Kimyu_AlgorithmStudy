#include <iostream>
#include <algorithm>

using namespace std;
const int SIZE = 15;

int l, c;
char cipher[SIZE];
char alphabet[SIZE+1];

void backtracking(int cnt, int start, int vowel) {
    if(cnt == l) { // 기저 조건: 단어 길이 l일 때
        if(vowel >= 1 && l-vowel >= 2) {
            // 1. 최소 한 개의 모음
            // 2. 최소 두 개의 자음
            for (int i = 0; i < cnt; i++) // 가능한 암호 출력
                cout << cipher[i];
            cout << '\n';
        }
        return;
    }

    for(int i = start; i <= c; i++) {
        cipher[cnt] = alphabet[i];
        // (i+1: 오름차순)
        if(alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' || alphabet[i] == 'o' || alphabet[i] == 'u') backtracking(cnt+1, i+1, vowel+1);
        else backtracking(cnt+1, i+1, vowel);
    }
}

int main() {
    cin >> l >> c;

    for(int i = 1; i <= c; i++)
        cin >> alphabet[i];
    sort(alphabet+1, alphabet+c+1); // 입력한 문자들 정렬

    backtracking(0, 1, 0);
    return 0;
}