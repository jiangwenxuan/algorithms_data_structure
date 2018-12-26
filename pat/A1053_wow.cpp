#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 105;
struct node {
    int weight;
    vector<int> child;
} Node[maxn];

bool cmp(int a, int b) {
    return Node[a].weight > Node[b].weight;
}

int n, m, S;
int path[maxn];

void dfs(int index, int numNode, int sum) {
    if(sum > S) {
        return;
    }
    if(sum == S) {
        if(Node[index].child.size() != 0) {
            return;
        }
        for(int i = 0; i < numNode; i++) {
            printf("%d%c", Node[path[i]].weight, i != numNode-1 ? ' ' : '\n');
        }
        return;
    }
    for(int i = 0; i < Node[index].child.size(); i++) {
        int child = Node[index].child[i];
        path[numNode] = child;
        dfs(child, numNode+1, sum+Node[child].weight);
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &S);
    for(int i = 0; i < n; i++) {
        scanf("%d", &Node[i].weight);
    }
    int id, k, child;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &id, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &child);
            Node[id].child.push_back(child);
        }
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);
    }
    path[0] = 0;
    dfs(0, 1, Node[0].weight);
    return 0;
}
