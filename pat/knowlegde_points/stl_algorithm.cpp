#include <algorithm>
#include <iostream>
using namespace std;

struct node {
	int a;
	int b;
};

bool cmp(int a, int b) {
	return a > b;
}

bool cmp2(node a, node b) {
	if(a.x != b.x) {
		return a.x > b.x;
	}
	return a.y > b.y;
}

int main() {
	int x = 1, y = 2;
	swap(x, y);
	int a[10];
	for(int i = 1; i <= 10; i++) {
		a[i-1] = i;
	}
	reverse(a, a+5);
	int a[6] = {9, 4, 2, 5, 6, -1};
	sort(a, a+4);
}