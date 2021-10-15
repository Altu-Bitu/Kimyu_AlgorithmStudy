#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a;

int findGood(int n) {
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        int left = 0, right = n-1;

        while(left < right) { // a[i]는 좋은 수인가
            if(left == i) { left++; continue; }
            if(right == i) { right--; continue; }

            int sum = a[left] + a[right];
            if(a[i] == sum) { cnt++; break; }
            else if(a[i] < sum) right--;
            else left++;
        }
    }
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
