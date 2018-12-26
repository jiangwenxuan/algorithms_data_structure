#include <cstdio>
#include <algorithm>
using namespace std;

struct cake {
	double store;
	double sell;
	double price;
};

bool cmp(cake a, cake b) {
	return a.price > b.price;
}

int main() {
	int n, d;
	scanf("%d %d", &n, &d);
	vector<cake> v(n);
	for(int i = 0; i < n; i++) {
		scanf("%lf", &v[i].store);
	}
	for(int i = 0; i < n; i++) {
		scanf("%lf", &v[i].sell);
		v[i].price = v[i].sell / v[i].store;
	}
	sort(v.begin(), v.end(), cmp);
	double moneyAmount = 0;
	for(int i = 0; i < n; i++) {
		int j = v[i].store - d;
		if(j > 0) {
			moneyAmount = moneyAmount + d * v[i].price;
			break;
		}
		else {
			moneyAmount = moneyAmount + v[i].price * v[i].store;
			d = d - v[i].store;
		}
	}
	printf("%.2lf", moneyAmount);
	return 0;
}