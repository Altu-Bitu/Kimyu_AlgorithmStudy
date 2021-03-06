#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<stack<int>> make_boardStack(int row_cnt, int col_cnt, vector<vector<int>> board) { // board 스택 만들기
    vector<stack<int>> b;
    for(int i = 0; i < col_cnt; i++) {
        stack<int> temp;
        for(int j = row_cnt-1; j >= 0; j--) {
            if(board[j][i] == 0) break;
            temp.push(board[j][i]);
        }
        b.push_back(temp);
    }
    return b;
}

int pickUp(vector<stack<int>> b, vector<int> moves) { // 인형 뽑기
    int answer = 0;
    stack<int> s; // 바구니

    for(int i = 0; i < moves.size(); i++) {
        if(!s.empty() && !b[moves[i]-1].empty() && s.top() == b[moves[i]-1].top()) { // 같은 인형들이 연달아 바구니에 담긴 경우
            s.pop(); b[moves[i]-1].pop();
            answer+=2; // 인형 2개 사라짐
        }
        else if(!b[moves[i]-1].empty()) {
            s.push(b[moves[i]-1].top());
            b[moves[i]-1].pop();
        }
    }
    return answer; // 사라진 인형 개수 반환
}

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<stack<int>> b = make_boardStack(board.size(), board[0].size(), board);
    return pickUp(b, moves);
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