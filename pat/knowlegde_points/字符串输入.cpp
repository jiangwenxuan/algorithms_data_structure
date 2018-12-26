#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char a[270];
	gets(a);
	int len = strlen(a);
	bool flag = true;
	for(int i = 0; i < len / 2; i++) {
		if(a[i] != a[len - 1 - i]) {
			flag = false;
			break;
		}
	}
	if(flag) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}
