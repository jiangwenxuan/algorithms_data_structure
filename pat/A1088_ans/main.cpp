#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if(b == 0) {
		return a;
	}
	else if(a < b) {
		return gcd(a, b % a);
	}
	else {
		return gcd(b, a % b);
	}
}

struct fraction {
	ll up;
	ll down;
}a, b;

fraction reduction(fraction result) {
	if(result.down < 0) {
		result.up = -result.up;
		result.down = -result.down;
	}
	if(result.up == 0) {
		result.down = 1;
	}
	else {
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}

fraction add(fraction a, fraction b) {
	fraction c;
	c.up = a.up * b.down + b.up * a.down;
	c.down = a.down * b.down;
	return reduction(c);
}

fraction minu(fraction a, fraction b) {
	fraction c;
	c.up = a.up * b.down - a.down * b.up;
	c.down = a.down * b.down;
	return reduction(c);
}

fraction multi(fraction a, fraction b) {
	fraction c;
	c.up = a.up * b.up;
	c.down = a.down * b.down;
	return reduction(c);
}

fraction divide(fraction a, fraction b) {
	fraction c;
	c.up = a.up * b.down;
	c.down = a.down * b.up;
	return reduction(c);
}

void showResult(fraction a) {
	a = reduction(a);
	if(a.up < 0) {
		printf("(");
	}
	if(a.down == 1) {
		printf("%lld", a.up);
	}
	else if(abs(a.up) > a.down) {
		printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % a.down, a.down);
	}
	else {
		printf("%lld/%lld", a.up, a.down);
	}
	if(a.up < 0) {
		printf(")");
	}
}

int main() {
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
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
	showResult(minu(a, b));
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
	if(b.up == 0) {
		printf("INF");
	}
	else {
		showResult(divide(a, b));
	}
	return 0;
}