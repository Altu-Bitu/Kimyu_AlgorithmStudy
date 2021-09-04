#include <iostream>
#include <vector>

using namespace std;
vector<int> a, sorted;

long long countSupervisor(int n, int b, int c){
    long long result = 0;
    for(int i = 0; i < n; i++) {
        a[i] -= b;
        result++;
        if(a[i] > 0) {
            if(a[i] % c == 0) result += a[i]/c;
            else result += (a[i]/c + 1);
        }
    }
    return result;
}

int main() {
    int n, b, c;
    cin >> n;

    a.assign(n, 0);
    sorted.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> b >> c;
    cout << countSupervisor(n, b, c);
    return 0;
}