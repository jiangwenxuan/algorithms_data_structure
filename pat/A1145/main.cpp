#include <cstdio>
#include <vector>
using namespace std;

bool isPrime(int n) {
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int tSize, n, m;
	int a;
	scanf("%d %d %d", &tSize, &n, &m);
	while(!isPrime(tSize)) {
		tSize++;
	}
	vector<int> v(tSize);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		int flag = 0;
		for(int j = 0; j < tSize; j++) {
			int pos = (a + j * j) % tSize;
			if(v[pos] == 0) {
				v[pos] = a;
				flag = 1;
				break;
			}
		}
		if(!flag) {
			printf("%d cannot be inserted.\n", a);
		}
	}
	int ans = 0;
	for(int i = 0; i < m; i++) {
		scanf("%d", &a);
		for(int j = 0; j <= tSize; j++) {
			ans++;
			int pos = (a + j * j) % tSize;
			if(v[pos] == a || v[pos] == 0) {
				break;
			}
		}
	}
	printf("%.1f\n", ans * 1.0 / m);
	return 0;
}