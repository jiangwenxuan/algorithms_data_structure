#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int record[100005] = {-1};
bool inTheParty[100005] = {false};
vector<int> v;

int main() {
	int n, m;
	int id1, id2, id3;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &id1, &id2);
		record[id1] = id2;
		record[id2] = id1;
	}
	scanf("%d", &m);
	int* v = new int[m];
	int len = 0;
	for(int i = 0; i < m; i++) {
		scanf("%d", &id3);
		inTheParty[id3] = true;
	}
	for(int i = 0; i < 100005; i++) {
		if(inTheParty[i] == true) {
			if(record[i] == -1) {
				v[len] = i;
				len++;
			}
			if(record[i] != -1 && inTheParty[record[i]] == false) {
				v[len] = i;
				len++;
			}
		}
	}
	sort(v, v + len);
	printf("%d\n%05d", len, v[0]);
	for(int i = 1; i < len; i++) {
		printf(" %05d", v[i]);
	}
	return 0;
}
