#include <cstdio>
using namespace std;

struct node {
	int data;
	node* lc;
	node* rc;
};
node* root = NULL;

node* newNode(int x) {
	node* curr = new node;
	curr->data = x;
	curr->lc = curr->rc = NULL;
	return curr;
}

node* build(node* &root, int x) {
	if(root == NULL) {
		root = newNode(x);
	}
	else if(root->data > x) {
		root->lc = build(root->lc, x);
	}
	else {
		root->rc = build(root->rc, x);
	}
	return root;
}

node* search(int x, node* root) {
	if(root == NULL) {
		return NULL;
	}
	if(root->data == x) {
		return root;
	}
	if(root->data > x) {
		return search(x, root->lc);
	}
	else {
		return search(x, root->rc);
	}
}

int father(int child1, int child2, node* root) {
    int MIN, MAX;
    if(child1 > child2) {
        MAX = child1;
        MIN = child2;
    }
    else {
        MIN = child1;
        MAX = child2;
    }
    if(root->data >= MIN && root->data <= MAX) {
        return root->data;
    }
    else if(root->data < MIN) {
        return father(child1, child2, root->rc);
    }
    else if(root->data > MAX) {
        return father(child1, child2, root->lc);
    }
}

int main() {
	int m, n;
	int x;
	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		root = build(root, x);
	}
	int child1, child2;
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &child1, &child2);
		node* curr1 = search(child1, root);
		node* curr2 = search(child2, root);
		if(curr1 == NULL && curr2 == NULL) {
			printf("ERROR: %d and %d are not found.\n", child1, child2);
		}
		else if(curr1 == NULL) {
		    printf("ERROR: %d is not found.\n", child1);
		}
		else if(curr2 == NULL) {
			printf("ERROR: %d is not found.\n", child2);
		}
		else {
			int ans = father(child1, child2, root);
			if(ans == child1) {
				printf("%d is an ancestor of %d.\n", child1, child2);
			}
			else if(ans == child2) {
				printf("%d is an ancestor of %d.\n", child2, child1);
			}
			else {
				printf("LCA of %d and %d is %d.\n", child1, child2, ans);
			}
		}
	}
	return 0;
}
