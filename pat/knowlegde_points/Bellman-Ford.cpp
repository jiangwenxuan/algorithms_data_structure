#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
	int v;
	int weight;
};
const int INF = 1000000;
const int maxv = 100;
vector<node> adj[maxv];
// n is the number of vertex, d[] save the shortest longth
int n;
int d[maxv];

bool bellman(int s) {
	fill(d, d + maxv, INF);
	d[s] = 0;
	for(int i = 0; i < n - 1; i++) {
		for(int u = 0; u < n; u++) {
			for(int j = 0; j < adj[u].size(); j++) {
				int v = adj[u][j].v;
				int dis = adj[u][j].weight;
				if(d[u] + dis < d[v]) {
					d[v] = d[u] + dis;
				}
			}
		}
	}
	for(int u = 0; u < n; u++) {
		for(int j = 0; j < adj[u].size(); j++) {
			int v = adj[u][j].v;
			int dis = adj[u][j].weight;
			if(dis + d[u] < d[v]) {
				return false;
			}
		}
	}
	return true;
}