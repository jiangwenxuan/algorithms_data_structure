#include <cstdio>
#include <algorithm>
using namespace std;

int v[100050];

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int a, b;
	sort(v, v + n, cmp);
	if(n % 2 == 0) {
		b = 0;
	}
	else {
		b = 1;
	}
	a = n / 2;
	long long current1 = 0; 
	long long current2 = 0;
	for(int i = 0; i < a; i++) {
		current1 = current1 + v[i];
	}
	for(int i = a; i < n; i++) {
		current2 = current2 + v[i];
	}
	printf("%d %lld", b, current2 - current1);
	return 0;
}
