#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000;

int n, m;
struct node {
	int v;
	int length;
	int time;
};
vector<node> adj[520];
int d[505];
int d1[505];
bool visit[505];
int pre[505];
int pre2[505];
int fastTime[505];
int passNode[505];
vector<int> v1;
vector<int> v2;

void dijkstra1(int s) {
	fill(d, d + 505, INF);
	fill(visit, visit + 505, false);
	fill(fastTime, fastTime + 505, INF);
	for(int i = 0; i < n; i++) {
		pre[i] = i;
	}
	d[s] = 0;
	fastTime[s] = 0;
	for(int i = 0; i < n; i++) {
		int u = -1;
		int MIN = INF;
		for(int j = 0; j < n; j++) {
			if(visit[j] == false && d[j] < MIN) {
				MIN = d[j];
				u = j;
			}
		}
		if(u == -1) {
			return;
		}
		visit[u] = true;
		for(int j = 0; j < adj[u].size(); j++) {
			int v = adj[u][j].v;
			if(visit[v] == false) {
                if(d[v] > d[u] + adj[u][j].length) {
                    fastTime[v] = fastTime[u] + adj[u][j].time;
                    d[v] = d[u] + adj[u][j].length;
                    pre[v] = u;
                }
                else if(d[v] == d[u] + adj[u][j].length) {
                    if(fastTime[v] > fastTime[u] + adj[u][j].time) {
                        pre[v] = u;
                        fastTime[v] = fastTime[u] + adj[u][j].time;
                    }
				}
			}
		}
	}
}

void dijkstra2(int s) {
	fill(d1, d1 + 505, INF);
	fill(passNode, passNode + 505, INF);
	fill(visit, visit + 505, false);
	for(int i = 0; i < n; i++) {
		pre2[i] = i;
	}
	d1[s] = 0;
	passNode[s] = 0;
	for(int i = 0; i < n; i++) {
		int u = -1;
		int MIN = INF;
		for(int j = 0; j < n; j++) {
			if(d1[j] < MIN && visit[j] == false) {
				u = j;
				MIN = d1[j];
			}
		}
		if(u == -1) {
			return;
		}
		visit[u] = true;
		for(int j = 0; j < adj[u].size(); j++) {
			int v = adj[u][j].v;
			if(visit[v] == false) {
				if(d1[v] > d1[u] + adj[u][j].time) {
					d1[v] = d1[u] + adj[u][j].time;
					pre2[v] = u;
					passNode[v] = passNode[u] + 1;
				}
				else if(d1[v] == d1[u] + adj[u][j].time) {
					if(passNode[v] > passNode[u] + 1) {
						passNode[v] = passNode[u] + 1;
						pre2[v] = u;
					}
				}
			}
		}
	}
}

void dfs1(int source, int destination) {
	if(destination == source) {
		v1.push_back(source);
		return;
	}
	else {
		dfs1(source, pre[destination]);
		v1.push_back(destination);
	}
}

void dfs2(int source, int destination) {
	if(destination == source) {
		v2.push_back(source);
	}
	else {
		dfs2(source, pre2[destination]);
		v2.push_back(destination);
	}
}

void myPrint1() {
	printf("%d", v1[0]);
	for(int i = 1; i < v1.size(); i++) {
		printf(" -> %d", v1[i]);
	}
}
void myPrint2() {
	printf("%d", v2[0]);
	for(int i = 1; i < v2.size(); i++) {
		printf(" -> %d", v2[i]);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	int s1, s2;
	int ifOneWay, length, time;
	node current;
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d %d %d", &s1, &s2, &ifOneWay, &length, &time);
		current.v = s2;
		current.length = length;
		current.time = time;
        adj[s1].push_back(current);
		if(ifOneWay != 1) {
			current.v = s1;
			adj[s2].push_back(current);
		}
	}
	int source, destination;
	scanf("%d %d", &source, &destination);
	dijkstra1(source);
	dijkstra2(source);
	dfs1(source, destination);
	dfs2(source, destination);
	bool flag = true;
	if(v1.size() != v2.size()) {
		flag = false;
	}
	for(int i = 0; i < v1.size() && flag == true; i++) {
		if(v1[i] != v2[i]) {
			flag = false;
			break;
		}
	}
	if(flag == true) {
		printf("Distance = %d; Time = %d: ", d[destination], d1[destination]);
		myPrint1();
	}
	else {
		printf("Distance = %d: ", d[destination]);
		myPrint1();
		printf("\n");
		printf("Time = %d: ", d1[destination]);
		myPrint2();
	}
	return 0;
}
