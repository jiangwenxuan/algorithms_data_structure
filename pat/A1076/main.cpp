#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[1005];
bool inq[1005] = {false};
int layer[1005] = {0};

int bfs(int v, int L) {
    int ans = 0;
    queue<int> q;
    q.push(v);
    inq[v] = true;
    layer[v] = 0;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        if(layer[current] > L) {
            break;
        }
        ans++;
        for(int i = 0; i < adj[current].size(); i++) {
            int u = adj[current][i];
            if(inq[u] == false) {
                inq[u] = true;
                layer[u] = layer[current] + 1;
                q.push(u);
            }
        }
    }
    return ans - 1;
}

int main() {
    int n, L;
    scanf("%d %d", &n, &L);
    int num, f;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &num);
        for(int j = 0; j < num; j++) {
            scanf("%d", &f);
            adj[f].push_back(i);
        }
    }
    int k, user;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &user);
        int ans = bfs(user, L);
        printf("%d\n", ans);
        for(int j = 1; j <= n; j++) {
            inq[j] = false;
            layer[j] = 0;
        }
    }
    return 0;
}
