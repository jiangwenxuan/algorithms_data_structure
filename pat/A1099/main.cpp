#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
	int data;
	int lc;
	int rc;
};

vector<node> tree;
vector<int> v;
vector<int> in;

void inOrder(int root) {
	if(root == -1) {
		return;
	}
	inOrder(tree[root].lc);
	in.push_back(root);
	inOrder(tree[root].rc);
}

void levelOrder(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		in.push_back(tree[now].data);
		if(tree[now].lc != -1) {
			q.push(tree[now].lc);
		}
		if(tree[now].rc != -1) {
			q.push(tree[now].rc);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	tree.resize(n);
	v.resize(n);
	for(int i = 0; i < n; i++) {
		int a, b;
		node current;
		scanf("%d %d", &a, &b);
		current.lc = a;
		current.rc = b;
		tree[i] = current;
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	inOrder(0);
	for(int i = 0; i < n; i++) {
		tree[in[i]].data = v[i];
	}
	in.clear();
	levelOrder(0);
	int len = in.size();
	for(int i = 0; i < len; i++) {
		printf("%d", in[i]);
		if(i != len - 1) {
			printf(" ");
		}
	}
	return 0;
}
