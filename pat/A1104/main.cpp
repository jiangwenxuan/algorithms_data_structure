#include <cstdio>
#include <vector>
using namespace std;

struct data {
	double num;
	int times;
};

int main() {
	int n;
	scanf("%d", &n);
	vector<data> array(n);
	double ans = 0.0;
	for(int i = 0; i < n; i++) {
		scanf("%lf", &array[i].num);
		if(i == 0) {
			array[i].times = n;
		}
		else {
			array[i].times = array[i-1].times - i + (n - i);
		}
		ans = ans + array[i].num * array[i].times;
	}
	printf("%.2lf", ans);
	return 0;
}
