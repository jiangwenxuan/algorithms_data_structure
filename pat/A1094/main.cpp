#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int layer;
	vector<int> child;
};
vector<node> tree(100);
vector<int> lay;

void levelOrder(int root) {
	queue<int> q;
	q.push(root);
	tree[root].layer = 1;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		lay[tree[now].layer]++;
		int len = tree[now].child.size();
		for(int i = 0; i < len; i++) {
			q.push(tree[now].child[i]);
			tree[tree[now].child[i]].layer = tree[now].layer + 1;
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	lay.resize(n + 1);
	for(int i = 0; i < m; i++) {
		int id;
		scanf("%d", &id);
		int k;
		scanf("%d", &k);
		tree[id].child.resize(k);
		for(int j = 0; j < k; j++) {
			scanf("%d", &tree[id].child[j]);
		}
	}
	levelOrder(1);
	int MIN = 0;
	int l = 0;
	for(int i = 1; i < n + 1; i++) {
		if(MIN < lay[i]) {
			MIN = lay[i];
			l = i;
		}
	}
	printf("%d %d", MIN, l);
	return 0;
}
