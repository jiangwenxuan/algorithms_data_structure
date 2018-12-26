#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int data;
	node* lc;
	node* rc;
};
node* root = NULL;
vector<int> pre, in, post;

node* newNode(int x) {
	node* current = new node;
	current->data = x;
	current->lc = current->rc = NULL;
	return current;
}

node* build(int preL, int preR, int inL, int inR) {
	if(preL > preR) {
		return NULL;
	}
	else if(preL == preR) {
		node* current = newNode(pre[preL]);
		return current;
	}
	else {
		node* current = newNode(pre[preL]);
		int i;
		for(i = inL; i <= inR; i++) {
			if(pre[preL] == in[i]) {
				break;
			}
		}
		int left = i - inL;
		current->lc = build(preL + 1, preL + left, inL, i - 1);
		current->rc = build(preL + left + 1, preR, i + 1, inR);
		return current;
	}
}

void postOrder(node* root) {
	if(root == NULL) {
		return;
	}
	postOrder(root->lc);
	postOrder(root->rc);
	post.push_back(root->data);
}

int main() {
	int n;
	scanf("%d", &n);
	pre.resize(n);
	in.resize(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	root = build(0, n - 1, 0, n - 1);
	postOrder(root);
	printf("%d", post[0]);
	return 0;
}