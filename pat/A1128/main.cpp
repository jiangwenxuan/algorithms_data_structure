#include <cstdio>
#include <algorithm>
using namespace std;

int chess[1005][1005] = {0};

bool judge(int n, int j, int q) {
	for(int i = 1; j + i <= n && q + i <= n; i++) {
		if(chess[j+i][q+i] == 1) {
			return false;
		}
	}
	for(int i = -1; j + i >= 1 && q + i >= 1; i--) {
		if(chess[j+i][q+i] == 1) {
			return false;
		}
	}
	int a = 1;
	int b = -1;
	while(j + a <= n && q + b >= 1) {
		if(chess[j+a][q+b] == 1) {
			return false;
		}
		a++;
		b--;
	}
	a = 1;
	b = -1;
	while(j + b >= 1 && q + a <= n) {
		if(chess[j+b][q+a] == 1) {
			return false;
		}
		a++;
		b--;
	}
	return true;
}

int main() {
	int k;
	scanf("%d", &k);
	int n;
	int q;
	for(int i = 0; i < k; i++) {
		bool flag = true;
		fill(chess[0], chess[0] + 1005 * 1005, 0);
		scanf("%d", &n);
		for(int j = 1; j <= n; j++) {
			scanf("%d", &q);
			chess[j][q] = 1;
			for(int m = 1; m < j; m++) {
				if(chess[m][q] == 1) {
					flag = false;
				}
			}
			flag = judge(n, j, q);
		}
		if(flag == true) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
