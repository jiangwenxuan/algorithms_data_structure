#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct factor {
	int x;
	int count;
};
factor fac[10];

const int maxn = 100;
bool notPrime[maxn];
int prime[maxn];
int pNum = 0;

void findPrime() {
	for(int i = 2; i < maxn; i++) {
		if(notPrime[i] == false) {
			prime[pNum] = i;
			pNum++;
			for(int j = i + i; j < maxn; j = j + i) {
				notPrime[j] = true;
			}
		}
	}
}

int findFactor(int n) {
	int num = 0;
	int s = (int)sqrt(n * 1.0);
	for(int i = 0; prime[i] <= s; i++) {
		if(n % prime[i] == 0) {
			fac[num].x = prime[i];
			fac[num].count = 0;
			while(n % prime[i] == 0) {
				fac[num].count++;
				n = n / prime[i];
			}
			num++;
		}
	}
	if(n != 1) {
		fac[num].x = n;
		fac[num].count = 1;
	}
	return num;
}