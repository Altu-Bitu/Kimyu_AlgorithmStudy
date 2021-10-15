#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100000;

int num[MAX+1];
vector<int> a;

int maxLen(int n, int k) {
    int len = 0, left = 0, right = 0; // (left & right : 투포인터)

    while(left <= right && right < n) {
        while(right < n) { // 구간 늘리기
            if(num[a[right]] == k) break; // (k개 이하만 허용)
            num[a[right++]]++;
        }
        len = max(len, right - left);

        bool stop = false;
        while(left < right) { // (k개 미만이 될 때까지) 구간 줄이기
            if(num[a[left]] == k) stop = true;
            num[a[left++]]--;
            if(stop) break;
        }
    }
    return len;
}

int main() {
    int n, k;
    cin >> n >> k;

    a.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << maxLen(n, k);
    return 0;
}