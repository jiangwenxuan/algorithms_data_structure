#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> in, post, result[35];
int n, tree[35][2], root;
struct node {
	int index;
	int depth;
};

void dfs(int &index, int inL, int inR, int postL, int postR) {
	if(inL > inR) {
		return;
	}
	index = postR;
	int i = 0;
	while(in[i] != post[postR]) {
		i++;
	}
	dfs(tree[index][0], inL, i - 1, postL, postL + (i - inL) - 1);
	dfs(tree[index][1], i + 1, inR, postL + (i - inL), postR - 1);
}

void bfs() {
	queue<node> q;
	q.push(node{root, 0});
	while(!q.empty()) {
		node temp = q.front();
		q.pop();
		result[temp.depth].push_back(post[temp.index]);
		if(tree[temp.index][0] != 0) {
			q.push(node{tree[temp.index][0], temp.depth + 1});
		}
		if(tree[temp.index][0] != 0) {
			q.push(node{tree[temp.index][0], temp.depth + 1});
		}
	}
}

int main() {
	scanf("%d", &n);
	in.resize(1 + n);
	post.resize(1 + n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &in[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &post[i]);
	}
	dfs(root, 1, n, 1, n);
	bfs();
	printf("%d", result[0][0]);
	for(int i = 1; i < 35; i++) {
		if(i % 2 == 1) {
			for(int j = 0; j < result[i].size(); j++) {
				printf(" %d", result[i][j]);
			}
		}
		else {
			for(int j = result[i].size() - 1; j >= 0; j--) {
				printf(" %d", result[i][j]);
			}
		}
	}
	return 0;
}