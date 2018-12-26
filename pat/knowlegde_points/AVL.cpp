#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    int data;
    node* lc, rc;
    int height;
};

node* newNode(int x) {
    node* Node = new node;
    Node->data = x;
    Node->lc = Node->rc = NULL;
    Node->height = 1;
    return Node;
}

int getHeight(node* root) {
    if(root == NULL) {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(node* root) {
    return getHeight(root->lc) - getHeight(root->rc);
}

void updataHeight(node* root) {
    root->height = max(root->lc->height, root->rc->height) + 1;
}

void search(node* root, int x) {
    if(root == NULL) {
        printf("failed");
        return;
    }
    if(x == root->data) {
        printf("%d", root->data);
    }
    if(x > root->data) {
        search(root->rc, x);
    }
    if(x < root->data) {
        search(root->lc, x);
    }
}

void L(node* &root) {
    node* temp = root->rc;
    root->rc = temp->lc;
    temp->lc = root;
    updataHeight(root);
    updataHeight(temp);
    root = temp;
}

void R(node* &root) {
    node* temp = root->lc;
    root->lc = temp->rc;
    temp->rc = root;
    updataHeight(root);
    updataHeight(temp);
    root = temp;
}

void insert(node* &root, int v) {
    if(root == NULL) {
        root = newNode(v);
        return;
    }
    if(v < root->data) {
        insert(root->lc, v);
        updataHeight(root);
        if(getBalanceFactor(root) == 2) {
            if(getBalanceFactor(root->lc) == 1) {
                R(root);
            }
            else if(getBalanceFactor(root->lc) == -1) {
                L(root->lc);
                R(root);
            }
        }
    }
    else {
        insert(root->rc, v);
        updataHeight(root);
        if(getBalanceFactor(root) == -2) {
            if(getBalanceFactor(root->rc) == -1) {
                L(root);
            }
            else if(getBalanceFactor(root->rc) == 1) {
                R(root->rc);
                L(root);
            }
        }
    }
}

node* create(int data[], int n) {
    node* root = NULL;
    for(int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}