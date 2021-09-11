#include <iostream>
#include <vector>

using namespace std;
vector<int> a;

void partialSum(int k, int n) {
    int result = 0;

    for(int i = 0; i < n-1; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += a[j];
            if(sum == k) result++;
        }
    }
    cout << result;
}

int main() {
    int n, k;
    cin >> n >> k;

    a.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    partialSum(k, n);
    return 0;
}