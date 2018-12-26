#include <iostream>
#include <stack>
using namespace std;

int a[1010];

bool check(int M, int N, int* a) {
	stack<int> s;
	int j = 0;
	for(int i = 1; i <= N; i++) {
		s.push(i);
		if(s.size() > M) {
			break;
		}
		while(!s.empty() && s.top() == a[j]) {
			j++;
			s.pop();
		}
	}
	return (j == N);
}

int main() {
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	for(int i = 0; i < K; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		if(check(M, N, a)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
