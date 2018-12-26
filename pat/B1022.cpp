#include <cstdio>
using namespace std;

int ans[60];
int num = 0;

void change(int c, int d) {
	do {
		ans[num++] = c % d;
		
		c /= d;
	} while(c != 0);
}

int main() {
	int a, b, d;
	scanf("%d %d %d", &a, &b, &d);
	int c = a + b;
	change(c, d);
	for(int i = num-1; i >= 0; i--) {
		printf("%d", ans[i]);
	}
	return 0;
}
                       
