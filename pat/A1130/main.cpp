#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	char data[13];
	int lc;
	int rc;
};
vector<node> v;
vector<int> father;

int findRoot(int n) {
	for(int i = 1; i <= n; i++) {
		if(father[i] == -1) {
			return i;
		}
	}
	return 0;
}

void dfs(int root) {
	if(root == -1) {
		return;
	}
	if(v[root].lc == -1 && v[root].rc == -1) {
		printf("%s", v[root].data);
	}
	else {
		printf("(");
		dfs(v[root].lc);
		printf("%s", v[root].data);
		dfs(v[root].rc);
		printf(")");
	}
}

int main() {
	int n;
	scanf("%d", &n);
	v.resize(n + 1);
	father.resize(n + 1);
	fill(father.begin(), father.end(), -1);
	for(int i = 1; i <= n; i++) {
		int leftC, rightC;
		scanf("%s %d %d", v[i].data, &leftC, &rightC);
		if(leftC != -1) {
			father[leftC] = i;
		}
		if(rightC != -1) {
			father[rightC] = i;
		}
		v[i].lc = leftC;
		v[i].rc = rightC;
	}
	int root = findRoot(n);
	dfs(v[root].lc);
	printf("%s", v[root].data);
	dfs(v[root].rc);
	return 0;
}
