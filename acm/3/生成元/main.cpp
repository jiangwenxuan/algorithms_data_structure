#include <cstdio>
#include <string.h>
using namespace std;

#define maxn 100005
int array[maxn];

int main() {
    int n, m;
    int x, y;
    memset(array, 0, sizeof(array));
    for (int i = 1; i < maxn; i++) {
    	x = y = i;
    	while (x > 0) {
    		y = x % 10 + y;
    		x = x / 10;
    	}
    	array[i] = y;
    }
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
    	scanf("%d", &m);
    	printf("%d\n", array[m]);
    }
    return 0;
}
