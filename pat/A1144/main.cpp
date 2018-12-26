#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> v;
map<int, bool> mp;

int main() {
	int n;
	scanf("%d", &n);
	int num;
	v.push_back(0);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		if(num > 0 && mp[num] == false) {
			v.push_back(num);
			mp[num] = true;
		}
	}
	sort(v.begin(), v.end());
	int len = v.size();
	if(len == 1) {
		printf("1");
	}
	else {
		for(int i = 1; i <= len; i++) {
			if(i != v[i]) {
				printf("%d", i);
				break;
			}
		}
	}
	return 0;
}
