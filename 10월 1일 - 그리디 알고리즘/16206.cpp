#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> v; // 케이크 길이 저장하는 배열

bool cmp(int &i1, int &i2) { // (10의 배수인 케이크가 먼저 와야 함)
    if(i1%10 && !(i2%10)) return i1%10 < i2%10;
    else if(!(i1%10) && i2%10) return i1%10 < i2%10;
    return i1 < i2;
}

int cutCake(int len) { // 케이크 자르기 & 길이 10인 케이크 개수 반환
    if(len == 10) return 1;
    if(len < 10) return 0;

    int cake = 0;
    while(m > 0 && len > 10) { // 케이크 잘라야 하는 경우
        len -= 10;
        cake++; m--;
    }
    if(len == 10) cake++; // (남은 부분의 길이가 10인 경우 케이크 개수만 증가)
    return cake;
}

int countCake() {
    int cake = 0;
    for(int i = 0; i < n; i++) { // 10의 배수인 케이크
        if(m == 0) break;
        cake += cutCake(v[i]);
    }
    return cake;
}

int main() {
    cin >> n >> m;

    v.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), cmp);

    cout << countCake();
    return 0;
}