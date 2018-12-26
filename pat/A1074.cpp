#include <iostream>
using namespace std;

int main() {
	int firstAdd, N, K, sum = 0;
	scanf("%d %d %d", &firstAdd, &N, &K);
	int temp, data[100005], next[100005], list[100005], result[100005];
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		scanf("%d %d", &data[temp], &next[temp]);
	}
	while(firstAdd != -1) {
		list[sum] = firstAdd;
		firstAdd = next[firstAdd];
		sum++;
	}
	for(int i = 0; i < sum; i++) {
		result[i] = list[i];
	}
	for(int i = 0; i < (sum - sum%K); i++) {
		result[i] = list;
	}
}