#include <iostream>
#include <string>
#include <map>
using namespace std;

bool check(char c) {
	if(c >= '0' && c <= '9')
		return true;
	if(c >= 'a' && c <= 'z')
		return true;
	if(c >= 'A' && c <= 'Z')
		return true;
	return false;
}

int main() {
	map<string, int> m;
	string str;
	getline(cin, str);
	int i = 0;
	while(i < str.length()) {
		string word;
		while(i < str.length() && check(str[i])) {
			if(str[i] >= 'A' && str[i] <= 'Z') {
				str[i] += 32;
			}
			word += str[i];
			i++;
		}
		if(word != " ") {
			if(m.find(word) == m.end()) {
				m[word] = 1;
			}
			else {
				m[word]++;
			}
		}
		while(i < str.length() && check(str[i]) == false) {
			i++;
		}		
	}
	string ans;
	int Max;
	for(map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
		if(it->second > Max) {
			ans = it->first;
			Max = it->second;
		}
	}
	cout << ans << " " << endl;
	return 0;
}