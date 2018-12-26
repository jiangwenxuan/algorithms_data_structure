#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

// init
struct bign {
	int d[1000];
	int len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char str[]) {
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++) {
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}

int compare(bign a, bign b) {
	if(a.len > b.len) {
		return 1;
	}
	else if(a.len < b.len) {
		return -1;
	}
	else {
		for(int i = a.len - 1; i >= 0; i--) {
			if(a.d[i] > b.d[i]) {
				return 1;
			}
			else if(a.d[i] < b.d[i]) {
				return -1;
			}
		}
		return 0;
	}
}

bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++) {
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len] = temp % 10;
		c.len++;
		carry = temp / 10;
	}
	if(carry != 0) {
		c.d[c.len] = carry;
		c.len++;
	}
	return c;
}

// sub, we should compare a with b before sub
bign sub(bign a, bign b) {
	bign c;
	for(int i = 0; i < a.len || i < b.len; i--) {
		if(a.d[i] < b.d[i]) {
			a.d[i+1]--;
			a.d[i] = a.d[i] + 10;
		}
		c.d[len] = a.d[i] - b.d[i];
		c.len++;
	}
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
		c.len--;
	}
	return c;
}

bign multi(bign a, int b) {
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len; i++) {
		int temp = carry + a.d[i] * b;
		c.d[c.len] = temp % 10;
		c.len++;
		carry = temp / 10;
	}
	while(carry != 0) {
		c.d[len] = carry % 10;
		len++;
		carry = carry / 10;
	}
	return c;
}

bign divide(bign a, int b) {
	bign c;
    c.len = a.len;
    int r = 0;
    for(int i = a.len - 1; i >= 0; i--) {
    	r = r * 10 + a.d[i];
    	if(r < b) {
    		c.d[i] = 0;
    	}
    	else {
    		c.d[i] = r / b;
    		r = r % b;
    	}
    }
    while(c.len - 1 >= 1 && c.d[c.len-1] == 0) {
    	c.len--;
    }
    return c;
}


// the whole code about add

#include <cstdio>
#include <cstring>

struct bign {
	int d[1000];
	int len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char str[]) {
	bign a;
	int l = strlen(str);
	a.len = l;
	for(int i = 0; i < l; i++) {
		a.d[i] = str[l - i - 1] - '0';
	}
	return a;
}

bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++) {
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len] = temp % 10;
		c.len++;
		carry = temp / 10;
	}
	if(carry != 0) {
		c.d[len] = carry;
		c.len++;
	}
	return c;
}

void myPrint(bign a) {
	for(int i = a.len - 1; a >= 0; a--) {
		printf("%d", a.d[i]);
	}
}

int main() {
	char str1[1005];
	char str2[1005];
	scanf("%s %s", str1, str2);
	bign a = change(str1);
	bign b = change(str2);
	bign c = add(a, b);
	myPrint(c);
	return 0;
}