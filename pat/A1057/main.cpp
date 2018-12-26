#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;

stack<int> s;
int table[100001] = {0};
int block[316] = {0};

void peekMedian(int k) {
	int sum = 0;
	int idx = 0;
	while(sum + block[idx] < k) {
		sum = sum + block[idx];
		idx++;
	}
	int num = idx * 316;
	while(sum + table[num] < k) {
		sum += table[num];
		num++;
	}
	printf("%d\n", num);
}

void Push(int x) {
	s.push(x);
	block[x / 316]++;
	table[x]++;
}

void Pop() {
	int x = s.top();
	s.pop();
	block[x / 316]--;
	table[x]--;
	printf("%d\n", x);
}

int main() {
	int n;
	scanf("%d", &n);
	char cmd[20];
	for(int i = 0; i < n; i++) {
		scanf("%s", cmd);
		if(strcmp(cmd, "Push") == 0) {
			int d;
			scanf("%d", &d);
			Push(d);
		}
		else if(strcmp(cmd, "Pop") == 0) {
			int h = s.size();
			if(h == 0) {
				printf("Invalid\n");
			}
			else {
				Pop();
			}
		}
		else {
			int h = s.size();
			int k;
			if(h == 0) {
				printf("Invalid\n");
			}
			else {
				if(h % 2 == 1) {
					k = (h + 1) / 2;
				}
				else {
					k = h / 2;
				}
				peekMedian(k);
			}
		}
	}
	return 0;
}
