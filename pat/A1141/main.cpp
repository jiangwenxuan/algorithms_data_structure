#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
	int score;
	int person;
	string institution;
};

map<string, node> mp;
vector<node> v;

bool cmp(node a, node b) {
	if(a.score != b.score) {
		return a.score > b.score;
	}
	else if(a.person != b.person) {
		return a.person < b.person;
	}
	else {
		return a.institution < b.institution;
	}
}

int main() {
    string a, b;
    int n, score;
    cin >> n;
    for(int i = 0; i < n; i++) {
    	cin >> a >> score >> b;
    	int len = b.length();
    	for(int j = 0; j < len; j++) {
    		if(b[j] >='A' && b[j] <= 'Z') {
    			b[j] = b[j] + 32;
    		}
    	}
    	if(a[0] == 'B') {
    		score = score * 2 / 3;
    	}
    	if(a[0] == 'T') {
    		score = score * 3 / 2;
    	}
    	if(mp.find(b) == mp.end()) {
    		node current;
    		current.score = score;
    		current.person = 1;
    		current.institution = b;
    		mp[b] = current;
    	}
    	else {
    		mp[b].score += score;
    		mp[b].person++;
    	}
    }
    map<string, node>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++) {
    	v.push_back(it->second);
    }
    sort(v.begin(), v.end(), cmp);
    int len = v.size();
    cout << len << endl;
    int j = 1;
    for(int i = 0; i < len; i++) {
    	if(i > 0 && v[i].score != v[i - 1].score) {
    		j = i + 1;
    	}
    	cout << j << " " << v[i].institution << " " << v[i].score << " " << v[i].person << endl;
    }
    return 0;
}
