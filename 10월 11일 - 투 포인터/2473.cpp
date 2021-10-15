#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef struct liquid {
    int l[3];
}liquid;
vector<int> l;

// 세 가지 용액 혼합값이 0에 가깝도록
liquid threeLiquid(int n) {
    liquid result;
    ll min_diff = 3 * 1e9 + 1; // 세 가지 용액 혼합값 최솟값 저장하는 변수

    for(int i = 0; i < n; i++) { // i번째 -> 나머지 용액
        int left = 0, right = n-1;

        while(left < right && min_diff) { // (min_diff가 0이면 stop)
            if(left == i) { left++; continue; }
            if(right == i) { right--; continue; }

            ll mix = (ll) l[left] + l[i] + l[right];
            if(abs(mix) < min_diff) {
                min_diff = abs(mix);
                result.l[0] = l[left];
                result.l[1] = l[i];
                result.l[2] = l[right];
            }

            if(mix > 0) right--;     // 더 작은 값 만들기
            else if(mix < 0) left++; // 더 큰 값 만들기
        }
    }
    sort(result.l, result.l+3); // 세 용액 오름차순 정렬
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    l.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> l[i];
    sort(l.begin(), l.end());

    liquid result = threeLiquid(n);
    cout << result.l[0] << ' ' << result.l[1] << ' ' << result.l[2];
    return 0;
}