#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, W;
	scanf("%d %d", &n, &W);
	int* money = new int[n+1];
	int* weight = new int[n+1];
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &money[i], &weight[i]);
	}
	int** dp = new int*[n+1];
	for(int i = 0; i <= n; i++) {
		dp[i] = new int[W+1];
	}
	for(int v = 0; v <= W; v++) {
		dp[0][v] = 0;
	}
	for(int i = 1; i <= n; i++) {
		dp[i][0] = 0;
		for(int v = 1; v <= W; v++) {
			if(v < weight[i]) {
				dp[i][v] = dp[i-1][v];
				continue;
			}
			else {
				dp[i][v] = max(dp[i-1][v], dp[i-1][v-weight[i]] + money[i]);
			}
		}
	}
// a better choice
//	for(int i = 1; i <= n; i++) {
//		for(int v = weight[i]; v <= W; v++) {
//			dp[i][v] = max(dp[i-1][v], dp[i-1][v-weight[i]] + money[i]);
//		}
//	}
	printf("%d %d %d %d ", dp[1][10], dp[2][30], dp[3][40], dp[3][50]);
	printf("%d", dp[n][W]);
	for(int i = 0; i <= n; i++) {
		delete[] dp[i];
	} 
	delete[] dp;
	return 0;
}
