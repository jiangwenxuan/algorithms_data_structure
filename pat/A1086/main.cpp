#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

struct node {
    int data;
    node* lc;
    node* rc;
};
vector<int> pre, in, post, ans;

void postOrder(node* root) {
    if(root == NULL) {
        return;
    }
    postOrder(root->lc);
    postOrder(root->rc);
    ans.push_back(root->data);
}

node* change(int preL, int preR, int inL, int inR) {
    if(preL > preR) {
        return NULL;
    }
    node* root = new node;
    root->data = pre[preL];
    int i;
    for(i = inL; i <= inR; i++) {
        if(in[i] == pre[preL]) {
            break;
        }
    }
    int numL = i - inL;
    root->lc = change(preL+1, preL+numL, inL, i-1);
    root->rc = change(preL+numL+1, preR, i+1, inR);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    int x;
    char a[5];
    stack<int> m;
    for(int i = 0; i < 2 * n; i++) {
        scanf("%s", &a);
        if(strcmp(a, "Push") == 0) {
            scanf("%d", &x);
            pre.push_back(x);
            m.push(x);
        }
        else {
            in.push_back(m.top());
            m.pop();
        }
    }
    node* root = change(0, n-1, 0, n-1);
    postOrder(root);
    printf("%d", ans[0]);
    for(int i = 1; i < ans.size(); i++) {
        printf(" %d", ans[i]);
    }
    return 0;
}
