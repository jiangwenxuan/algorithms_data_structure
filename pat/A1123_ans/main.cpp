#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int data;
	node* lc;
	node* rc;
};

node* leftRotate(node* tree) {
	node* temp = tree->rc;
	tree->rc = temp->lc;
	temp->lc = tree;
	return temp;
}

node* rightRotate(node* tree) {
	node* temp = tree->lc;
	tree->lc = temp->rc;
	temp->rc = tree;
	return temp;
}

node* leftRightRotate(node* tree) {
	tree->lc = leftRotate(tree->lc);
	return rightRotate(tree);
}

node* rightLeftRotate(node* tree) {
	tree->rc = rightRotate(tree->rc);
	return leftRotate(tree);
}

int getHeight(node* tree) {
	if(tree == NULL) {
		return 0;
	}
	int l = getHeight(tree->lc);
	int r = getHeight(tree->rc);
	return max(l, r) + 1;
}

node* insert(node* tree, int value) {
	if(tree == NULL) {
		tree = new node();
		tree->data = value;
	}
	else if(tree->data > value) {
		tree->left = insert(tree->left, value);
		int l = getHeight(tree->lc);
		int r = getHeight(tree->rc);
		if(l - r >= 2) {
			if(value < tree->left->data) {
				tree = rightRotate(tree);
			}
			else {
				tree = leftRightRotate(tree);
			}
		}
	}
	else {
		tree->rc = insert(tree->rc, value);
		int l = getHeight(tree->lc);
		int r = getHeight(tree->rc);
		if(r - l >= 2) {
			if(value > tree->rc->data) {
				tree = leftRotate(tree);
			}
			else {
				tree = rightLeftRotate(tree);
			}
		}
	}
	return tree;
}

int isComplete = 1;
int after = 0;

vector<int> levelOrder(node* tree) {
	vector<int> v;
	queue<node*> q;
	q.push(tree);
	while(!q.empty()) {
		node* temp = q.front();
		q.pop();
		v.push_back(temp->data);
		if(temp->left != NULL) {
			if(after) {
				isComplete = 0;
			}
			q.push(temp->lc);
		}
		else {
			after = 1;
		}
		if(temp->rc != NULL) {
			if(after) {
				isComplete = 0;
			}
			q.push(temp->rc);
		}
		else {
			after = 1;
		}
	}
	return v;
}

int main() {
	int n, temp;
	scanf("%d", &n);
	node* tree = NULL;
	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		tree = insert(tree, temp);
	}
	vector<int> v = levelOrder(tree);
	for(int i = 0; i < v.size(); i++) {
		if(i != 0) {
			printf(" ");
		}
		printf("%d", v[i]);
	}
	printf("\n%s", isComplete ? "YES" : "NO");
	return 0;
}