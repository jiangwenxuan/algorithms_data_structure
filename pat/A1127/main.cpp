#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int data;
	node* lc;
	node* rc;
	int layer;
};
node* root = NULL;
vector<int> inOrder;
vector<int> postOrder;
vector<int> zig;
int record[35] = {0};

node* newNode(int x) {
	node* current = new node;
	current->lc = current->rc = NULL;
	current->data = x;
	return current;
}

node* buildTree(int inL, int inR, int postL, int postR) {
	if(postL > postR) {
		return NULL;
	}
	node* now = newNode(postOrder[postR]);
    if(postL == postR) {
		return now;
	}
	int i;
	for(i = inL; i <= inR; i++) {
		if(inOrder[i] == postOrder[postR]) {
			break;
		}
	}
	int numLeft = i - inL;
	now->lc = buildTree(inL, i - 1, postL, postL + numLeft - 1);
	now->rc = buildTree(i + 1, inR, postL + numLeft, postR - 1);
	return now;
}

int levelOrder() {
	int k = 0;
	queue<node*> q;
	q.push(root);
	root->layer = 1;
	while(!q.empty()) {
		node* now = q.front();
		zig.push_back(now->data);
		q.pop();
		if(now->lc != NULL) {
			q.push(now->lc);
			now->lc->layer = now->layer + 1;
			k = now->layer + 1;
		}
		if(now->rc != NULL) {
			q.push(now->rc);
			now->rc->layer = now->layer + 1;
			k = now->layer + 1;
		}
	}
	return k;
}

void dfs(node* root) {
	int k = root->layer;
	record[k]++;
	if(root->lc != NULL) {
		dfs(root->lc);
	}
	if(root->rc != NULL) {
		dfs(root->rc);
	}
}

int reverse(int j, int i) {
	int len = record[i];
	int current = j;
	int* array = new int[len];
	for(int k = len - 1; k >= 0; k--) {
		array[k] = zig[current];
		current++;
	}
	int s = 0;
	for(; j < current; j++) {
		zig[j] = array[s];
		s++;
	}
	return current;
}

int main() {
	int n;
	scanf("%d", &n);
	inOrder.resize(n);
	postOrder.resize(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &inOrder[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &postOrder[i]);
	}
	root = buildTree(0, n - 1, 0, n - 1);
	int k = levelOrder();
	dfs(root);
	int j = 0;
	for(int i = 1; i <= k; i++) {
        if(i % 2 == 1) {
            j = reverse(j, i);
        }
        else {
            j = j + record[i];
        }
	}
	for(int i = 0; i < zig.size(); i++) {
		if(i != 0) {
			printf(" ");
		}
		printf("%d", zig[i]);
	}
	return 0;
}
