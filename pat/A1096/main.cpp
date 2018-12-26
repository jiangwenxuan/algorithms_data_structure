#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if(n == 1) {
		printf("1\n");
		printf("1");
	}
	else {
		int ans = 1;
		int ansNum = 2;
		int end = (int)sqrt(n * 1.0);
		for(int len = 1; len < end; len++) {
			int start = 2;
			long long fast = 1;
			for(; start < end; start++) {
				long long current = 1;
				for(int i = start; i < start + len; i++) {
					current = current * i;
				}
				if(n % current == 0 && n > current) {
					if(len > ans) {
						ans = len;
						ansNum = start;
					}
				}
			}
			if(start == 2) {
				for(int k = start; k < start + len; k++) {
					fast = fast * k;
				}
                if(fast > n) {
                    break;
			    }
			}
		}
		printf("%d\n", ans);
		printf("%d", ansNum);
		for(int i = ansNum + 1; i < ans + ansNum; i++) {
            printf("*%d", i);
		}
	}
	return 0;
}
