#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int* a = new int[n];
	int* b = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	int i, j;
	for(i = 0; i < n-1 && b[i] <= b[i+1]; i++);
	for(j = i + 1; a[j] == b[j] && j < n; j++);
	if(j == n) {
		printf("Insertion Sort\n");
		sort(a, a+i+2);
	}
	else {
		printf("Merge Sort\n");
		int k = 1; 
		int flag = 1;
		while(flag) {
			flag = 0;
			for(i = 0; i < n; i++) {
				if(a[i] != b[i]) {
					flag = 1;
				}
			}
			k = 2 * k;
			for(i = 0; i < n / k; i++) {
				sort(a + i * k, a + (i + 1) * k);
			}
			sort(a + n / k * k, a + n);
		}
	}
	for(j = 0; j < n; j++) {
		if(j != 0) {
			printf(" ");
		}
		printf("%d", a[j]);
	}
	delete [] a;
	delete [] b;
	return 0;
}