#include <iostream>
#include <vector>

using namespace std;

// p만큼 줄어든 경우, 건널 수 있는가
bool pass(vector<int> stones, int k, int p) {
    int blank = 0;
    for(int i = 0; i < stones.size(); i++) {
        if(stones[i]-p <= 0) blank++;
        else blank = 0;
        if(blank == k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;

    // left : 건널 수 있는 사람 최솟값 / right : 건널 수 있는 사람 최댓값
    int left = 0, right = 0;
    for(int i = 0; i < stones.size(); i++)
        right = max(right, stones[i]);

    while(left <= right) {
        int mid = (left + right) / 2;
        bool success = pass(stones, k, mid);

        if(!success) right = mid - 1; // 징검다리 건널 수 없음 -> 사람 줄이기
        else { // 징검다리 건널 수 있음 -> 사람 수 늘리기
            answer = mid + 1; // (mid만큼 줄어들고도 한 사람 더 건널 수 있음)
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;

    cout << solution(stones, k);
    return 0;
}