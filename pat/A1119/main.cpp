#include <cstdio>
#include <vector>
using namespace std;

vector<int> pre;
vector<int> post;
vector<int> in;
bool unique = true;

struct node {
	int data;
	node* lc;
	node* rc;
};

node* deal(int preL, int preR, int postL, int postR) {
	node* current = new node;
	if(preL > preR) {
        return NULL;
	}
	current->data = pre[preL];
	current->lc = current->rc = NULL;
	if(preL == preR) {
		return current;
	}
	int i = preL + 1;
	while (i <= preR && pre[i] != post[postR-1]) {
        i++;
	}
	int numLeft = i - preL - 1;
	if(numLeft == 0) {
        current->rc = deal(i, preR, postL + (i - preL - 1), postR - 1);
		unique = false;
		return current;
	}
	current->lc = deal(preL + 1, i - 1, postL, postL + (i - preL - 2));
	current->rc = deal(i, preR, postL + (i - preL - 1), postR - 1);
	return current;
}

void inOrder(node* root) {
	if(root == NULL) {
		return;
	}
	else {
		inOrder(root->lc);
		in.push_back(root->data);
		inOrder(root->rc);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	pre.resize(n);
	post.resize(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	node* root = deal(0, n-1, 0, n-1);
	inOrder(root);
	if(unique == true) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	printf("%d", in[0]);
	for(int i = 1; i < in.size(); i++) {
		printf(" %d", in[i]);
	}
	printf("\n");
	return 0;
}
