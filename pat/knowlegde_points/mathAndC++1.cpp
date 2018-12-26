#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// gcd

// iterator
int gcd1(int a, int b) {
	while( b != 0) {
		int current = a;
		a = b;
		b = current % b;
	}
	return a;
}

// recursion
int gcd2(int a, int b) {
	if(b == 0) {
		return a;
	}
	else {
		return gcd2(b, a % b);
	}
}

void change(int* a, int* b) {
	int current = *a;
	*a = *b;
	*b = current;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int* m = &a;
	int* n = &b;
	if(a < b) {
		change(m, n);
	}
	printf("%d\n", gcd1(a, b));
	printf("%d\n", gcd2(a, b));
	return 0;
}


// fraction

struct fraction {
	int up;
	int down;
};

fraction reduction(fraction result) {
	if(result.down < 0) {
		result.up = -result.up;
		result.down = -result.down;
	}
	if(result.up == 0) {
		result.down = 1;
	}
	else {
		int d = gcd1(abs(result.up), abs(result.down));
		result.up = result.up / d;
		result.down = result.down / d;
	}
	return result;
}

fraction add(fraction a, fraction b) {
	fraction result;
	result.up = a.up * b.down + b.up * a.down;
	result.down = a.down * b.down;
	return reduction(result);
}

fraction minu(fraction a, fraction b) {
	fraction result;
	result.up = a.up * b.down - b.up * a.down;
	result.down = a.down * b.down;
	return reduction(result);
}

fraction multi(fraction a, fraction b) {
	fraction result;
	result.up = a.up * b.up;
	result.down = a.down * b.down;
	return reduction(result);
}

fraction divide(fraction a, fraction b) {
	fraction result;
	result.up = a.up * b.down;
	result.down = a.down * b.up;
	return reduction(result);
}

void showResult(fraction r) {
	r = reduction(r);
	if(r.down == 1) {
		printf("%lld\n", r.up);
	}
	else if(abs(r.up) > abs(r.down)) {
		printf("%d %d/%d\n", r.up / r.down, abs(r.up) % r.down, r.down);
	}
	else {
		printf("%d/%d", r.up, r.down);
	}
}


// prime

bool isPrime(int n) {
	if(n <= 1) {
		return false;
	}
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

bool isPrime(int n) {
	if(n <= 1) {
		return false;
	}
	for(int i = 2; i < n; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

// prime table
const int maxn = 100;
int prime[maxn];
int pNum = 0;
bool p[maxn] = {0};
void findPrime() {
	for(int i = 1; i < maxn; i++) {
		if(isPrime[i] == true) {
			prime[pNum] = i;
			pNum++;
			p[i] = true;
		}
	}
}

// a better prime table
const int maxn = 100;
int prime[maxn];
int pNum = 0;
bool p[maxn] = {false};
void findPrime() {
	for(int i = 2; i < maxn; i++) {
		if(p[i] == false) {
			prime[pNum] = i;
			pNum++;
			for(int j = i + i; j < maxn; j += i) {
				p[j] = true;
			}
		}
	}
}

