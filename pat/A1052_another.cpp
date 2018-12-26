#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100005;
struct node {
    int address, data, next;
    bool flag = false;
} Node[maxn];

bool cmp(node a, node b) {
    if(a.flag == false | b.flag == false) {
        return a.flag > b.flag;
    }
    else {
        a.data < b.data;
    }
}

int main() {
    int num, add;
    scanf("%d %d", &num, &add);
    int current;
    for(int i = 0; i < num; i++) {
        scanf("%d", &current);
        scanf("%d %d", &Node[current].data, &Node[current].next);
        Node[current].address = current;
    }
    int count = 0, p = add;
    while(p != -1) {
        Node[p].flag = true;
        p = Node[p].next;
        count++;
    }
    if(count == 0) {
        printf("0 -1");
    }
    else {
        sort(node, node + maxn, cmp);
        printf("%d %05d", count, Node[0].address);
        for(int i = 0; i < count-1; i++) {
            printf("%05d %d %05d", Node[i].address, Node[i].data, Node[i+1].address);
        }
        printf("%05d %d -1", Node[count-1].address, Node[count-1].data);
    }
    return 0;
}