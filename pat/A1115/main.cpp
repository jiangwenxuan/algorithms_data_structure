#include <cstdio>
#include <queue>
using namespace std;

struct node {
	int data;
	int layer;
	node* lc;
	node* rc;
};
int n;

void insert(int x, node* &root) {
	if(x <= root->data) {
		if(root->lc == NULL) {
			node* current = new node;
			current->data = x;
			root->lc = current;
			current->lc = current->rc = NULL;
			return;
		}
		else {
			insert(x, root->lc);
		}
	}
	else if(x > root->data) {
		if(root->rc == NULL) {
			node* current = new node;
			current->data = x;
			root->rc = current;
			current->lc = current->rc = NULL;
			return;
		}
		else {
			insert(x, root->rc);
		}
	}
}

int smallest = 1, smaller = 0;
int n1 = 0, n2 = 0;

void levelTra(node* root) {
    queue<node*> q;
    root->layer = 1;
    q.push(root);
    while(!q.empty()) {
        node* current = q.front();
        q.pop();
        if(current->lc != NULL) {
            smallest = current->lc->layer = current->layer + 1;
            q.push(current->lc);
        }
        if(current->rc != NULL) {
            smallest = current->rc->layer = current->layer + 1;
            q.push(current->rc);
        }
    }
}

void search(node* root) {
	if(root->layer == smaller) {
		n2++;
	}
	if(root->layer == smallest) {
		n1++;
	}
	if(root->lc != NULL) {
		search(root->lc);
	}
	if(root->rc != NULL) {
		search(root->rc);
	}
}

int main() {
	scanf("%d", &n);
	node* root = new node;
	root->lc = root->rc = NULL;
	int x;
	scanf("%d", &x);
	root->data = x;
	for(int i = 1; i < n; i++) {
		scanf("%d", &x);
		insert(x, root);
	}
	root->layer = 1;
	levelTra(root);
	smaller = smallest - 1;
	search(root);
	printf("%d + %d = %d", n1, n2, n1 + n2);
	return 0;
}
