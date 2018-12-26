#include <map>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void change1(string s) {
    int len = s.length(), num = 0;
    for (int i = 0; i < len; i++) {
        num = num * 10 + (s[i] - '0');
    }
    if (num / 13) {
        cout << tenDigit[num / 13];
        if  (num % 13) {
            cout << ' ' << unitDigit[num % 13] << endl;
        }
    }
    else {
        cout << unitDigit[num % 13] << endl;
    }
    return;
}

void change2(string s) {
    int len = s.length(), num = 0;
    if (len == 4) {
        cout << 0 << endl;
        return;
    }
    else if (len == 3) {
        for (int i = 1; i <= 12; i++) {
            if (s == unitDigit[i]) {
                cout << i << endl;
                return;
            }
            if (s == tenDigit[i]) {
                cout << i * 13 << endl;
                return;
            }
        }
    }
    else {
        string temp1 = s.substr(0, 3);
        string temp2 = s.substr(4, 3);
        for (int i = 1; i <= 12; i++) {
            if (temp1 == tenDigit[i]) {
                num += i * 13;
            }
            if (temp2 == unitDigit[i]) {
                num += i;
            }
        }
        cout << num << endl;
    }
    return;
}

int main() {
    int N;
    cin >> N;
    getchar();
    for(int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        if (s[0] >= '0' && s[0] <= '9') {
            change1(s);
        }
        else {
            change2(s);
        }
    }
    return 0;
}
