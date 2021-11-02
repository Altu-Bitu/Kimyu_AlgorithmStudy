#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a;

bool twoPointer(int i, int n) {
    int left = 0, right = n-1;

    while(left < right) { // a[i]는 좋은 수인가
        if(left == i) { left++; continue; }
        if(right == i) { right--; continue; }

        // 서로 다른 수 조건 만족시
        int sum = a[left] + a[right];
        if(a[i] == sum) return true; // 좋은 수인 경우
        else if(a[i] < sum) right--;
        else left++;
    }
    return false; // 좋은 수 아닌 경우
}

int findGood(int n) { // 좋은 수 개수 반환
    int cnt = 0;

    for(int i = 0; i < n; i++)
        cnt += twoPointer(i, n);
    return cnt;
}

int main() {
    int n;
    cin >> n;

    a.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    cout << findGood(n);
    return 0;
}
