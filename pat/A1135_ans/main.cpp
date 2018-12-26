#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<int> arr;
struct node {
	int data;
	node* lc;
	node* rc;
};

node* build(node* &root, int v) {
	if(root == NULL) {
		root = new node();
		root->data = v;
		root->lc = root->rc = NULL;
	}
	else if(abs(v) <= abs(root->data)) {
		root->lc = build(root->lc, v);
	}
	else {
		root->rc = build(root->rc, v);
	}
	return root;
}

bool judge1(node* root) {
	if(root == NULL) {
		return true;
	}
	if(root->data < 0) {
		if(root->lc != NULL && root->lc->data < 0) {
			return false;
		}
		if(root->rc != NULL && root->rc->data < 0) {
			return false;
		}
	}
	return judge1(root->lc) && judge1(root->rc);
}

int getNum(node* root) {
	if(root == NULL) {
		return 0;
	}
	int l = getNum(root->lc);
	int r = getNum(root->rc);
	return root->data > 0 ? max(l, r) + 1 : max(l, r);
}

bool judge2(node* root) {
	if(root == NULL) {
		return true;
	}
	int l = getNum(root->lc);
	int r = getNum(root->rc);
	if(l != r) {
		return false;
	}
	return judge2(root->lc) && judge2(root->rc);
}

int main() {
	int k, n;
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		scanf("%d", &n);
		arr.resize(n);
		node* root = NULL;
		for(int j = 0; j < n; j++) {
			scanf("%d", &arr[j]);
			root = build(root, arr[j]);
		}
		if(arr[0] < 0 || judge1(root) == false || judge2(root) == false) {
			printf("No\n");
		}
		else {
			printf("Yes\n");
		}
	}
	return 0;
}
