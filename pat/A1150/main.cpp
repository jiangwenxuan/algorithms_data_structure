#include <cstdio>
#include <vector>
using namespace std;

int g[205][205] = {0};

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a][b] = g[b][a] = c;
	}
	int k;
	scanf("%d", &k);
	int MIN = 99999999, MINP = 0;
	for(int i = 1; i <= k; i++) {
		int h, start, next;
		bool flag = true;
		bool mark = true;
		int ans = 0;
		scanf("%d %d", &h, &start);
		int begin = start;
		vector<int> v(n + 1);
		for(int j = 1; j < h; j++) {
			scanf("%d", &next);
			if(g[start][next] == 0) {
				flag = false;
			}
			else {
				ans += g[start][next];
				v[next]++;
			}
			start = next;
		}
		printf("Path %d: ", i);
		for(int j = 1; j <= n; j++) {
            if(v[j] == 0) {
                mark = false;
            }
		}
		if(flag == false) {
			printf("NA (Not a TS cycle)\n");
		}
		else if(flag == true && mark == true && next == begin && h == n + 1) {
			printf("%d (TS simple cycle)\n", ans);
			if(MIN > ans) {
				MIN = ans;
				MINP = i;
			}
		}
		else if(flag == true && mark == true && next == begin){
			printf("%d (TS cycle)\n", ans);
			if(MIN > ans) {
				MIN = ans;
				MINP = i;
			}
		}
		else {
			printf("%d (Not a TS cycle)\n", ans);
		}
	}
	printf("Shortest Dist(%d) = %d\n", MINP, MIN);
	return 0;
}
