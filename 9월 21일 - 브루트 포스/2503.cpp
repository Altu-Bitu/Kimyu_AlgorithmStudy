#include <iostream>
#include <vector>

using namespace std;
bool suppose[1000];

vector<int> digit(int q) { // 자릿수 구하기
    vector<int> temp;
    temp.assign(3, 0);
    for(int i = 2; i >= 0; i--) {
        temp[i] = q % 10;
        q /= 10;
    }
    return temp;
}

void setInvalid() { // 불가능한 수 세팅
    for(int i = 0; i < 123; i++) suppose[i] = false; // 1. 두 자리수 불가능
    for(int i = 123; i <= 987; i++) {
        vector<int> check = digit(i);
        if(check[0] == 0 || check[1] == 0 || check[2] == 0) { // 2. 0 불가능
            suppose[i] = false;
            continue;
        }
        else if(check[0] == check[1] || check[0] == check[2] || check[1] == check[2]) { // 3. 같은 숫자 불가능
            suppose[i] = false;
            continue;
        }
        suppose[i] = true;
    }
    for(int i = 988; i < 1000; i++) suppose[i] = false; // 4. 최대 숫자 벗어나는 경우
}

void baseballGame(int q, int strike, int ball) { // 숫자 야구
    vector<int> num = digit(q);

    for(int i = 123; i <= 987; i++) { // 영수 예상 숫자 리스트
        int strike_cnt = 0, ball_cnt = 0;

        if(suppose[i]) {
            vector<int> cmp = digit(i); // 비교 대상
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    if(j == k && num[j] == cmp[k]) strike_cnt++;    // 스트라이크
                    else if(j != k && num[j] == cmp[k]) ball_cnt++; // 볼
                }
            }
            if(strike != strike_cnt || ball != ball_cnt) suppose[i] = false; // 예상 숫자 리스트에서 제외
        }
    }
}

int countAnswer() { // 예상 숫자 개수 세기
    int sum = 0;
    for(int i = 123; i <= 987; i++)
        sum += suppose[i];
    return sum;
}

int main() {
    int n, q, strike, ball;
    cin >> n;

    setInvalid(); // 불가능한 숫자 세팅
    while(n--) {
       cin >> q >> strike >> ball;
        baseballGame(q, strike, ball);
    }

    cout << countAnswer();
    return 0;
}