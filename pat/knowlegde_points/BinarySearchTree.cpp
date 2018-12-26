#include <iostream>
using namespace std;

struct node {
    int data;
    node* lc;
    node* rc;
};
node* root = NULL;

void search(node* root, int x) {
    if(root == NULL) {
        printf("search failed");
        return;
    }
    if(x == root->data) {
        printf("%d\n", root->data);
    }
    else if(x < root->data) {
        search(root->lc, x);
    }
    else {
        search(root->rc, x);
    }
}

node* newNode(int x) {
    node* root = new node;
    root->data = x;
    root->lc = root->rc == NULL;
    return root;
}

// recursion insert
void insert(node* &root, int x) {
    if(root == NULL) {
        root = newNode(x);
        return;
    }
    if(x == root->data) {
        return;
    }
    else if(x < root->data) {
        insert(root->lc, x);
    }
    else {
        insert(root->rc, x);
    }
}

// iteration insert
void insert_iteration(node* &root, int h) {
    node* y = NULL;
    node* x = root;
    while(root != NULL) {
        y = x;
        if(root->data > h) {
            x = x->lc;
        }
        else {
            x = x->rc;
        }
    }
    if(y == NULL) {
        root = newNode(h);
    }
    else if(y->data > x) {
        y->lc = newNode(h);
    }
    else {
        y->rc = newNode(h);
    }
}

node* create(int data[], int n) {
    node* root = NULL;
    for(int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}

node* findMax(node* root) {
    while(root->rc != NULL) {
        root = root->rc;
    }
    return root;
}

node* findMin(node* root) {
    while(root->lc != NULL) {
        root = root->lc;
    }
    return root;
}

void deleteNode(node* &root, int x) {
    if(root == NULL) {
        return;
    }
    if(root->data == x) {
        if(root->lc == NULL && root->rc == NULL) {
            root = NULL;
        }
        else if(root->lc != NULL) {
            node* pre = findMax(root->lc);
            root->data = pre->data;
            deleteNode(root->lc, pre->data);
        }
        else {
            node* next = findMin(root->rc);
            root->data = next->data;
            deleteNode(root->rc, next->data);
        }
    }
    else if(root->data > x) {
        deleteNode(root->lc, x);
    }
    else {
        deleteNode(root->rc, x);
    }
}