#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	long long x;
	long long y;
};

long long gcd(long long a, long long b) {
	if(a < b) {
		long long x = a;
		a = b;
		b = x;
	}
	if(b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

node betterRa(node& a) {
	if(a.y < 0) {
		a.x = -a.x;
		a.y = -a.y;
	}
	if(a.x == 0) {
		a.y = 1;
	}
	else {
		long long s = gcd(abs(a.x), abs(a.y));
		a.x = a.x / s;
		a.y = a.y / s;
	}
	return a;
}

node add(node a, node b) {
	node c;
	c.y = a.y * b.y;
	c.x = a.x * b.y + b.x * a.y;
	return betterRa(c);
}

node diff(node a, node b) {
	node c;
	c.y = a.y * b.y;
	c.x = a.x * b.y - b.x * a.y;
	return betterRa(c);
}

node multi(node a, node b) {
	node c;
	c.y = a.y * b.y;
	c.x = a.x * b.x;
	return betterRa(c);
}

node divide(node a, node b) {
	node c;
	c.y = a.y * b.x;
	c.x = a.x * b.y;
	return betterRa(c);
}

void showResult(node a) {
    if(a.y == 0) {
        printf("INF");
        return;
    }
    long long m = 0;
    if(abs(a.x) > abs(a.y)) {
        m = a.x / a.y;
        a.x = a.x % a.y;
    }
    if(m == 0) {
        if(a.x == 0) {
            printf("0");
            return;
        }
        else if(a.x < 0) {
            printf("(%lld/%lld)", a.x, a.y);
        }
        else {
            printf("%lld/%lld", a.x, a.y);
        }
    }
    else {
        if(a.x == 0) {
            if(m > 0) {
                printf("%lld", m);
                return;
            }
            else {
                printf("(%lld)", m);
                return;
            }
        }
        else if(a.x < 0) {
            printf("(%lld %lld/%lld)", m, abs(a.x), a.y);
            return;
        }
        else {
            printf("%lld %lld/%lld", m, a.x, a.y);
            return;
        }
	}
}

int main() {
	node a, b;
	scanf("%lld/%lld %lld/%lld", &a.x, &a.y, &b.x, &b.y);
	betterRa(a);
	betterRa(b);
	showResult(a);
	printf(" + ");
	showResult(b);
	printf(" = ");
	showResult(add(a, b));
	printf("\n");
		showResult(a);
	printf(" - ");
	showResult(b);
	printf(" = ");
	showResult(diff(a, b));
	printf("\n");
	showResult(a);
	printf(" * ");
	showResult(b);
	printf(" = ");
	showResult(multi(a, b));
	printf("\n");
	showResult(a);
	printf(" / ");
	showResult(b);
	printf(" = ");
	showResult(divide(a, b));
	printf("\n");
	return 0;
}
