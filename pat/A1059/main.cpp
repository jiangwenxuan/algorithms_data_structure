#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 100010;
int prime[maxn];
struct factor {
	int x;
	int count;
};
factor fac[20];

bool isPrime(int a) {
    int s = (int)sqrt(a * 1.0);
    if(a == 1) {
        return false;
    }
    for(int i = 2; i <= s; i++) {
        if(a % i == 0) {
            return false;
        }
    }
    return true;
}

int findPrime(int n, int pNum) {
	for(int i = 1; i <= maxn; i++) {
        if(isPrime(i) == true) {
            prime[pNum] = i;
            pNum++;
        }
	}
	return pNum;
}

int findFactor(int n, int j, int pNum) {
    int s = (int)sqrt(n * 1.0);
    for(int i = 0; s >= prime[i] && i < pNum; i++) {
        if(n % prime[i] == 0) {
            fac[j].x = prime[i];
            fac[j].count = 0;
            while(n % prime[i] == 0) {
                fac[j].count++;
                n = n / prime[i];
            }
            j++;
        }
        if(n == 1) {
            break;
        }
    }
    if(n != 1) {
        fac[j].count = 1;
        fac[j].x = n;
        j++;
    }
    return j;
}

int main() {
	int n;
	scanf("%d", &n);
	if(n == 1) {
        printf("1=1");
        return 0;
	}
	int a = findPrime(n, 0);
	int s = findFactor(n, 0, a);
	printf("%d=", n);
	for(int i = 0; i < s; i++) {
		if(i != s-1) {
			if(fac[i].count == 1) {
				printf("%d*", fac[i].x);
			}
			else {
				printf("%d^%d*", fac[i].x, fac[i].count);
			}
		}
		else {
			if(fac[i].count == 1) {
				printf("%d", fac[i].x);
			}
			else {
				printf("%d^%d", fac[i].x, fac[i].count);
			}
		}
	}
	return 0;
}
