#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node {
    double nowPrice;
    int num;
    vector<int> child;
};
vector<node> tree;
vector<int> book;
int n;
double price, r;

void layerOrder(int n) {
    queue<int> q;
    q.push(0);
    tree[0].nowPrice = price;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        for(int i = 0; i < tree[top].child.size(); i++) {
            int a = tree[top].child[i];
            tree[a].nowPrice = tree[top].nowPrice * (1 + r / 100);
            q.push(a);
        }
    }
}

int main() {
    scanf("%d %lf %lf", &n, &price, &r);
    tree.resize(n);
    for(int i = 0; i < n; i++) {
        int k, id;
        scanf("%d", &k);
        if(k != 0) {
            for(int j = 0; j < k; j++) {
                scanf("%d", &id);
                tree[i].child.push_back(id);
            }
        }
        else {
            scanf("%d", &id);
            book.push_back(i);
            tree[i].num = id;
        }
    }
    layerOrder(n);
    double sales = 0;
    for(int i = 0; i < book.size(); i++) {
        int a = book[i];
        sales = sales +  tree[a].nowPrice * tree[a].num;
    }
    printf("%.1f", sales);
    return 0;
}

