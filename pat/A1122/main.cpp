#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int g[205][205];
vector<int> v;
bool visit[205] = {false};

int main() {
	int n, e;
	scanf("%d %d", &n, &e);
	int v1, v2;
	fill(g[0], g[0] + 205 * 205, 0);
	for(int i = 0; i < e; i++) {
		scanf("%d %d", &v1, &v2);
		g[v1][v2] = 1;
		g[v2][v1] = 1;
	}
	int m;
	scanf("%d", &m);
	int k;
	for(int i = 0; i < m; i++) {
        bool flag1 = true;
        bool flag2 = true;
		v.clear();
		scanf("%d", &k);
		v.resize(k);
		fill(visit, visit + 205, false);
		for(int j = 0; j < k; j++) {
			scanf("%d", &v[j]);
			visit[v[j]] = true;
		}
		for(int i = 1; i <= n; i++) {
            if(visit[i] == false) {
                flag2 = false;
            }
		}
		if(k != n + 1 || v[0] != v[k-1] || flag2 == false) {
			printf("NO\n");
		}
		else {
			for(int j = 1; j < k; j++) {
				v1 = v[j - 1];
				v2 = v[j];
				if(g[v1][v2] == 0) {
					flag1 = false;
					break;
				}
			}
			if(flag1 == true) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}
