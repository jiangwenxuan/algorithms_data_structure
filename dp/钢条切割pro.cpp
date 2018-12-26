#include <cstdio>
using namespace std;

int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int r[11], s[11];

int bottomUp(int n) {
    r[0] = 0;
    for(int i = 1; i <= n; i++) {
        int q = -10;
        for(int j = 1; j <= i; j++) {
            if(q < p[j] + r[i-j]) {
                q = p[j] + r[i-j];
                s[i] = j;
                r[i] = q;
            }
        }
    }
    return r[n];
}

void print_ans(int n) {
    while(n > 0) {
        printf("%d ", s[n]);
        n = n - s[n];
    }
}

int main() {
    bottomUp(10);
    for(int i = 1; i <= 10; i++) {
    	printf("%d ", r[i]);
	}
    print_ans(10);
    return 0;
}
