#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

// d[i] is the shortest distance between i and s
// visit[i] means if we have visit i

const int maxv = 1000;
const int INF = 100000000;

// 1.matrix
// n is the number of the vertexs
int n, G[maxv][maxv];
int d[maxv];
bool visit[maxv];

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
		for(int v = 0; v < n; v++) {
			if(visit[v] == false && G[u][v] != INF && G[u][v] + d[u] < d[v]) {
				d[v] = d[u] + G[u][v];
			}
		}
	}
}

// 2.adj table

struct node {
	int v;
	int dis;
};
vector<node> adj[maxv];
int n;
int d[maxv];
bool visit[maxv] = {false};

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
			int v = adj[u][j].v;
			if(visit[v] == false && d[u] + adj[u][j].dis < d[v]) {
				d[v] = d[u] + adj[u][j].dis;
			}
		}
	}
}

// an example, print the shortest dis between v0 to vi
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxv = 1000;
const int INF = 10000000;
// n is the num of vertex, m is the num of edge
int n;   
int m;
int G[maxv][maxv];
int d[maxv];
bool visit[maxv] = {false};

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
		for(int j = 0; j < n; j++) {
			if(visit[j] == false && G[u][j] != INF && G[u][j] + d[u] < d[j]) {
				d[j] = d[u] + G[u][j];
			}
		}
	}
}

int main() {
	int s;
	scanf("%d %d %d", &n, &m, &s);
	int u, v, w;
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		G[u][v] = w;
	}
	dijkstra(s);
	for(int i = 0; i < n; i++) {
		printf("%d\n", d[i]);
	}
	return 0;
}

// dijkstra pro (*^_^*)
// if we want to know all the vertex from s to v
// we can use a pre[i] to save the pre of i
// or we can add (int pre) into the struct node
// struct node {
// 	int v;
// 	int dis;
// 	int pre;
// };

int n, G[maxv][maxv];
int d[maxv];
int pre[maxv];
bool visit[maxv] = {false};

void dijkstra(int s) {
	fill(d, d + maxv, INF);
	// init the pre[i]
	for(int i = 0; i < n; i++) {
		pre[i] = i;
	}
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
		for(int v = 0; v < n; v++) {
			if(visit[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v];
				pre[v] = u;
			}
		}
	}
}

void dfs(int v, int s) {
	if(v == s) {
		printf("%d ", s);
		return;
	}
	dfs(pre[v], s);
	printf("%d ", v);
}