#include <iostream>

using namespace std;

bool is_java(string &arg) {
    // 1. 첫문자 반드시 소문자
    // 2. 소문자, 대문자 외에 다른 문자 불가
    if(arg[0] < 'a' || arg[0] > 'z') return false;     // (1번)
    if(arg.find('_') != string::npos) return false; // (2번)
    for(int i = 1; i < arg.length(); i++) {
        if ((arg[i] < 'A' || arg[i] > 'Z') && (arg[i] < 'a' || arg[i] > 'z')) // (2번)
            return false;
    }
    return true;
}

bool is_cpp(string &arg) {
    // 1. 첫문자 반드시 소문자
    // 2. 마지막 문자 _ 불가
    // 3. 연속으로 _ 불가
    if(arg[0] < 'a' || arg[0] > 'z') return false;      // (1번)
    if(arg[arg.length()-1] == '_') return false;        // (2번)
    if(arg.find("__") != string::npos) return false; // (3번)
    for(int i = 1; i < arg.length(); i++) {
        if ((arg[i] < 'a' || arg[i] > 'z') && arg[i] != '_') return false;
    }
    return true;
}

string java(string &arg) { // 자바 변수명 만들기
    string temp = "";
    for(int i = 0; i < arg.length(); i++) {
        if(arg[i] == '_') {
            temp += arg[i+1] - 'a' + 'A';
            i++;
            continue;
        }
        temp += arg[i];
    }
    return temp;
}

string cpp(string &arg) { // c++ 변수명 만들기
    string temp = "";
    for(char ch : arg) {
        if(ch >= 'A' && ch <= 'Z') {
            temp += '_';
            temp += ch - 'A' + 'a';
            continue;
        }
        temp += ch;
    }
    return temp;
}

string make_identifier(string &arg) { // 변수명 만들기
    bool isJava = is_java(arg);
    bool isCpp = is_cpp(arg);

    if(!isJava && !isCpp) return "Error!";
    if(isJava) return cpp(arg); // 자바 -> 씨쁠쁠
    else return java(arg);      // 씨쁠쁠 -> 자바
}

int main() {
    string argument;
    cin >> argument;

    cout << make_identifier(argument);
    return 0;
}