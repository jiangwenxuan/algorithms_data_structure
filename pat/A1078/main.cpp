#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool record[10010] = {false};
vector<int> s;

void init() {
	for(int i = 2; i < 10010; i++) {
		if(record[i] == false) {
			s.push_back(i);
		}
		for(int j = i + i; j < 10010; j = j + i) {
			record[j] = true;
		}
	}
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	init();
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= m) {
			m = s[i];
			break;
		}
	}
	bool* a = new bool[m];
	fill(a, a + m, false);
	for(int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		int current;
		int j = 0;
		bool mark = false;
		while(j <= m) {
			current = (k + j * j) % m;
			if(a[current] == false) {
				a[current] = true;
				mark = true;
				printf("%d", current);
				break;
			}
			else {
				j++;
			}
		}
		if(mark == false) {
			printf("-");
		}
		if(i != n-1) {
			printf(" ");
		}
	}
	return 0;
}
