#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pre;
struct node {
	int data;
	node* lc;
	node* rc;
	int layer;
};

node* newNode(int x) {
	node* current = new node;
	current->data = x;
	current->lc = current->rc = NULL;
	return current;
}

node* createTree(int preL, int preR) {
	if(preL > preR) {
		return NULL;
	}
	if(preL == preR) {
		node* now = newNode(pre[preL]);
		return now;
	}
	node* now = newNode(pre[preL]);
	int i;
	for(i = preL; i <= preR; i++) {
		if(abs(pre[i]) > abs(pre[preL])) {
			break;
		}
	}
	now->lc = createTree(preL + 1, i - 1);
	now->rc = createTree(i, preR);
	return now;
}

bool judge(node* root) {
    vector<node*> vec[17];
    root->layer = 1;
    vec[root->layer].push_back(root);
    queue<node*> q;
    q.push(root);
    int MAX = 1;
    while(!q.empty()) {
    	node* now = q.front();
    	q.pop();
    	if(now->lc != NULL) {
    		MAX = now->lc->layer = now->layer + 1;
    		q.push(now->lc);
    		vec[now->layer + 1].push_back(now->lc);
    	}
    	if(now->rc != NULL) {
    		MAX = now->rc->layer = now->layer + 1;
    		q.push(now->rc);
    		vec[now->layer + 1].push_back(now->rc);
    	}
    }
    for(int i = 1; i <= MAX; i = i + 2) {
    	int len = vec[i].size();
    	if(i % 2 == 1) {
    		for(int j = 0; j < len; j++) {
    			if(vec[i][j]->data < 0) {
    				return false;
    			}
    		}
    	}
    	else {
    		for(int j = 0; j < len; j++) {
    			if(vec[i][j]->data > 0) {
    				return false;
    			}
    		}
    	}
    }
    int m = 1;
    for(int i = 2; i < MAX; i++) {
    	m = 2 * m;
    	if(vec[i].size() != m) {
    		return false;
    	}
    }
    return true;
}

int main() {
	int k, num;
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		pre.clear();
		int current;
		scanf("%d", &num);
		for(int j = 0; j < num; j++) {
			scanf("%d", &current);
			pre.push_back(current);
		}
		node* root = createTree(0, num - 1);
		if(judge(root) == false) {
			printf("No\n");
		}
		else {
			printf("Yes\n");
		}
	}
	return 0;
}
