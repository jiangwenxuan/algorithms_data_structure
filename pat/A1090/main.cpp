#include <cstdio>
#include <vector>
using namespace std;

struct node {
    vector<int> child;
};
vector<node> tree;
int ans = 0;
int times = 0;

void dfs(int x, int layer) {
    if(tree[x].child.size() == 0) {
        if (layer > ans) {
            ans = layer;
            times = 1;
        }
        else if (layer == ans) {
            times++;
        }
        return;
    }
    for(int i = 0; i < tree[x].child.size(); i++) {
        dfs(tree[x].child[i], layer+1);
    }
}

int main() {
    int n, root;
    double price, r;
    scanf("%d %lf %lf", &n, &price, &r);
    tree.resize(n);
    r = r / 100;
    int current;
    for(int i = 0; i < n; i++) {
        scanf("%d", &current);
        if(current != -1) {
            tree[current].child.push_back(i);
        }
        else {
            root = i;
        }
    }
    dfs(root, 0);
    for(int i = 0; i < ans; i++) {
        price = price * (1 + r);
    }
    printf("%.2lf %d", price, times);
    return 0;
}
