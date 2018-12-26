#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool inq[1005];
vector<vector<int> > adj;

void bfs(int u) {
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        for(int i = 0; i < adj[top].size(); i++) {
            int w = adj[top][i];
            if(inq[w] == false) {
                inq[w] = true;
                q.push(w);
            }
        }
    }
}

int needRepair(int v) {
    int ans = 0;
    inq[v] = true;
    for(int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];
        if(inq[u] == false) {
            ans++;
            bfs(u);
        }
    }
    return ans - 1;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    adj.resize(n+1);
    int city1, city2;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &city1, &city2);
        adj[city1].push_back(city2);
        adj[city2].push_back(city1);
    }
    int city;
    for(int i = 0; i < k; i++) {
        fill(inq, inq + 1005, false);
        scanf("%d", &city);
        int a = needRepair(city);
        printf("%d\n", a);
    }
    return 0;
}
