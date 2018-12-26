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
bool root[15];

int findFather(int n) {
    int father;
    for(int i = 0; i < n; i++) {
        if(root[i] == false) {
            father = i;
        }
    }
    return father;
}

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
    bool flag1, flag2;
    scanf("%d", &n);
    getchar();
    tree.resize(n);
    for(int i = 0; i < n; i++) {
        char a, b;
        int A, B;
        scanf("%c %c", &a, &b);
        getchar();
        if(a == '-') {
            A = -1;
            flag1 = true;
        }
        else {
            A = a - '0';
        }
        if(b == '-') {
            B = -1;
            flag2 = true;
        }
        else {
            B = b - '0';
        }
        tree[i].lc = B;
        tree[i].rc = A;
        if(!flag1) {
            root[A] = true;
        }
        if(!flag2) {
            root[B] = true;
        }
    }
    int root = findFather(n);
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

