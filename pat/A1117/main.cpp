#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	int n;
	scanf("%d", &n);
	int* array = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	sort(array, array + n, cmp);
	int i = 0;
	while(i < n) {
      if(n - i < array[i]) {
        break;
      }
      i++;
	}
	printf("%d", n - i);
	return 0;
}