#include <iostream>
#include <string>
#include <map>
using namespace std;

string str[1005];

int main() {
	int m, n, s;
	map<string, int> mapp;
	cin >> m >> n >> s;
	for(int i = 1; i <= m; i++) {
		cin >> str[i];
		mapp[str[i]] = 0;
	}
	if(m < s) {
		cout << "Keep going..." << endl;
	}
	else {
		int i = s;
		while(i <= m) {
			if(mapp[str[i]] == 0) {
				cout << str[i] << endl;
				mapp[str[i]] = 1;
				i = i + n;
			}
			else {
				i++;
			}
		}
	}
	return 0;
}