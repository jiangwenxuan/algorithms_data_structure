#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 40;
struct node {
    int data;
    node* lc, rc;
};
int pre[maxn], in[maxn], post[maxn];
int n;
vector<int> ans;

node* create(int preL, int preR, int inL, int inR) {
    if(preL > preR) {
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
}

void postOrder(node* root) {
    if(root == NULL) {
        return;
    }
    postOrder(root->lc);
    postOrder(root->rc);
    ans.push_back(root->data);
}

int main() {
    scanf("%d", &n);
    char s[5];
    stack<int> st;
    int x, preIndex = 0, inIndex = 0;
    for(int i = 0; i < 2 * n; i++) {
        scanf("%s", s);
        if(strcmp(s, "Push") == 0) {
            scanf("%d", &x);
            pre[preIndex] = x;
            preIndex++;
            st.push(x);
        }
        else {
            in[inIndex] = st.top();
            inIndex++;
            st.pop();
        }
    }
    node* root = create(0, n-1, 0, n-1);
    postOrder(root);
    printf("%d", ans[0]);
    for(int i = 1; i < ans.size(); i++) {
        printf(" %d", ans[i]);
    }
    return 0;
}