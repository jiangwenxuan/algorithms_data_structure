#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[205];
int g[205][205] = {0};
vector<int> v;

bool notIn(int m) {
	int h = v.size();
	for(int i = 1; i < h; i++) {
		if(m == v[i]) {
			return false;
		}
	}
	return true;
}

int judge() {
	int len = v.size();
	for(int i = 0; i < len; i++) {
		for(int j = i + 1; j < len; j++) {
			int m = v[i];
			int n = v[j];
			if(g[m][n] != 1) {
				return 3;
			}
		}
	}
	int vertex = v[0];
	int l = adj[vertex].size();
	for(int i = 0; i < l; i++) {
		int m = adj[vertex][i];
		if(notIn(m) == true) {
			bool mark = true;
			for(int j = 1; j < len; j++) {
				if(g[m][v[j]] != 1) {
					mark = false;
					break;
				}
			}
			if(mark == true) {
				return 2;
			}
		}
	}
	return 1;
}

int main() {
	int n, e;
	scanf("%d %d", &n, &e);
	for(int i = 0; i < e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		g[a][b] = g[b][a] = g[a][a] = g[b][b] = 1;
	}
	for(int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	int m, k;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &k);
		v.clear();
		v.resize(k);
		for(int i = 0; i < k; i++) {
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		int ans = judge();
		if(ans == 1) {
			printf("Yes\n");
		}
		else if(ans == 2) {
			printf("Not Maximal\n");
		}
		else {
			printf("Not a Clique\n");
		}
	}
	return 0;
}
