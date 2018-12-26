#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 10010;
string str[maxn];

bool cmp(string s1, string s2) {
    return s1+s2 < s2+s1;
}

int main() {
    int n;
    string ans;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str+n, cmp);
    for(int i = 0; i < n; i++) {
        ans = ans + str[i];
    }
    while(ans.size() != 0 && ans[0] == '0') {
        ans.erase(ans.begin());
    }
    if(ans.size() == 0) {
        cout << 0;
    }
    else {
        cout << ans;
    }
    return 0;
}