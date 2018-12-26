#include <iostream>
#include <string>
using namespace std;

string deal(string str, int n, int& e) {
    int i = 0;
    while(str.length() > 0 && str[0] == '0') {
        str.erase(str.begin());
    }
    if(str[i] == '.') {
        str.erase(0, 1);
        while(str.length() > 0 && str[0] == '0') {
            str.erase(str.begin());
            e--;
        }
    }
    else {
        while(i < str.length() && str[i] != '.') {
            i++;
            e++;
        }
        if(i < str.length()) {
            str.erase(str.begin() + i);
        }
    }
    if(str.length() == 0) {
        e = 0;
    }
    int num = 0;
    i = 0;
    string ans;
    while(num < n) {
        if(i < str.length()) {
            ans += str[i];
            i++;
        }
        else {
            ans += '0';
        }
        num++;
    }
    return ans;
}

int main() {
    int n;
    string s1;
    string s2;
    cin >> n >> s1 >> s2;
    int e1 = 0;
    int e2 = 0;
    string s3 = deal(s1, n, e1);
    string s4 = deal(s2, n, e2);
    if(s3 == s4 && e1 == e2) {
        cout << "YES 0." << s3 << "*10^" << e1 << endl;
    }
    else {
        cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
    }
    return 0;
}
