#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adj[1005];
vector<int> inNum(1005);
vector<int> ans, topological;

bool judge(int n) {
	vector<int> temp = inNum;
	for(int i = 0; i < n; i++) {
		int curr = topological[i];
		if(temp[curr] != 0) {
			return false;
		}
		int l = adj[curr].size();
		for(int j = 0; j < l; j++) {
			temp[adj[curr][j]]--;
		}
	}
	return true;
}

int main() {
	int n, m;
	int a, b;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		inNum[b]++;
	}
	int queries;
	scanf("%d", &queries);
	for(int i = 0; i < queries; i++) {
		topological.clear();
		int current;
		for(int j = 0; j < n; j++) {
			scanf("%d", &current);
			topological.push_back(current);
		}
		if(judge(n) == false) {
			ans.push_back(i);
		}
	}
	int len = ans.size();
	for(int i = 0; i < len; i++) {
		printf("%d", ans[i]);
		if(i != len - 1) {
			printf(" ");
		}
	}
	return 0;
}
