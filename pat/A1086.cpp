#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct node {
    int lOrR;
    int lc = -1;
    int rc = -1;
};
node tree[35];
vector<int> ans;

void postOrder(int i) {
    if(tree[i].lc == -1 && tree[i].rc == -1) {
        return;
    }
    postOrder(tree[i].lc);
    postOrder(tree[i].rc);
    ans.push_back(i);
}

int main() {
    int n, x;
    scanf("%d", &n);
    char a[5];
    vector<int> m;
    for(int i = 0; i < n; i++) {
        scanf("%s", &a);
        if(strcmp(a, "Push") == 0) {
            scanf("%d", &x);
            m.push_back(x);
            tree[x].lOrR = 1;
        }
        else {
            int child = m.front();
            m.pop_back();
            int father = m.front();
            if(tree[father].lOrR == 1) {
                tree[father].lc = child;
                tree[father].lOrR = 2;
            }
            else {
                tree[father].rc = child;
            }
        }
    }
    postOrder(1);
    printf("%d", ans[0]);
    for(int i = 1; i < m.size(); i++) {
        printf(" %d", ans[i]);
    }
    return 0;
}
