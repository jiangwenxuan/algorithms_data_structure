#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100;
int data[maxn];
int dp[maxn], memo[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    dp[0] = data[0];
    memo[0] = 0;
    for(int i = 1; i < n; i++) {
        if(dp[i-1] + data[i] > data[i]) {
            dp[i] = dp[i-1] + data[i];
            memo[i] = i-1;
        }
        else {
            dp[i] = data[i];
            memo[i] = i;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
    	if(dp[i] > dp[ans]) {
    		ans = i;
		}
	}
    int current = ans;
    printf("%d\n", dp[ans]);
    while(memo[current] != current) {
        printf("%d ", data[current]);
        current = memo[current];
    }
    printf("%d", data[current]);
    return 0;
}
