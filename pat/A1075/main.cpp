#include <cstdio>
#include <algorithm>
using namespace std;

bool haveSub[100005] = {false};
struct node {
	int name;
	int perfect;
	int score[6];
	bool sub[6];
	int total;
};
node v[100005];

bool cmp(node a, node b) {
	if(a.total != b.total) {
		return a.total > b.total;
	}
	else if(a.perfect != b.perfect) {
		return a.perfect > b.perfect;
	}
	else {
		return a.name < b.name;
	}
}

int main() {
	int N, K, M;
	scanf("%d %d %d", &N, &K, &M);
	int fullMark[K+1];
	for(int i = 1; i <= K; i++) {
		scanf("%d", &fullMark[i]);
	}
	int count = 0;
	int id = 0;
	int index = 0;
	int grade = 0;
	for(int i = 0; i < M; i++) {
		scanf("%d %d %d", &id, &index, &grade);
		if(haveSub[id] == false) {
			haveSub[id] = true;
			count++;
		}
		v[id].sub[index] = true;
		v[id].name = id;
		if(grade > v[id].score[index]) {
			v[id].total = v[id].total - v[id].score[index];
			v[id].score[index] = grade;
			v[id].total = v[id].total + v[id].score[index];
			if(grade >= fullMark[index]) {
				v[id].perfect++;
			}
		}
		if(grade == -1 && v[id].score[index] == 0) {
			v[id].score[index] = 0;
		}
	}
	sort(v, v + N+1, cmp);
	printf("1 %05d %d", v[0].name, v[0].total);
	for(int i = 1; i <= K; i++) {
		if(v[0].score[i] == 0 && v[0].sub[i] == true) {
			printf(" 0");
		}
		else if(v[0].score[i] == 0 && v[0].sub[i] == false) {
			printf(" -");
		}
		else {
			printf(" %d", v[0].score[i]);
		}
	}
	printf("\n");
	int j = 1;
	for(int i = 1; i <= count; i++) {
		if(v[i].total <= 0) {
			break;
		}
		if(v[i].total != v[i-1].total) {
			j = i+1;
		}
		printf("%d %05d %d", j, v[i].name, v[i].total);
		for(int k = 1; k <= K; k++) {
			if(v[i].score[k] == 0 && v[i].sub[k] == true) {
				printf(" 0");
			}
			else if(v[i].score[k] == 0 && v[i].sub[k] == false) {
				printf(" -");
			}
			else {
				printf(" %d", v[i].score[k]);
			}
		}
		printf("\n");
	}
	return 0;
}
