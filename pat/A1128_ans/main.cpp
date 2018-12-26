#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int k, n;
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		scanf("%d", &n);
		vector<int> v(n);
		bool result = true;
		for(int j = 0; j < n; j++) {
			scanf("%d", &v[j]);
			for(int m = 0; m < j; m++) {
				if((v[j] == v[m]) || abs(v[j] - v[m]) == abs(j - m)) {
					result = false;
				}
			}
		}
		if(result == true) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
