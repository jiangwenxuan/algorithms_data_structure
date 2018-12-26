#include <iostream>
#include <string>
using namespace std;

int change(char c) {
	if(c >= '0' && c <= '9') {
        return c - '0';
	}
	if(c >= 'a' && c <= 'z') {
		return c - 'a' + 10;
	}
	if(c == '_') {
		return 36;
	}
	if(c == ' ') {
		return 37;
	}
	return 39;
}

int repeat[40] = {0};
int mark[40] = {0};
int tag[40] = {0};

int main() {
	int k;
	cin >> k;
	string str;
	string ans;
	string s;
	cin >> str;
	int current;
	int len = str.length();
	for(int i = 0; i < len; i++) {
		bool flag = true;
		if(i > len - k) {
			flag = false;
		}
		for(int j = i; j < i + k - 2 && flag == true; j++) {
			if(str[j] != str[j + 1]) {
				flag = false;
				break;
			}
		}
		if(flag == true) {
			current = change(str[i]);
			repeat[current] = 1;
			i = i + k - 1;
		}
		else {
			current = change(str[i]);
			mark[current] = 1;
		}
	}
	int j = 0;
	while(j < len) {
		current = change(str[j]);
		if(repeat[current] == 0 || (repeat[current] == 1 && mark[current] == 1)) {
			ans = ans + str[j];
			j++;
		}
		else {
			ans = ans + str[j];
			tag[current]++;
			if(tag[current] == 1) {
				s = s + str[j];
			}
			j = j + k;
		}
	}
	cout << s << endl << ans;
	return 0;
}
