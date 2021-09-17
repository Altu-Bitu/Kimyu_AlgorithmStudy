#include <iostream>

using namespace std;
bool num[21] = {false, };

void add(int x) { num[x] = true; }
void remove(int x) { num[x] = false; }
int check(int x) { return num[x] ? 1 : 0; }
void toggle(int x) { check(x) ? remove(x) : add(x); }

void empty() {
    for(int i = 1; i <= 20; i++) num[i] = false;
}
void all() {
    for(int i = 1; i <= 20; i++) num[i] = true;
}

void add_remove_check_toggle(char ch, int x) {
    switch(ch) {
        case 'a': add(x); break;
        case 'r': remove(x); break;
        case 'c':
            cout << check(x) << '\n';
            break;
        case 't': toggle(x); break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, x;
    string cmd;
    cin >> m;

    while(m--) {
        cin >> cmd;
        if(cmd == "add" || cmd == "remove" || cmd == "check" || cmd == "toggle") {
            cin >> x;
            add_remove_check_toggle(cmd[0], x);
        }
        else if(cmd == "empty") empty();
        else if(cmd == "all") all();
    }
    return 0;
}