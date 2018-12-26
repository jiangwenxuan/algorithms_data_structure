#include <cstdio>
using namespace std;

int main() {
    int n;
    int ans = 0;
    scanf("%d", &n);
    int a = 1;
    int left;
    int right;
    int now;
    while(n / a != 0) {
   		left = n / (a * 10);
   		now = n / a % 10;
   		right = n % a;
   		if(now == 0) {
   			ans = ans + left * a;
   		}
   		else if(now > 1) {
   			ans = ans + (left + 1) * a; 
   		}
   		else {
   			ans = ans + left * a + right + 1;
   		}
   		a = a * 10;
    }
    printf("%d", ans);
    return 0;
}
