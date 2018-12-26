#include <cstdio>
#include <vector>
#include <map>
using namespace std;

struct node {
	int address;
	int data;
	int next;
};
node add[100005];
vector<node> ans1, ans2;
map<int, bool> mp;

int main() {
	int startAdd, num;
	scanf("%d %d", &startAdd, &num);
	for(int i = 0; i < num; i++) {
		int addr, data, next;
		scanf("%d %d %d", &addr, &data, &next);
		add[addr].address = addr;
		add[addr].data = data;
		add[addr].next = next;
	}
	while(startAdd != -1) {
		if(mp[abs(add[startAdd].data)] == false) {
			ans1.push_back(add[startAdd]);
			mp[abs(add[startAdd].data)] = true;
		}
		else {
			ans2.push_back(add[startAdd]);
		}
		startAdd = add[startAdd].next;
	}
	int len1 = ans1.size();
	int len2 = ans2.size();
	for(int i = 0; i < len1; i++) {
		if(i != len1 - 1) {
			printf("%05d %d %05d\n", ans1[i].address, ans1[i].data, ans1[i + 1].address);
		}
		else {
			printf("%05d %d -1\n", ans1[i].address, ans1[i].data);
		}
	}
	for(int i = 0; i < len2; i++) {
		if(i != len2 - 1) {
			printf("%05d %d %05d\n", ans2[i].address, ans2[i].data, ans2[i + 1].address);
		}
		else {
			printf("%05d %d -1\n", ans2[i].address, ans2[i].data);
		}
	}
	return 0;
}
