#include <iostream>
#include <queue>
using namespace std;

struct node {
    typename data;
    int layer;
    node* lc;
    node* rc;
};

node* root = NULL;

node* newNode(int x) {
    node* Node = new node;
    Node->data = x;
    Node->lc = Node->rc = NULL;
    return Node;
}

void search(node* root, int x, int newData) {
    if(root = NULL) {
        return;
    }
    if(root->data == x) {
        root->data = newData;
    }
    search(root->lc, x, newData);
    search(root->rc, x, newData);
}

void insert(node* &root, int x) {
    if(root == NULL) {
        root = newNode(x);
        return;        
    }
    if(according to tree) {
        insert(root->lc, x);
    }
    else {
        insert(root->rc, x);
    }
}

void preorder(node* root) {
    if(root == NULL) {
        return;
    }
    visit(root->data);
    preorder(root->lc);
    preorder(root->rc);
}

void layerOrder(node* root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* now = q.front();
        q.pop();
        visit(now->data);
        if(now->lc != NULL) {
            q.push(now->lc);
        }
        if(now->rc != NULL) {
            q.push(now->rc);
        }
    }
}

void LayerOrder(node* root) {
    queue<node*> q;
    root->layer = 1;
    q.push(root);
    while(!q.empty()) {
        node* now = q.front();
        q.pop();
        visit(now);
        if(now->lc != NULL) {
            now->lc->layer = now->layer + 1;
            q.push(now->lc);
        }
        if(now->rc != NULL) {
            now->rc->layer = now->layer + 1;
            q.push(now->rc);
        }
    }
}

// given a preorder and a midorder, we can build the tree

node* create(int preL, int preR, int inL, int intR) {
    if(preL < preR) {
        return NULL;
    }
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == pre[preL]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lc = create(preL+1, preL+numLeft, inL, k-1);
    root->rc = create(preL+numLeft+1, preR, k+1, inR);
    return root;
}

// static create a tree
struct node {
    typename data;
    int lc;
    int rc;
} Node[maxn];
int index = 0;
int newNode(int x) {
    Node[index] = x;
    Node[index].lc = Node[index].rc = -1;
    return index++;
}

void search(int root, int x, int newData) {
    if(root == -1) {
        return;
    }
    if(Node[root].data == x) {
        Node[root].data = newData;
    }
    search(Node[root].lc, x, newData);
    search(Node[root].rc, x, newData);
}

void insert(int &root, int x) {
    if(root == -1) {
        root = newNode(x);
        return;
    }
    if(base on feature of tree) {
        insert(Node[root].lc, x);
    }
    else {
        insert(Node[root].rc, x);
    }
}

int create(int data[], int n) {
    int root = -1;
    for(int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}

void preOrder(int root) {
    if(root == -1) {
        return;
    }
    visit(root);
    preOrder(Node[root].lc);
    preOrder(Node[root].rc);
}

void layerOrder(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        visit(new);
        if(Node[now].lc != -1) {
            q.push(Node[now].lc);
        }
        if(Node[now].rc != -1) {
            q.push(Node[now].rc);
        }
    }
}

