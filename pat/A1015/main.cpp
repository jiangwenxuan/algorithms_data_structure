#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int x) {
	int flag = true;
	if(x == 1 || x == 0) {
        return false;
	}
	int m = (int)sqrt(x * 1.0);
	for(int i = 2; i <= m; i++) {
		if(x % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

int change(int n, int x) {
	vector<int> record;
	while(n != 0) {
		record.push_back(n % x);
		n = n / x;
	}
	int ans = 0;
	int s = 1;
	for(int i = record.size() - 1; i >= 0; i--) {
		ans = ans + record[i] * s;
		s = s * x;
	}
	return ans;
}

int main() {
	int n, x;
	scanf("%d", &n);
	while(n > 0) {
		scanf("%d", &x);
		int m = change(n, x);
		if(isPrime(m) == true && isPrime(n) == true) {
			printf("Yes");
		}
		else {
			printf("No");
		}
		scanf("%d", &n);
	}
	return 0;
}
