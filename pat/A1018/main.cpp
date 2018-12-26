#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 10000000;
const int maxv = 505;
struct node {
	int v;
	int dis;
};
vector<node> adj[maxv];
int bikes[maxv];
int d[maxv];
int pre[maxv];
int takeBack[maxv];
bool visit[maxv] = {false};

void dijkstra(int s, int n, int c) {
	fill(d, d + maxv, INF);
	d[s] = 0;
	for(int i = 0; i <= n; i++) {
		pre[i] = i;
	}
	for(int i = 0; i < n; i++) {
		int u = -1;
		int MIN = INF;
		for(int j = 0; j < n; j++) {
			if(visit[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) {
			return;
		}
		visit[u] = true;
		for(int j = 0; j < adj[u].size(); j++) {
			int k = adj[u][j].v;
			if(visit[k] == false) {
				if(d[u] + adj[u][j].dis < d[k]) {
					d[k] = d[u] + adj[u][j].dis;
					pre[k] = u;
					takeBack[k] = takeBack[u] + (bikes[k] - c / 2);
				}
				if(d[u] + adj[u][j].dis == d[k]) {
					if(takeBack[u] + bikes[k] - c / 2 < takeBack[k] && takeBack[u] + bikes[k] - c / 2 > 0) {
						takeBack[k] = takeBack[u] + bikes[k] - c / 2;
						pre[k] = u;
					}
					if(takeBack[u] + bikes[k] - c / 2 > takeBack[k] && takeBack[u] + bikes[k] - c / 2 < 0) {
						takeBack[k] = takeBack[u] + bikes[k] - c / 2;
						pre[k] = u;
					}
				}
			}
		}
	}
}

void dfs(int s, int v) {
	if(s == v) {
		printf("%d", s);
		return;
	}
	dfs(s, pre[v]);
	printf("->%d", v);
}

int main() {
	int c, n, target, m;
	scanf("%d %d %d %d", &c, &n, &target, &m);
	int u, v, w;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &bikes[i]);
	}
	bikes[0] = 0;
	for(int i = 0; i < m; i++) {
		node current;
		scanf("%d %d %d", &u, &v, &w);
		current.v = v;
		current.dis = w;
		adj[u].push_back(current);
		current.v = u;
		adj[v].push_back(current);
	}
	dijkstra(0, n, c);
	int a = takeBack[target];
	printf("%d ", abs(a));
	dfs(0, target);
	if(a < 0) {
		a = 0;
	}
	printf(" %d", a);
	return 0;
}
