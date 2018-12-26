#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
// can not use erase in a loop!!!
string dealString(string s) {
	for (string::iterator it = s.begin(); it != s.end(); it++) {
		if (*it > 'z' || *it < 'A') {
			s.erase(it);
		}
	}
	return s;
}

int main() {
	string s1, s2;
	map<string, int> m;
	do {
		cin >> s1;
		s2 = dealString(s1);
		++m[s2];
	} while (s1[s1.length() - 1] == '\n');
	int count = 0;
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
		if (it->second > count) {
			count = it->second;
			s2 = it->first;
		}
	}
	cout << s2 << ' ' << count << endl;
	return 0;
}
