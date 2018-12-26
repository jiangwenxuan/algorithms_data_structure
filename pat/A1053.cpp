#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int data;
    vector<int> child;
};
int N, M, S;
vector<int> temp;
vector<node> Node;

bool cmp(int a, int b) {
	return Node[a].data > Node[b].data;
}

void DFS(int index, int sumWeight) {
    if(sumWeight > S) {
        return;
    }
    if(sumWeight == S) {
        if(Node[index].child.size() != 0) {
            return;
        }
        for(int i = 0; i < temp.size(); i++) {
            printf("%d%c", temp[i], i != temp.size() - 1 ? ' ' : '\n');
        }
        return;
    }
    for (int i = 0; i < Node[index].child.size(); i++) {
        int weight = Node[Node[index].child[i]].data;
        temp.push_back(weight);
        DFS(Node[index].child[i], sumWeight + weight);
        temp.pop_back();
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &S);
    int numOfChild;
    int currentLeaf;
    int currentNum;
    Node.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &Node[i].data);
        Node[i].child.clear();
    }
    for(int i = 0; i < M; i++) {
        scanf("%d", &currentLeaf);
        scanf("%d", &numOfChild);
        for(int j = 0; j < numOfChild; j++) {
            scanf("%d", &currentNum);
            Node[currentLeaf].child.push_back(currentNum);
        }
        sort(Node[currentLeaf].child.begin(), Node[currentLeaf].child.end(), cmp);
    }
    temp.push_back(Node[0].data);
    DFS(0, Node[0].data);
    return 0;
}
