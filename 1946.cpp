#include <iostream>
#include <vector>

using namespace std;
vector<int> testNum;
struct grade {
    int document;
    int interview;
};
vector<vector<grade>> test;
vector<vector<grade>> evalDoc;
vector<vector<grade>> evalInt;

void ascendingDoc(int n, vector<grade> &e) { // 서류 점수 오름차순
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(e[j].document > e[j+1].document)
                swap(e[j], e[j+1]);
        }
    }
}

void ascendingInt(int n, vector<grade> &e) { // 면접 점수 오름차순
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(e[j].interview > e[j+1].interview)
                swap(e[j], e[j+1]);
        }
    }
}

void findPass(int t) { // 합격자 찾기
    for(int i = 0; i < t; i++) {
        int pass = testNum[i];
        for(int j = 0; j < testNum[i]; j++) {
            if(evalDoc[i][j].document == evalInt[i][j].document
                && evalDoc[i][j].interview == evalInt[i][j].interview)
                pass -= 1;
            else break;
        }
        cout << pass << '\n';
    }
}

int main() {
    int t, n1, n2;
    cin >> t;

    testNum.assign(t , 0);
    test.assign(t, vector<grade>(100000, {0, 0}));
    evalDoc.assign(t, vector<grade>(100000, {0, 0}));
    evalInt.assign(t, vector<grade>(100000, {0, 0}));

    for(int i = 0; i < t; i++) {
        cin >> testNum[i];
        for(int j = 0; j < testNum[i]; j++)
            cin >> test[i][j].document >> test[i][j].interview;
        evalDoc[i] = test[i];
        ascendingDoc(testNum[i], evalDoc[i]);
        evalInt[i] = test[i];
        ascendingInt(testNum[i], evalInt[i]);
    }

    return 0;
}

