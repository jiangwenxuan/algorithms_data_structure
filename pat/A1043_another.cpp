#include <cstdio>
#include <vector>
using namespace std;

struct node {
    int data;
    node* lc, rc;
};

void insert(node* &root, int data) {
    if(root == NULL) {
        root = new node;
        root->data = data;
        root->lc = root->rc = NULL;
        return;
    }
    if(data < root->data) {
        insert(root->lc, data);
    }
    else {
        insert(root->rc, data);
    }
}

void preOrder(node* root, vector<int>& vi) {
    if(root == NULL) {
        return;
    }
    vi.push_back(root->data);
    preOrder(root->lc, vi);
    preOrder(root->rc, vi);
}