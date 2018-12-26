#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct node {
	int height;
	char name[10];
};

vector<node> v;
vector<node> temp;

bool cmp(node a, node b) {
	if(a.height != b.height) {
		return a.height < b.height;
	}
	else {
		return strcmp(a.name, b.name) > 0;
	}
}

int main() {
	int n, row;
	scanf("%d %d", &n, &row);
	node current;
	for(int i = 0; i < n; i++) {
        getchar();
		scanf("%s %d", current.name, &current.height);
		v.push_back(current);
	}
	sort(v.begin(), v.end(), cmp);
	int k = n / row;
	int extra = n - row * k;
	temp.clear();
	temp.resize(extra + k);
	int m = (extra + k) / 2;
	int mark = 1;
	int left = 1;
	temp[m] = v[n - 1];
	for(int i = n - 2; i >= n - (extra + k); i--) {
		if(left % 2 == 1) {
			temp[m - mark] = v[i];
			left++;
		}
		else {
			temp[m + mark] = v[i];
			mark++;
			left++;
		}
	}
	for(int i = 0; i < temp.size(); i++) {
		if(i == 0) {
			printf("%s", temp[i].name);
		}
		else {
			printf(" %s", temp[i].name);
		}
	}
	printf("\n");
	for(int i = row - 2; i >= 0; i--) {
		temp.clear();
		temp.resize(k);
		m = k / 2;
		mark = 1;
		left = 1;
		temp[m] = v[i * k - 1 + k];
		for(int j = k - 2; j >= 0; j--) {
			if(left % 2 == 1) {
				temp[m - mark] = v[i * k + j];
				left++;
			}
			else {
				temp[m + mark] = v[i * k + j];
				left++;
				mark++;
			}
		}
		for(int i = 0; i < temp.size(); i++) {
			if(i == 0) {
				printf("%s", temp[i].name);
			}
			else {
				printf(" %s", temp[i].name);
			}
		}
		printf("\n");
	}
	return 0;
}
