#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    node* lc;
    node* rc;
};
node* root = NULL;
queue<int> m;
int post[35];
int in[35];

node* create(int postL, int postR, int inL, int inR) {
    if(postL > postR) {
        return NULL;
    }
    node* root = new node;
    root->data = post[postR];
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == post[postR]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lc = create(postL, postL+numLeft-1, inL, k-1);
    root->rc = create(postL+numLeft, postR-1, k+1, inR);
    return root;
}

void levelOrder(node* root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* now = q.front();
        q.pop();
        m.push(now->data);
        if(now->lc != NULL) {
            q.push(now->lc);
        }
        if(now->rc != NULL) {
            q.push(now->rc);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    root = create(0, n-1, 0, n-1);
    levelOrder(root);
    printf("%d", m.front());
    m.pop();
    while(!m.empty()) {
        printf(" %d", m.front());
        m.pop();
    }
    return 0;
}
