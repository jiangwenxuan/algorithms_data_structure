#include <cstdio>
#include <vector>
#include <vector>
using namespace std;

int start, destination;
bool visit[10005];
int G[10005][10005];
struct station {
	int id;
	vector<int> next;
};
station sta[10005];

vector<int> temp, path;
int optValue, optLen;
void dfs(int s) {
	visit[s] = true;
	if(s == destination) {
		temp.push_back(s);
		int transfer = 1;
		for(int i = 0; i < temp.size() - 2; i++) {
			int a = temp[i];
			int b = temp[i + 1];
			int c = temp[i + 2];
			if(G[a][b] != G[b][c]) {
				transfer++;
			}
		}
		if(temp.size() < path.size()) {
			path = temp;
			optLen = temp.size();
			optValue = transfer;
		}
		else if(temp.size() == path.size()) {
			if(optValue > transfer) {
				optValue = transfer;
				path = temp;
			}
		}
		visit[s] = false;
		temp.pop_back();
		return;
	}
	temp.push_back(s);
	if(temp.size() < optLen) {
		for(int i = 0; i < sta[s].next.size(); i++) {
			if(visit[sta[s].next[i]] == false) {
				dfs(sta[s].next[i]);
			}
		}
	}
	visit[s] = false;
	temp.pop_back();
}

int main() {
	int n, m, k;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &m, &a);
		for(int j = 1; j < m; j++) {
			scanf("%d", &b);
			sta[a].next.push_back(b);
			sta[b].next.push_back(a);
			G[a][b] = G[b][a] = i;
			b = a;
		}
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		temp.clear();
		scanf("%d %d", &start, &destination);
		optLen = optValue = 1000000;
		fill(visit, visit + 10005, false);
		dfs(start);
		printf("%d\n", optLen - 1);
		vector<int> tran, line;
		line.push_back(G[path[0]][path[1]]);
		tran.push_back(start);
		for(int j = 0; j < path.size() - 2; j++) {
			int a = path[j];
			int b = path[j + 1];
			int c = path[j + 2];
			if(G[a][b] != G[b][c]) {
				tran.push_back(b)
				line.push_back(G[b][c]);
			}
		}
		tran.push_back(destination);
		for(int j = 0; j < optValue; j++) {
			printf("Take Line#%d from %04d to %04d.\n", line[j], tran[j], tran[j + 1]);
		}
	}
	return 0;
}