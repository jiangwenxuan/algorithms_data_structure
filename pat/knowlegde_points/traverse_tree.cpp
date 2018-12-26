#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    typename data;
    vector<int> child;
} Node[maxn];

int index = 0;
int newNode(int x) {
    Node[index].data = x;
    Node[index].child.clear();
    return index++;
}

void preOrder(int root) {
    visit(root);
    for(int i = 0; i < Node[root].child.size(); i++) {
        preOrder(Node[root].child[i]);
    }
}

void layerOrder(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        visit(now);
        for(int i = 0; i < Node[now].child.size(); i++) {
            q.push(Node[now].child[i]);
        }
    }
}

struct node {
    typename data;
    int layer;
    vector<int> child;
};

void layerOrder(int root) {
    queue<int> q;
    q.push(root);
    Node[root].layer = 0;
    while(!q.empty()) {
        int front = q.front();
        visit(front);
        q.pop();
        for(int i = 0; i < Node[front].child.size(); i++) {
            int current = Node[front].child[i];
            Node[current].layer = Node[front].layer++;
            q.push(current);
        }
    }
}