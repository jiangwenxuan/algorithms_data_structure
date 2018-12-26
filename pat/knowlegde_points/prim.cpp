// visit[i] shows if i is in the tree
// d[s] shows the distance betweem s and unionS(don't visit)

const int maxv = 1000;
const int INF = 10000000;

// matrix

// n is the num of Vertex
int n;
int G[maxv][maxv];
int d[maxv];
bool visit[maxv] = {false};

int prim() {
	fill(d, d + maxv, INF);
	d[0] = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int u = -1;
		int MIN = INF;
		for(int j = 0; j < n; j++) {
			if(visit[j] == false && d[j] < INF) {
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) {
			return -1;
		}
		visit[u] = true;
		ans += d[u];
		for(int v = 0; v < n; v++) {
			if(visit[v] == false && G[u][v] != INF && d[v] > G[u][v]) {
				d[v] = G[u][v];
			}
		}
	}
	return ans;
}

// vector

struct node {
	int v;
	int weight;
};
vector<node> adj[maxv];
int n;
int d[maxv];
bool visit[maxv] = {false};

int prim() {
	fill(d, d + maxv, INF);
	d[0] = 0;
	int ans = 0;
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
			return -1;
		}
		visit[u] = true;
		ans += d[u];
		for(int v = 0; v < adj[u].size(); v++) {
			int w = adj[u][v].v;
			if(visit[w] == false && d[w] > adj[u][v].weight) {
				d[w] = adj[u][v].weight;
			}
		}
	}
	return ans;
}


// an example

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxv = 1000;
const int INF = 100000000;

// n is the num of vertex, m is the num of edge
int n, m;
int G[maxv][maxv];
int d[maxv];
bool visit[maxv];

int prim() {
	fill(d, d + maxv, INF);
	d[0] = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int u = -1;
		int MIN = INF;
		for(int j = 0; j < n; j++) {
			if(visit[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[u];
			}
		}
		if(u == -1) {
			return -1;
		}
		visit[u] = true;
		ans += d[u];
		for(int j = 0; j < n; j++) {
			if(visit[j] == false && G[u][j] != INF && G[u][j] < d[j]) {
				d[j] = G[u][j];
			}
		}
	}
	return ans;
}

int main() {
	int u, v, w;
	scanf("%d %d", &n, &m);
	fill(G[0], G[0] + maxv * maxv, INF);
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		G[u][v] = G[v][u] = w;
	}
	int ans = prim();
	printf("%d", ans);
	return 0;
}