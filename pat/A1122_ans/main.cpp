#include <iostream>
#include <set>
#include <vector>
using namespace std;

int a[210][210] = {0};

int main() {
	int n, m;
	int cnt, k;
	scanf("%d %d", &n, &m);
	for(int i = ; i < m; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		a[t1][t2] = a[t2][t1] = 1;
	}
	scanf("%d", &cnt);
	while(cnt--) {
		scanf("%d", &k);
		vector<int> v(k);
		set<int> s;
		int flag1 = 1;
		int flag2 = 1;
		for(int i = 0; i < k; i++) {
			scanf("%d", &v[i]);
			s.insert(v[i]);
		}
		if(s.size() != n || k - 1 != n || v[0] != v[k - 1]) {
			flag1 = 0;
		}
		for(int i = 0; i < k - 1; i++) {
			if(a[v[i]][v[i + 1]] == 0) {
				flag2 = 0;
				break;
			}
		}
		printf("%s", flag1 && flag2 ? "YES\n" : "NO\n");
	}
	return 0;
}