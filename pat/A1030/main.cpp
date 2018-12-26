#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxv = 510;
const int INF = 10000000;
struct node {
	int v;
	int dis;
	int cost;
};
vector<node> adj[maxv];
bool visit[maxv];
int d[maxv];
int travelCost[maxv];
int pre[maxv];

void dijkstra(int s, int n) {
	fill(d, d + maxv, INF);
	fill(travelCost, travelCost + maxv, INF);
	for(int i = 0; i < n; i++) {
		pre[i] = i;
	}
	travelCost[s] = 0;
	d[s] = 0;
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

		for(int k = 0; k < adj[u].size(); k++) {
			int h = adj[u][k].v;
			if(visit[h] == false) {
				if(d[u] + adj[u][k].dis < d[h]) {
					d[h] = d[u] + adj[u][k].dis;
					travelCost[h] = travelCost[u] + adj[u][k].cost;
					pre[h] = u;
				}
				else if(d[u] + adj[u][k].dis == d[h]) {
					if(travelCost[u] + adj[u][k].cost < travelCost[h]) {
						travelCost[h] = travelCost[u] + adj[u][k].cost;
						pre[h] = u;
					}
				}
			}
		}
	}
}

void dfs(int s, int v) {
	if(s == v) {
		printf("%d ", s);
		return;
	}
	dfs(s, pre[v]);
	printf("%d ", v);
}

int main() {
	int n, m, start, destination;
	scanf("%d %d %d %d", &n, &m, &start, &destination);
	int u, v, w, c;
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d %d", &u, &v, &w, &c);
		node current;
		current.v = v;
		current.dis = w;
		current.cost = c;
		adj[u].push_back(current);
		current.v = u;
		adj[v].push_back(current);
	}
	dijkstra(start, n);
	dfs(start, destination);
	printf("%d %d", d[destination], travelCost[destination]);
	return 0;
}
