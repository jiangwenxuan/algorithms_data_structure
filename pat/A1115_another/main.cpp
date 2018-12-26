#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int v;
	node* lc;
	node* rc;
};

node* build(int x, node* root) {
	if(root == NULL) {
		root = new node;
		root->v = x;
		root->lc = root->rc = NULL;
	}
	else if(v <= root->v) {
		root->lc = build(x, root->lc);
	}
	else {
		root->rc = build(x, root->rc);
	}
	return root;
}

vector<int> num(1000);
int maxdepth = -1;

void dfs(node* root, int depth) {
	if(root == NULL) {
		maxdepth = max(depth, maxdepth);
		return;
	}
	num[depth]++;
	dfs(root->lc, depth + 1);
	dfs(root->rc, depth + 1);
}

int main() {
	int n, t;
	scanf("%d", &n);
	node* root = NULL;
	for(int i = 0; i < n; i++) {
		scanf("%d", &t);
		root = build(t, root);
	}
	dfs(root, 0);
	printf("%d + %d = %d", num[maxdepth - 1], num[maxdepth - 2], num[maxdepth - 1] + num[maxdepth - 2]);
	return 0;
}