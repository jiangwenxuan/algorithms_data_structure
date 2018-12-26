#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct bign {
	int d[1000];
	int len;
	bign() {
		fill(d, d + 1000, 0);
		len = 0;
	}
};

bign reverse(bign a) {
    bign b;
    b.len = a.len;
    for(int i = 0; i < a.len; i++) {
    	b.d[i] = a.d[a.len - i - 1];
    }
    return b;
}

bign add(bign a, bign b) {
	int temp = 0;
	bign c;
	for(int i = 0; i < a.len || i < b.len; i++) {
		temp = temp + a.d[i] + b.d[i];
		c.d[c.len++] = temp % 10;
		temp = temp / 10;
	}
	while(temp != 0) {
		c.d[c.len++] = temp % 10;
		temp = temp / 10;
	}
	return c;
}

bool ifPa(bign a) {
	bool flag = true;
	for(int i = 0; i < a.len; i++) {
		if(a.d[i] != a.d[a.len - 1 - i]) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	int step;
	char s[15];
	scanf("%s %d", s, &step);
	bign a;
	int l = strlen(s);
	for(int i = 0; i < l; i++) {
		a.d[a.len++] = s[l - i - 1] - '0';
	}
	int mark = 0;
	while(mark < step) {
		if(ifPa(a) == true) {
			break;
		}
		else {
			bign b = reverse(a);
			a = add(a, b);
			mark++;
		}
	}
	for(int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
	printf("\n%d", mark);
	return 0;
}
