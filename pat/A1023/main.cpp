#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct bign {
	int len;
	int d[30];
	bign() {
		fill(d, d + 30, 0);
		len = 0;
	}
}a, b;

int record[10] = {0};

void multi(bign& a, int b) {
	int temp = 0;
	for(int i = 0; i < a.len; i++) {
		temp = b * a.d[i] + temp;
		a.d[i] = temp % 10;
		temp = temp / 10;
	}
	while(temp != 0) {
		a.d[a.len] = temp % 10;
		a.len++;
		temp = temp / 10;
	}
}

int main() {
	char m[30];
	scanf("%s", m);
	int l = strlen(m);
	a.len = l;
	for(int i = l - 1; i >= 0; i--) {
		a.d[l - i - 1] = m[i] - '0';
		record[m[i] - '0']++;
	}
	multi(a, 2);
	bool flag = true;
	for(int i = 0; i < a.len; i++) {
		record[a.d[i]]--;
	}
	for(int i = 0; i < 10; i++) {
		if(record[i] != 0) {
			flag = false;
			break;
		}
	}
	if(flag == false) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
	for(int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
	return 0;
}
