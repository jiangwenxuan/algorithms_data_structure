#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxv = 505;
const int INF = 10000000;

struct node {
	int v;
	int dis;
};
int n, m, Cmax, Sp, numPath = 0;
int weight[maxv];
vector<node> adj[maxv];
int d[maxv];
int minNeed = INF;
int minRemain = INF;
bool visit[maxv] = {false};
vector<int> pre[maxv];
vector<int> tempPath, path;

void dijkstra(int s) {
	fill(d, d + maxv, INF);
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
		for(int j = 0; j < adj[u].size(); j++) {
			int k = adj[u][j].v;
			if(visit[k] == false) {
				if(d[u] + adj[u][j].dis < d[k]) {
					d[k] = d[u] + adj[u][j].dis;
					pre[k].clear();
					pre[k].push_back(u);
				}
				else if(d[u] + adj[u][j].dis == d[k]) {
					pre[k].push_back(u);
				}
			}
		}
	}
}

void dfs(int v) {
	if(v == 0) {
		tempPath.push_back(v);
		int need = 0;
		int remain = 0;
		for(int i = tempPath.size()-1; i >= 0; i--) {
			int id = tempPath[i];
			if(weight[id] > 0) {
				remain += weight[id];
			}
			else {
				if(remain > abs(weight[id])) {
					remain -= abs(weight[id]);
				}
				else {
					need += abs(weight[id]) - remain;
					remain = 0;
				}
			}
		}
		if(need < minNeed) {
			minNeed = need;
			minRemain = remain;
			path = tempPath;
		}
		else if(need == minNeed && remain < minRemain) {
			minRemain = remain;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	tempPath.pop_back();
}

int main() {
	scanf("%d %d %d %d", &Cmax, &n, &Sp, &m);
	int u, v, w;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &weight[i]);
		weight[i] -= (Cmax / 2);
	}
	for(int i = 0; i < m; i++) {
		node current;
		scanf("%d %d %d", &u, &v, &w);
		current.v = u;
		current.dis = w;
		adj[v].push_back(current);
		current.v = v;
		adj[u].push_back(current);
	}
	dijkstra(0);
	dfs(Sp);
	printf("%d ", minNeed);
	for(int i = path.size() - 1; i >= 0; i--) {
		printf("%d", path[i]);
		if(i > 0) {
			printf("->");
		}
	}
	printf(" %d", minRemain);
	return 0;
}
