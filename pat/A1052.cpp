#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int address;
    int data;
    int nextAddress;
};
node Node[100005];

bool cmp(node a, node b) {
    return a.data < b.data;
}

int main() {
    int num, add;
    scanf("%d %d", &num, &add);
    for(int i = 0; i < num; i++) {
        scanf("%d %d %d", &Node[i].address, &Node[i].data, &Node[i].nextAddress);
    }
    sort(Node, Node+num, cmp);
    for(int i = 0; i < num-1; i++) {
        Node[i].nextAddress = Node[i+1].address;
    }
    Node[num-1].nextAddress = -1;
    printf("%d %05d", num, Node[0].address);
    for(int i = 0; i < num-1; i++) {
        printf("%05d %d %05d\n", Node[i].address, Node[i].data, Node[i].nextAddress);
    }
    printf("%05d %d -1", Node[num-1].address, Node[num-1].data);
    return 0;
}
