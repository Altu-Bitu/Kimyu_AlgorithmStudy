#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int liquid[3];
vector<int> l;

// 세 가지 용액 혼합값이 0에 가깝도록
void threeLiquid(int n) {
    ll min_diff = 3 * 1e9 + 1; // 세 가지 용액 혼합값 최솟값 저장하는 변수

    for(int i = 0; i < n; i++) { // i번째 -> 나머지 용액
        int left = i+1, right = n-1;

        while(left < right && min_diff) { // (min_diff가 0이면 stop)
            ll mix = (ll) l[left] + l[i] + l[right];

            if(abs(mix) < min_diff) {
                min_diff = abs(mix);
                liquid[0] = l[left];
                liquid[1] = l[i];
                liquid[2] = l[right];
            }

            if(mix > 0) right--;     // 더 작은 값 만들기
            else if(mix < 0) left++; // 더 큰 값 만들기
        }
    }
    sort(liquid, liquid+3); // 세 용액 오름차순 정렬
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

    threeLiquid(n);
    cout << liquid[0] << ' ' << liquid[1] << ' ' << liquid[2];
    return 0;
}