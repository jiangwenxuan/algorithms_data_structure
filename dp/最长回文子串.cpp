#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100;
int dp[N][N];
char A[N];

int main() {
	int n = 6;
    for(int i = 0; i < n; i++) {
        scanf("%s", &A[i]);
    }
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
        ans++;
        if(i < n-1) {
            if(A[i] == A[i+1]) {
                dp[i][i+1] = 1;
                ans++;
            }
            else {
                dp[i][i+1] = 0;
            }
        }
    }
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if(A[i] == A[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
    
}
