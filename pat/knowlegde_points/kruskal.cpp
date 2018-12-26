#include <cstdio>
#include <algorithm>
using namespace std;

const int maxV = 100;
const int maxE = 10000;

struct edge {
	int u, v;
	int cost;
} E[maxE];

bool cmp(edge a, edge b) {
	return a.cost < b.cost;
}

int father[maxV];
int findFather(int x) {
	int a = x;
	while(x != father[x]) {
		x = father[x];
	}
	while(a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

// n = num of V, m = num of E
int kruskal(int n, int m) {
	int ans = 0;
	int numEdge = 0;
	for(int i = 0; i < n; i++) {
		father[i] = i;
	}
	sort(E, E + m, cmp);
	for(int i = 0; i < m; i++) {
		int faU = findFather(E[i].u);
		int faV = findFather(E[i].v);
		if(faU != faV) {
			father[faU] = faV;
			ans += E[i].cost;
			numEdge++;
			if(numEdge == n - 1) {
				break;
			}
		}
	}
	if(numEdge != n - 1) {
		return -1;
	}
	else {
		return ans;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].cost);
	}
	int ans = kruskal(n, m);
	printf("%d", ans);
	return 0;
}