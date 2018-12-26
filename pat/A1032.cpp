#include <iostream>
using namespace std;

struct node {
	char data;
	int next;
	int num;
};
node n1[100005];

int main() {
	int add1, add2, N;
	int address;
	scanf("%d %d %d", &add1, &add2, &N);
	for(int i = 0; i < N; i++) {
		scanf("%d ", &address);
		scanf("%c %d", &n1[address].data, &n1[address].next);
	}
	while(add1 != -1) {
		n1[add1].num = 1;
		add1 = n1[add1].next;
	}
	int target;
	bool flag = false;
	while(add2 != -1) {
		if(n1[add2].num == 1) {
			target = add2;
			flag = true;
			break;
		}
		add2 = n1[add2].next;
	}
	if(flag) {
		printf("%05d", target);
	}
	else {
		printf("-1");
	}
	return 0;
}
