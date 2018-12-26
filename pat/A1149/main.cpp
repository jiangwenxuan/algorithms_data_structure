#include <cstdio>
#include <map>
#include <vector>
using namespace std;

vector<int> incom[100005];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		incom[a].push_back(b);
		incom[b].push_back(a);
	}
	for(int i = 0; i < m; i++) {
		int k;
		int current;
		bool flag = true;
		scanf("%d", &k);
		map<int, bool> mp;
		for(int j = 0; j < k; j++) {
			scanf("%d", &current);
			if(mp[current] != false) {
				flag = false;
			}
			if(incom[current].size() != 0) {
				for(int k = 0; k < incom[current].size(); k++) {
                    mp[incom[current][k]] = true;
				}
			}
		}
		if(flag == false) {
			printf("No\n");
		}
		else {
			printf("Yes\n");
		}
	}
	return 0;
}
