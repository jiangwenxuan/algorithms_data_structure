#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	vector<int> v;
};
node vertex[10005];
bool visit[10005];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vertex[a].v.push_back(i);
		vertex[b].v.push_back(i);
	}
	int k, num, s, current;
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		fill(visit, visit + 10005, false);
		scanf("%d", &num);
		s = 0;
		for(int j = 0; j < num; j++) {
			scanf("%d", &current);
			int len = vertex[current].v.size();
			for(int h = 0; h < len; h++) {
				int now = vertex[current].v[h];
				if(visit[now] == false) {
					visit[now] = true;
					s++;
				}
			}
		}
		if(s == m) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}
