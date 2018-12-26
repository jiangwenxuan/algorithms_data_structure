#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int data;
	int address;
	int next;
};

int main() {
	int begin, n, k;
	int s, d, e;
	scanf("%d %d %d", &begin, &n, &k);
	node a[100005];
	vector<node> v, ans;
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d", &s, &d, &e);
		a[s] = {d, s, e};
	}
	for(; begin != -1; begin = a[begin].next) {
		v.push_back(a[begin]);
	}
	int len = v.size();
	for(int i = 0; i < len; i++) {
		if(v[i].data < 0) {
			ans.push_back(v[i]);
		}
	}
	for(int i = 0; i < len; i++) {
		if(v[i].data >= 0 && v[i].data <= k) {
			ans.push_back(v[i]);
		}
	}
	for(int i = 0; i < len; i++) {
		if(v[i].data > k) {
			ans.push_back(v[i]);
		}
	}
	len = ans.size();
	for(int i = 0; i < len; i++) {
		if(i != len - 1) {
			printf("%05d %d %05d\n", ans[i].address, ans[i].data, ans[i + 1].address);
		}
		else {
			printf("%05d %d -1", ans[i].address, ans[i].data);
		}
	}
	return 0;
}