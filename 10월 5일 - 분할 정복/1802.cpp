#include <iostream>

using namespace std;
bool result;

void divide(int left, int right, string paper) {
    if(left >= right) return; // 기저조건

    int l = left, r = right;
    while(l < r) {
        if(paper[l++] == paper[r--]) {
            result = false;
            return;
        }
    }
    // (마지막 l == r이므로) l과 r 은 mid 값
    divide(left, l-1, paper); // left ~ mid전까지 검사
    divide(l+1, right, paper); // mid후부터 ~ right 검사
}

int main() {
    int t, mid;
    cin >> t;

    string paper;
    while(t--) {
        cin >> paper;

        result = true;
        divide(0, paper.length()-1, paper);
        if(result) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}