#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct node {
	string id;
	int midG;
	int finalG;
	int g;
	int assignments;
};

map<string, node> mp;
vector<node> v;

bool cmp(node a, node b) {
	if(a.g != b.g) {
		return a.g > b.g;
	}
	else {
		return a.id < b.id;
	}
}

int main() {
	int p, m, n;
	cin >> p >> m >> n;
	string a;
	int b;
	map<string, node>::iterator it;
	for(int i = 0; i < p; i++) {
		node current;
		cin >> a >> b;
		current.assignments = b;
		current.id = a;
		current.midG = current.finalG = 0;
		mp[a] = current;
	}
	for(int i = 0; i < m; i++) {
		node current;
		cin >> a >> b;
		if(mp.find(a) != mp.end()) {
			mp[a].midG = b;
		}
	}
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		if(mp.find(a) != mp.end()) {
			mp[a].finalG = b;
		}
	}
	for(it = mp.begin(); it != mp.end(); it++) {
		if(it->second.midG > it->second.finalG) {
			it->second.g = (int)((0.4 * it->second.midG) + (0.6 * it->second.finalG) + 0.5);
		}
		else {
			it->second.g = it->second.finalG;
		}
		if(it->second.midG == 0) {
			it->second.midG = -1;
		}
		if(it->second.g >= 60 && it->second.assignments >= 200) {
			v.push_back(it->second);
		}
	}
	sort(v.begin(), v.end(), cmp);
	int len = v.size();
	for(int i = 0; i < len; i++) {
		cout << v[i].id << " " << v[i].assignments << " " << v[i].midG << " " << v[i].finalG << " " << v[i].g << endl;
	}
	return 0;
}
