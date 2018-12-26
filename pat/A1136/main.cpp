#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct bign {
	int save[2000];
	int len;
	bign() {
        len = 0;
        fill(save, save + 2000, 0);
	}
};

bool judge(bign s) {
	int len = s.len;
	for(int i = 0; i < len / 2; i++) {
		if(s.save[i] != s.save[len - i - 1]) {
			return false;
		}
	}
	return true;
}

bign newAdd(bign a, bign b) {
	bign c;
	int total = 0;
	for(int i = 0; i < a.len || i < b.len; i++) {
		total = total + a.save[i] + b.save[i];
		c.save[c.len] = total % 10;
		c.len++;
		total = total / 10;
	}
	while(total != 0) {
		c.save[c.len] = total % 10;
		total = total / 10;
		c.len++;
	}
	return c;
}

int main() {
	char current[2000];
	scanf("%s", current);
	int l = strlen(current);
	bign a;
	a.len = l;
	for(int i = 0; i < l; i++) {
		a.save[i] = current[l - i - 1] - '0';
	}
	if(judge(a) == true) {
        for(int i = 0; i < a.len; i++) {
            printf("%d", a.save[a.len - i - 1]);
        }
		printf(" is a palindromic number.");
	}
	else {
		int num = 0;
		bign b;
		bign c;
		bool flag = false;
		while(num < 10) {
			b.len = a.len;
			for(int i = 0; i < a.len; i++) {
				b.save[i] = a.save[a.len - i - 1];
			}
			c = newAdd(a, b);
            for(int i = 0; i < a.len; i++) {
                printf("%d", a.save[a.len - i - 1]);
            }
			printf(" + ");
            for(int i = 0; i < b.len; i++) {
                printf("%d", b.save[b.len - i - 1]);
            }
            printf(" = ");
            for(int i = 0; i < c.len; i++) {
                printf("%d", c.save[c.len - i - 1]);
            }
            printf("\n");
			if(judge(c) == true) {
				flag = true;
				break;
			}
			else {
				a = c;
			}
			num++;
		}
		if(flag == true) {
            for(int i = 0; i < c.len; i++) {
                printf("%d", c.save[c.len - i - 1]);
            }
			printf(" is a palindromic number.\n");
		}
		else {
			printf("Not found in 10 iterations.\n");
		}
	}
	return 0;
}
