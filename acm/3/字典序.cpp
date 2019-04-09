#include <cstdio>
#include <string.h>
using namespace std;

#define maxn 100

int less(const char* s, int p, int q) {
	int n = strlen(s);
	char x, y;
	for (int i = 0; i < n; i++) {
		x = s[(p + i) % n];
		y = s[(q + i) % n];
		if (x != y) {
			return x < y;
		}
	}
	return 0;
}

int main() {
	int t;
	char s[maxn];
	scanf("%d", &t);
	while (t > 0) {
		t--;
		scanf("%d", s);
		int ans = 0;
		int n = strlen(s);
		for (int i = 1; i < n; i++) {
			if (less(s, i, ans)) {
				ans = i;
			}
		}
		for (int i = 0; i < n; i++) {
			putchar(s[(i + ans) % n]);
		}
		putchar('\n');
	}
	return 0;
}