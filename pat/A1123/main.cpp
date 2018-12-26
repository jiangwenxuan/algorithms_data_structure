#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int data;
	node* lc;
	node* rc;
	int height;
	int index;
};

node* root = NULL;
vector<int> v;

node* newNode(int x) {
	node* current = new node;
	current->data = x;
	current->lc = current->rc = NULL;
	current->height = 1;
	return current;
}

int getHeight(node* root) {
	if(root == NULL) {
		return 0;
	}
	else {
		return root->height;
	}
}

void updataHeight(node* root) {
	root->height = max(getHeight(root->lc), getHeight(root->rc)) + 1;
}

int balanceFactor(node* root) {
	return getHeight(root->lc) - getHeight(root->rc);
}

void L(node* &root) {
	node* temp = root->rc;
	root->rc = temp->lc;
	temp->lc = root;
	updataHeight(root);
	updataHeight(temp);
	root = temp;
}

void R(node* &root) {
	node* temp = root->lc;
	root->lc = temp->rc;
	temp->rc = root;
	updataHeight(root);
	updataHeight(temp);
	root = temp;
}

void insert(int x, node* &root) {
	if(root == NULL) {
		root = newNode(x);
		return;
	}
	else if(root->data > x) {
		insert(x, root->lc);
		updataHeight(root);
		if(balanceFactor(root) == 2) {
			if(balanceFactor(root->lc) == 1) {
				R(root);
			}
			if(balanceFactor(root->lc) == -1) {
				L(root->lc);
				R(root);
			}
		}
	}
	else {
		insert(x, root->rc);
		updataHeight(root);
		if(balanceFactor(root) == -2) {
			if(balanceFactor(root->rc) == -1) {
				L(root);
			}
			if(balanceFactor(root->rc) == 1) {
				R(root->rc);
				L(root);
			}
		}
	}
}

void levelOrder(node* root) {
	int i = 1;
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		node* now = q.front();
		q.pop();
		now->index = i;
		i++;
		v.push_back(now->data);
		if(now->lc != NULL) {
			q.push(now->lc);
		}
		if(now->rc != NULL) {
			q.push(now->rc);
		}
	}
}

bool judge(int len) {
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		node* current = q.front();
		q.pop();
		if(current->index * 2 <= len && current->lc == NULL) {
			return false;
		}
		if(current->index * 2 + 1 <= len && current->rc == NULL) {
			return false;
		}
		if(current->lc != NULL) {
			q.push(current->lc);
		}
		if(current->rc != NULL) {
			q.push(current->rc);
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	int x;
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		insert(x, root);
	}
	levelOrder(root);
	int len = v.size();
    printf("%d", v[0]);
    for(int i = 1; i < len; i++) {
    	printf(" %d", v[i]);
    }
    if(judge(len) == true) {
    	printf("\nYES");
    }
    else {
    	printf("\nNO");
    }
    return 0;
}