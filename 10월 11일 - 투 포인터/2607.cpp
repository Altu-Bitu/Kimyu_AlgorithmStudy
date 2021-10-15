#include <iostream>
#include <vector>

using namespace std;
int alpha[26];
vector<string> word;

bool checkConfiguration(int cmp[26]) { // 두 문자 구성 비교하기
    int different = 0, idx = -1;
    for(int i = 0; i < 26; i++) {
        if(alpha[i] == cmp[i]) continue;

        // 같은 구성 ->  1. 한 문자 더하거나 빼기  2. 한 문자 다른 문자로 바꾸기
        different++;
        if(abs(alpha[i] - cmp[i]) > 1) return false; // 1번 위반
        if(different > 2) return false;
        if(idx != -1 && alpha[idx] + alpha[i] != cmp[idx] + cmp[i]) return false; // 2번 위반
        idx = i;
    }
    return true;
}

void setAlphabet(int a[26], string w) { // 단어 구성 세팅하기
    for(int i = 0; i < w.length(); i++)
        a[w[i] - 'A']++;
}

int isSimilar(int n) {
    int cnt = 0;
    setAlphabet(alpha, word[0]); // 첫번째 알파벳 구성 세팅

    for(int i = 1; i < n; i++) {
        int cmp[26] = {0, };
        setAlphabet(cmp, word[i]); // 비교할 알파벳 구성 세팅
        if(checkConfiguration(cmp)) cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    word.assign(n, "");
    for(int i = 0; i < n; i++)
        cin >> word[i];

    cout << isSimilar(n);
    return 0;
}