#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt, b[100];

struct node {
	int data;
	int lc;
	int rc;
	int index;
	int lebel;
};
node a[110];

bool cmp(node x, node y) {
	if(x.lebel != y.lebel) {
		return x.lebel < y.lebel;
	}
	return x.index < y.index;
}

void dfs(int root, int index, int lebel) {
	if(a[root].lc == -1 &&a[root].rc == -1) {
		a[root] = {b[cnt++], a[root].lc, a[root].rc, index, lebel};
	}
	else {
		if(a[root].lc != -1) {
			dfs(a[root].lc, index * 2 + 1, lebel + 1);
		}
		a[root] = {b[cnt++], a[root].lc, a[root].rc, index, lebel};
		if(a[root].rc != -1) {
			dfs(a[root].rc, index * 2 + 2, lebel + 1);
		}
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].lc >> a[i].rc;
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(b, b + n);
	dfs(0, 0, 0);
	sort(a, a + n, cmp);
	for(int i = 0; i < n; i++) {
		if(i != 0) {
			cout << " ";
			cout << a[i].data;
		}
	}
	return 0;
}