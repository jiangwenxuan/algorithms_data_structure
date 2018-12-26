#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

const int maxV = 1000;
vecetor<vector<int> > adj;
int n, m;
int inDegree[maxV];
vector<int> topoloSort;

bool topologicalSort() {
    int num = 0;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        topoloSort.push_back(u);
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0) {
                q.push(v);
            }
        }
//        adj[u].clear();
        num++;
    }
    if(n == num) {
        return true;
    }
    else {
        return false;
    }
}