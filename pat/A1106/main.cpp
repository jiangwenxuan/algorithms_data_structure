#include <cstdio>
#include <vector>
using namespace std;

vector<int> tree[100005];

double MIN = 9999999;
int num = 0;
int minDepth;

void dfs(int root, int depth, double p, double r) {
	int len = tree[root].size();
	if(len == 0) {
		if(depth < minDepth) {
			minDepth = depth;
			num = 1;
			MIN = p;
		}
		else if(depth == minDepth) {
			num++;
		}
		return;
	}
	else {
		for(int i = 0; i < len; i++) {
			dfs(tree[root][i], depth + 1, p * r, r);
		}
	}
}

int main() {
	int n;
	double p;
	double r;
	scanf("%d %lf %lf", &n, &p, &r);
	for(int i = 0; i < n; i++) {
		int k, a;
		scanf("%d", &k);
		for(int j = 0; j < k; j++) {
			scanf("%d", &a);
			tree[i].push_back(a);
		}
	}
	r = 1 + (r / 100);
	minDepth = n + 1;
	dfs(0, 1, p, r);
	printf("%.4f %d", MIN, num);
	return 0;
}
