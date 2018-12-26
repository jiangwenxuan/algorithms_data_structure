#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    int data;
    int height;
    node* lc;
    node* rc;
};
int data[25];

node* newNode(int x) {
    node* current = new node;
    current->data = x;
    current->lc = current->rc = NULL;
    current->height = 1;
    return current;
}

int getHeight(node* a) {
    if(a == NULL) {
        return 0;
    }
    return a->height;
}

int getBalanceFactor(node* a) {
    return getHeight(a->lc) - getHeight(a->rc);
}

void updataHeight(node* a) {
    a->height = max(getHeight(a->lc), getHeight(a->rc)) + 1;
}

void L(node* &root) {
    node* current = root->rc;
    root->rc = current->lc;
    current->lc = root;
    updataHeight(root);
    updataHeight(current);
    root = current;
}

void R(node* &root) {
    node* current = root->lc;
    root->lc = current->rc;
    current->rc = root;
    updataHeight(root);
    updataHeight(current);
    root = current;
}

void insert(node* &root, int x) {
    if(root == NULL) {
        root = newNode(x);
        return;
    }
    else if(x < root->data) {
        insert(root->lc, x);
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
        insert(root->rc, x);
        updataHeight(root);
        if(getBalanceFactor(root) == -2) {
            if(getBalanceFactor(root->rc) == -1) {
                L(root);
            }
            else if(getBalanceFactor(root->lc) == 1) {
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

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    node* root = create(data, n);
    printf("%d", root->data);
    return 0;
}
