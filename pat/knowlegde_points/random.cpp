#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand((unsigned)time(NULL));
	for(int i = 0; i < 10; i++) {
		printf("%d\n", rand());
	}
	return 0;
}

// form a random number in [0, n] 
int main() {
	srand((unsigned)time(NULL));
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 10; i++) {
		printf("%d ", rand() % (n + 1));
	}
	return 0;
}

// form a random number in [a, b]
int main() {
	srand((unsigned)time(NULL));
	int a, b;
	scanf("%d %d", &a, &b);
	for(int i = 0; i < 10; i++) {
		printf("%d\n", rand() % (b+1) + a);
	}
	return 0;
}
