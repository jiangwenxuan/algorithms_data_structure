#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char a[5];

bool cmp1(char a, char b) {
	return a > b;
}
bool cmp2(char a, char b) {
	return a < b;
}

int charToNum(char a[]) {
	int ans = 0;
	int j = 1;
	for(int i = 3; i >= 0; i--) {
		ans += a[i] * j;
		j = j * 10;
	}
	return ans;
}
void numToChar(int x) {
	for(int i = 3; i >= 0; i--) {
		a[i] = x % 10;
		x = x / 10;
	}
}

int main() {
	int x;
	scanf("%d", &x);
	int y = 0;
	int z = -1;
	while(z != 6174 && z != 0) {
		numToChar(x);
		sort(a, a + 4, cmp1);
		x = charToNum(a);
		sort(a, a + 4, cmp2);
		y = charToNum(a);
		sort(a, a + 4, cmp2);
		z = x - y;
		printf("%04d - %04d = %04d\n", x, y, z);
		x = z;
	}
}
