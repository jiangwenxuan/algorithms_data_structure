#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int v;
    int w;
};
const int maxV = 1000;
const int inF = 10000000000;

// DFS

// 1: matrix

int n, G[maxV][maxV];
bool visit[maxV] = {false};

void dfs(int u, int depth) {
    visit[u] = true;
    for(int i = 0; i < n; i++) {
        if(visit[i] == false && G[u][i] != inF) {
            dfs(i, depth+1);
        }
    }
}

void dfsTraverse() {
    for(int i = 0; i < n; i++) {
        if(visit[i] == false) {
            dfs(i, 1);
        }
    }
}

// 2: linked list

vector<int> adj[maxV];
int n;
bool visit[maxV] = {false};

void DFS(int u, int depth) {
    visit[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(visit[v] == false) {
            DFS(v, depth+1);
        }
    }
}

void DFSTraverse() {
    for(int i = 0; i < n; i++) {
        if(visit[i] == false) {
            DFS(i, 1);
        }
    }
}


// BFS

// 1: matrix

int n, G[maxV][maxV];
bool inqueue[maxV];

void bfs(int u) {
    queue<int> q;
    q.push(u);
    inqueue[u] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v = 0; v < n; v++) {
            if(inqueue[v] == false && G[u][v] != inF) {
                q.push(v);
                inqueue[v] = true;
            }
        }
    }
}

void bfsTraverse() {
    for(int i = 0; i < n; i++) {
        if(inqueue[i] == false) {
            bfs(i);
        }
    }
}

// 2: linked list

vector<int> adj[maxV];
int n;
bool inq[maxV] = {false};

void bfs(int u) {
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int i = 0; i < adj[v].size()) {
            int w = adj[v][i];
            if(inq[w] == false) {
                q.push(w);
                inq[w] = true;
            }
        }
    }
}

void bfsTrave() {
    for(int i = 0; i < n; i++) {
        if(inq[i] == false) {
            bfs(i);
        }
    }
}

// bfs with layer

struct node {
    int v;
    int layer;
};

vector<node> adj[maxV];

void bfs(int s) {
    queue<node> q;
    node start;
    start.v = s;
    start.layer = 0;
    q.push(start);
    inq[start.v] = true;
    while(!q.empty()) {
        node topOne = q.front();
        q.pop();
        int u = topOne.v;
        for(int i = 0; i < adj[u].size(); i++) {
            node next = adj[u][i];
            next.layer = topOne.layer + 1;
            if(inq[next.v] == false) {
                q.push(next);
                inq[next.v] = true;
            }
        }
    }
} 