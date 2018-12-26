#include <cstdio>
#include <vector>
using namespace std;

vector<int> adj[505];
bool visit[505] = {false};
int cnt = 0;

void dfs(int v) {
    visit[v] = true;
    cnt++;
    for(int i = 0; i < adj[v].size(); i++) {
        if(visit[adj[v][i]] == false) {
            dfs(adj[v][i]);
        }
    }
}

int main() {
	int n, m;
	int v1, v2;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &v1, &v2);
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	int j = 0;
	int flag = 0;
	for(int i = 1; i <= n; i++) {
		if(i != 1) {
			printf(" ");
		}
		j = adj[i].size();
		printf("%d", j);
		if(j % 2 == 0) {
			flag++;
		}
	}
	printf("\n");
	dfs(1);
	if(flag == n && cnt == n) {
		printf("Eulerian");
	}
	else if(flag == n - 2 && cnt == n) {
		printf("Semi-Eulerian");
	}
	else {
		printf("Non-Eulerian");
	}
	return 0;
}
