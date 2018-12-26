#include <cstdio>
using namespace std;

int father[10005];

int find(int x) {
	int a = x;
	while(x != father[x]) {
		x = father[x];
	}
	int current;
	while(a != x) {
		current = father[a];
		father[a] = x;
		a = current;
	}
	return x;
}

void Union(int a, int b) {
	int faA = find(a);
	int faB = find(b);
	father[faA] = faB;
}

int main() {
	for(int i = 0; i < 10005; i++) {
		father[i] = i;
	}
	int N;
	scanf("%d", &N);
	int k, m, n;
	int MIN = -1;
	for(int i = 0; i < N; i++) {
		scanf("%d", &k);
		if(k == 1) {
			scanf("%d", &m);
			if(m > MIN) {
				MIN = m;
			}
		}
		else if(k > 1) {
			scanf("%d", &m);
			if(m > MIN) {
				MIN = m;
			}
			for(int i = 1; i < k; i++) {
				scanf("%d", &n);
				Union(m, n);
				if(n > MIN) {
					MIN = n;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= MIN; i++) {
		if(father[i] == i) {
			ans++;
		}
	}
	printf("%d %d\n", ans, MIN);
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		scanf("%d %d", &m, &n);
		if(find(m) == find(n)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}
