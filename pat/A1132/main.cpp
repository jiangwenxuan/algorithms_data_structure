#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		char str[15];
		long long a = 0;
		long long b = 0;
		long long c = 0;
		scanf("%s", str);
		int len = strlen(str);
		for(int j = 0; j < len / 2; j++) {
			a = a * 10 + str[j] - '0';
			b = b * 10 + str[j] - '0';
		}
		for(int j = len / 2; j < len; j++) {
			a = a * 10 + str[j] - '0';
			c = c * 10 + str[j] - '0';
		}
		bool flag = true;
		if(c == 0) {
			printf("No\n");
		}
		else {
			if((a / (b * c) * b * c) != a) {
				flag = false;
			}
			if(flag == true) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
	}
	return 0;
}
