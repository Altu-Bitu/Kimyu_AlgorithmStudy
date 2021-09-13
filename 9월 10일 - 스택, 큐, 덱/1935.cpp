#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> num;
stack<double> temp;

void compute(string exp) {
    for(int i = 0; i < exp.length(); i++) {
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') { // 연산자가 나온 경우
            // 피연산자 pop
            double op2 = temp.top(); temp.pop();
            double op1 = temp.top(); temp.pop();

            switch(exp[i]) { // 연산 결과 다시 push
                case '+':
                    temp.push(op1 + op2);
                    break;
                case '-':
                    temp.push(op1 - op2);
                    break;
                case '*':
                    temp.push(op1 * op2);
                    break;
                case '/':
                    temp.push((double)op1/ op2);
                    break;
            }
        }
        else temp.push(num[exp[i]-'A']); // 연산자가 아닌 경우
    }
    printf("%.2f", temp.top()); // 소수 둘째자리까지 출력
}
int main() {
    int n;
    string exp;

    cin >> n;
    cin >> exp;
    num.assign(n, 0);
    for(int i = 0; i < n; i++) // 피연산자 입력받기
        cin >> num[i];
    compute(exp); // 후위 표기법 계산
    return 0;
}