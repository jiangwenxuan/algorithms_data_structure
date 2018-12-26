#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v, temp, ans;

int main() {
	int n;
	scanf("%d", &n);
	v.resize(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	temp = v;
	sort(v.begin(), v.end());
	int max = 0;
	for(int i = 0; i < n; i++) {
		if(v[i] == temp[i] && temp[i] > max) {
			ans.push_back(v[i]);
		}
		if(temp[i] > max) {
			max = temp[i];
		}
	}
	int len = ans.size();
	printf("%d\n", len);
	for(int i = 0; i < len; i++) {
		printf("%d", ans[i]);
		if(i != len - 1) {
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
