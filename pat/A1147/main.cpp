#include <cstdio>
#include <vector>
using namespace std;

vector<int> levelOrder;
vector<int> postOrder;

void dfs(int start, int m) {
	if(start > m) {
		return;
	}
	dfs(start * 2, m);
	dfs(start * 2 + 1, m);
	postOrder.push_back(levelOrder[start]);
}

int judge(int m) {
	bool mark;
	bool flag = true;
	int len = levelOrder.size() - 1;
	if(levelOrder[1] <= levelOrder[2]) {
		mark = false;
	}
	else {
		mark = true;
	}
	for(int i = 1; i <= len / 2; i++) {
		if(mark == false) {
			if(i * 2 <= m && levelOrder[i] > levelOrder[i * 2]) {
				flag = false;
				break;
			}
			if(i * 2 + 1 <= m && levelOrder[i] > levelOrder[i * 2 + 1]) {
				flag = false;
				break;
			}
		}
		else if(mark == true) {
			if(i * 2 <= m && levelOrder[i] < levelOrder[i * 2]) {
				flag = false;
				break;
			}
			if(i * 2 + 1 <= m && levelOrder[i] < levelOrder[i * 2 + 1]) {
				flag = false;
				break;
			}
		}
	}
	if(flag == true && mark == false) {
		return 2;
	}
	if(flag == true && mark == true) {
		return 1;
	}
	else {
		return 3;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	levelOrder.resize(m + 1);
	for(int i = 0; i < n; i++) {
		postOrder.clear();
		for(int j = 1; j <= m; j++) {
			scanf("%d", &levelOrder[j]);
		}
		int ans = judge(m);
		dfs(1, m);
		if(ans == 1) {
			printf("Max Heap\n");
		}
		else if(ans == 2) {
			printf("Min Heap\n");
		}
		else {
			printf("Not Heap\n");
		}
		for(int j = 0; j < m; j++) {
			printf("%d", postOrder[j]);
			if(j != m - 1) {
				printf(" ");
			}
			if(j == m - 1) {
				printf("\n");
			}
		}
	}
	return 0;
}
