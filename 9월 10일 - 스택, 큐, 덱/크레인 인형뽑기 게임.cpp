#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s; // 바구니

    for(int i = 0; i < moves.size(); i++) {
        for(int j = 0; j < board.size(); j++) {
            if(board[j][moves[i]-1]) {
                if(!s.empty() && s.top() == board[j][moves[i]-1]) { // 같은 인형 2개가 바구니에 담긴 경우
                    s.pop(); answer+=2; // 인형 2개 사라짐
                }
                else s.push(board[j][moves[i]-1]);
                board[j][moves[i]-1] = 0; // 해당 인형 격자에서 제거
                break;
            }
        }
    }
    return answer; // 사라진 인형 개수
}

int main() {
    vector<vector<int>> board = {
            {0,0,0,0,0},
            {0,0,1,0,3},
            {0,2,5,0,1},
            {4,2,4,4,2},
            {3,5,1,3,1}
    };
    vector<int> moves = {1,5,3,5,1,2,1,4};
    cout << solution(board, moves);
    return 0;
}