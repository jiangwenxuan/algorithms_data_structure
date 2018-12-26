#include <iostream>
using namespace std;

struct node {
	int data;
	node* lc;
	node* rc;
};
node* root = NULL;
int post[7] = {2, 3, 1, 5, 7, 6, 4};
int in[7] = {1, 2, 3, 4, 5, 6, 7};
node* create(int postL, int postR, int inL, int inR) {
    if(postL > postR) {
        return NULL;
    }
    node* root = new node;
    root->data = post[postR];
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == post[postR]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lc = create(postL, postL+numLeft-1, inL, k-1);
    root->rc = create(postL+numLeft, postR-1, k+1, inR);
    return root;
}
void traverse(node* root) {
	if(root == NULL) {
		return;
	}
	printf("%d", root->data);
	traverse(root->lc);
	traverse(root->rc);
}
int main() {
	root = create(0, 6, 0, 6);
	traverse(root);
	return 0;
}
