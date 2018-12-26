#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100;
char x[maxn];
char y[maxn];
int c[maxn][maxn];

void lcs(int m, int n) {
    for(int i = 1; i <= m; i++) {
        c[i][0] = 0;
    }
    for(int j = 0; j <= n; j++) {
        c[0][j] = 0;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(x[i] == y[j]) {
                c[i][j] = c[i-1][j-1] + 1;
            }
            else if(c[i-1][j] > c[i][j-1]) {
                c[i][j] = c[i-1][j];
            }
            else {
                c[i][j] = c[i][j-1];
            }
        }
    }
}

int main() {
    gets(x+1);
    gets(y+1);
    int m = strlen(x+1);
    int n = strlen(y+1);
    lcs(m, n);
    printf("%d", c[m][n]);
    return 0;
}
