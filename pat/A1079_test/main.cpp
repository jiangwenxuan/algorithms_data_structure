#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int num;
    int layer;
    vector<int> child;
};
vector<node> tree;
vector<int> book;

void layerOrder(int n) {
    queue<int> q;
    q.push(0);
    tree[0].layer = 0;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        for(int i = 0; i < tree[top].child.size(); i++) {
            int a = tree[top].child[i];
            tree[a].layer = tree[top].layer+1;
            q.push(a);
        }
    }
}

float totalSales(int price, int r) {
    float sales = 0;
    for(int i = 0; i < book.size(); i++) {
        int realPrice = price;
        int a = book[i];
        for(int j = 0; j < tree[a].layer; j++) {
            realPrice = realPrice * (1 + r / 100);
        }
        sales = sales +  realPrice * tree[a].num;
    }
    return sales;
}

int main() {
    int n;
    float price, r;
    scanf("%d %f %f", &n, &price, &r);
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
    for(int i = 0; i < book.size(); i++) {
        printf("%d\n", tree[book[i]].layer);
    }
    printf("%f", r / 100);
    float sales = totalSales(price, r);
    printf("%f", sales);
    return 0;
}

