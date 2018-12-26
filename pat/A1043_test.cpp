#include <iostream>
using namespace std;

int array[1005];

bool judge1(int preL, int preR, int n) {
    if(n == 0 || n == 1) {
        return true;
    }
    int root = array[preL];
    int current;
    for(int i = preL+1; i <= preR; i++) {
        if(array[i] >= root) {
            current = i;
            break;
        }
    }
    for(int i = current+1; i <= preR; i++) {
        if(array[i] < root) {
            return false;
        }
    }
    return judge1(preL+1, current-1, current-preL-1) && judge1(current, preR, preR-current+1);
}

bool judge2(int preL, int preR, int n) {
    if(n == 0 || n == 1) {
        return true;
    }
    int root = array[preL];
    int current;
    for(int i = preL+1; i <= preR; i++) {
        if(array[i] < root) {
            current = i;
            break;
        }
    }
    for(int i = current+1; i <= preR; i++) {
        if(array[i] >= root) {
            return false;
        }
    }
    return judge2(preL + 1, current - 1, current - preL - 1) && judge2(current, preR, preR - current+1);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	if(judge2(0, n-1, n)) {
		printf("true");
	}
	else {
		printf("false");
	}
	return 0;
}
