#include <cstdio>
#include <cmath>
using namespace std;

bool visit[10005] = {false};
int award[10005] = {0};

bool isPrime(int x) {
    if(x == 1 || x == 0) {
        return false;
    }
	int s = (int)sqrt(1.0 * x);
	for(int i = 2; i <= s; i++) {
		if(x % s == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	int id;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &id);
		visit[id] = true;
		if(i == 1) {
			award[id] = 1;
		}
		else if(isPrime(i) == true) {
			award[id] = 2;
		}
		else {
			award[id] = 3;
		}
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		scanf("%d", &id);
		if(visit[id] == false) {
			printf("%04d: Are you kidding?\n", id);
		}
		else {
			switch(award[id]) {
				case 1:
					printf("%04d: Mystery Award\n", id);
					break;
				case 2:
					printf("%04d: Minion\n", id);
					break;
				case 3:
					printf("%04d: Chocolate\n", id);
					break;
				case 4:
					printf("%04d: Checked\n", id);
					break;
			}
		}
		award[id] = 4;
	}
	return 0;
}
