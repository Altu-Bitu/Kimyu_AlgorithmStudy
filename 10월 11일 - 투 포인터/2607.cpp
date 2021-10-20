#include <iostream>
#include <vector>

using namespace std;
int alpha[26];
vector<string> word;

bool checkConfiguration(int cmp[26]) { // 두 문자 구성 비교하기
    int different = 0;

    int left = 0, right = 25;
    while(left < right) {
        while(left < right) { // 다른 구성 나올 때까지 반복
            if(alpha[left] != cmp[left]) break;
            left++;
        }
        different += abs(alpha[left] - cmp[left]);
        if(different > 2) return false;
        if(left == right) break;

        while(left < right) { // 다른 구성 나올 때까지 반복
            if(alpha[right] != cmp[right]) break;
            right--;
        }
        different += abs(alpha[right] - cmp[right]);
        if(different > 2) return false;
        if(left == right) break;

        // 하나의 문자를 다른 문자로 바꿀 수 있는 경우
        if((alpha[left] + alpha[right]) != (cmp[left] + cmp[right])) return false;
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