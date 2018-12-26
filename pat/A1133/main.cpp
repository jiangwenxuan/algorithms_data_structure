#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int address;
	int data;
	int nextAddress;
};
node record[100005];
vector<node> v;

int main() {
	int beginAdd, n, k;
	scanf("%d %d %d", &beginAdd, &n, &k);
	for(int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d", &a);
        scanf("%d %d", &record[a].data, &record[a].nextAddress);
        record[a].address = a;
	}
	while(beginAdd != -1) {
		node current = record[beginAdd];
		v.push_back(current);
		beginAdd = record[beginAdd].nextAddress;
	}
	int len = v.size();
	int mark = -1;
	int h = len;
	int i = 0;
	while(i < len) {
		if(i == h) {
			break;
		}
		if(v[i].data < 0) {
			node current = v[i];
			for(int j = i; j > mark + 1; j--) {
				v[j] = v[j - 1];
			}
			v[mark + 1] = current;
			mark++;
			i++;
		}
		else if(v[i].data > k) {
			node current = v[i];
			for(int j = i; j < len - 1; j++) {
				v[j] = v[j + 1];
			}
			v[len - 1] = current;
			h--;
		}
		else {
			i++;
		}
	}
	for(int i = 0; i < len; i++) {
		if(i != len - 1) {
			printf("%05d %d %05d\n", v[i].address, v[i].data, v[i + 1].address);
		}
		else {
			printf("%05d %d -1", v[i].address, v[i].data);
		}
	}
	return 0;
}