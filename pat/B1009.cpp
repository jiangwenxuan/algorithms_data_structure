#include <cstdio>
#include <cstring>
using namespace std;

char a[85];
char ans[85][85];

int main() {
	gets(a);
	int len = strlen(a);
	int r = 0; 
	int h = 0;
	for(int i = 0; i < len; i++) {
		if(a[i] != ' ') {
			ans[r][h] = a[i];
			h++;
		}
		else {
			ans[r][h] = '\0';
			r++;
			h = 0;
		}
	}
	for(; r >= 0; r--) {
		printf("%s", ans[r]);
		if(r > 0) {
			printf(" ");
		}
	}
	return 0;
}
