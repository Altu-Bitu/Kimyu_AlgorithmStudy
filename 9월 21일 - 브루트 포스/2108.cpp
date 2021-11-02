#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
vector<int> vec;
int cnt[8001] = {0,};

int mode() { // ÃÖºó°ª
    int max = 0, result, max_cnt = 0;

    for(int i = 0; i < 8001; i++) {
        if(max < cnt[i]) {
            max = cnt[i]; max_cnt = 1;
            result = i - 4000;
        }
        else if(max == cnt[i]) max_cnt++;
        if(max == cnt[i] && max_cnt == 2) result = i - 4000;
    }
    return result;
}

int main() {
    int n, num, sum = 0, min_num, max_num, mid;
    cin >> n;

    mid = n / 2;
    for(int i = 0; i < n; i++) {
        cin >> num;
        sum += num;
        vec.push_back(num);
        cnt[num+4000]++;
    }
    sort(vec.begin(), vec.end());
    min_num = vec[0]; max_num = vec[n-1];

    cout << round((double) sum / n) << '\n'; // Æò±Õ
    cout << vec[mid] << '\n';                // Áß¾Ó°ª
    cout << mode() << '\n';                  // ÃÖºó°ª
    cout << max_num - min_num;               // ¹üÀ§
    return 0;
}