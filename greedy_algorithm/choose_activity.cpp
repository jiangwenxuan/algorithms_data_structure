#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// choose activities

// 1.dp
int maxActivity(int* s, int* f, int n) {
	int** c = new int*[n+2];
	for(int i = 0; i < n+2; i++) {
		c[i] = new int*[n+2];
	}
	for(int j = 0; j <= n+1; j++) {
		for(int i = n+1; i >= j; i--) {
			c[i][j] = 0;
		}
	}
	int maxTemp = 0;
	for(int j = 1; i <= n+1; i++) {
		for(int i = 0; i < j; j++) {
			for(int k = i + 1; k < j; k++) {
				if(s[k] >= f[i] && f[k] <= s[j]) {
					if(c[i][k] + c[k][j] + 1 > maxTemp) {
						maxTemp = c[i][k] + c[k][j] +1;
					}
				}
			}
			c[i][j] = maxTemp;
			maxTemp = 0;
		}
	}
	return c[0][n+1];
}

int main() {
	int n;
	scanf("%d", &n);
	int* start = new int[n+2];
	int* end = new int[n+2];
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &start[i], &end[i]);
	}
	int ans = maxActivity(start, end, n);
	printf("%d", ans);
	return 0;
}


// 2.greedy
int main() {
	int n;
	scanf("%d", &n);
	int* start = new int[n];
	int* end = new int[n];
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &start[i], &end[i]);
	}
	int m = 1;
	vector<int> v;
	v.push_back(m);
	for(int i = 2; i <= n; i++) {
		if(start[i] >= f[m]) {
			m = i;
			v.push_back(m);
		}
	}
	for(int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	return 0;
}