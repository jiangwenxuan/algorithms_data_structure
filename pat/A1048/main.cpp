#include <cstdio>
using namespace std;

int m[1005] = {0};

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int a;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &a);
		m[a]++;
	}
	int midIndex = M / 2 + 1;
	for(int i = 1; i < midIndex; i++) {
		if(m[i] != 0) {
			m[i]--;
			if(m[M-i] != 0) {
			  printf("%d %d", i, M-i);
			  return 0;
			}
			m[i]++;
		}
	}
	printf("No Solution");
	return 0;
}
