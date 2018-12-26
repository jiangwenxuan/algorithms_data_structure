#include <iostream>
using namespace std;
int main() {
	char a[5];
	int b;
	scanf("%s", a);
	if(len(a) == 4){
		scanf("%d", &b);
		printf("%d", b);
	}
	else {
		printf("wow");
	}
	return 0;
}
