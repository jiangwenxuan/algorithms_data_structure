#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int deal(int num) {
	int s = 0;
	while(num != 0) {
		s = s + num % 10;
		num = num / 10;
	}
	return s;
}

bool s[10005] = {false};
vector<int> v;

int main() {
	int n;
	int num;
	int ans;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		ans = deal(num);
		if(s[ans] == false) {
			v.push_back(ans);
			s[ans] = true;
		}
	}
	printf("%d\n", v.size());
	sort(v.begin(), v.end());
	printf("%d", v[0]);
	for(int i = 1; i < v.size(); i++) {
		printf(" %d", v[i]);
	}
	return 0;
}