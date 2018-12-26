#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int n;
	long long p;
	cin >> n >> p;
	if (n == 0) {
		cout << n;
		return 0;
	}
	long long int *a = new long long int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int result = 1;
	for (int i = 0; i < n; i++) {
	  int b = (int)(upper_bound(a, a+n, a[i] * p) - (a+i));
		result = max(b, result);
	}
	cout << result;
	return 0;
}