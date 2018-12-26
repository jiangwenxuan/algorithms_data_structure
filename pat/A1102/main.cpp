#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int lc;
    int rc;
};
vector<node> tree;
vector<int> in;
vector<int> layer;

void inOrder(int root) {
    if(root == -1) {
        return;
    }
    inOrder(tree[root].lc);
    in.push_back(root);
    inOrder(tree[root].rc);
}

void layerOrder(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        layer.push_back(current);
        if(tree[current].lc != -1) {
            q.push(tree[current].lc);
        }
        if(tree[current].rc != -1) {
            q.push(tree[current].rc);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    tree.resize(n);
    vector<int> book(n);
    for(int i = 0; i < n; i++) {
        char a, b;
        scanf("%c %c", &a, &b);
        getchar();
        tree[i].rc = (a == '-' ? -1 : (a - '0'));
        tree[i].lc = (b == '-' ? -1 : (b - '0'));
        if(tree[i].lc != -1) {
            book[tree[i].lc] = 1;
        }
        if(tree[i].rc != -1) {
            book[tree[i].rc] = 1;
        }
    }
    int root;
    for(int i = 0; i < n; i++) {
        if(book[i] == 0) {
            root = i;
            break;
        }
    }
    inOrder(root);
    layerOrder(root);
    for(int i = 0; i < layer.size(); i++) {
        printf("%d%c", layer[i], i != layer.size()-1 ? ' ' : '\n');
    }
    for (int i = 0; i < in.size(); i++) {
        printf("%d%c", in[i], i != in.size() - 1 ? ' ' : '\n');
    }
    return 0;
}
