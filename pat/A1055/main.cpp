// not good

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct person {
	char name[10];
	int age;
	int worth;
};
person p[100005];

bool cmp1(person a, person b) {
	return a.age < b.age;
}
bool cmp2(person a, person b) {
	if(a.worth != b.worth) {
		return a.worth > b.worth;
	}
	else if(a.age != b.age) {
		return a.age < b.age;
	}
	else {
		return strcmp(a.name, b.name) < 0;
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int j = 0;
	int a, w;
	char current[10] = "Nobody";
	for(int i = 0; i < n; i++) {
		scanf("%s %d %d", p[j].name, &a, &w);
		if(strcmp(p[j].name, current) != 0) {
			p[j].age = a;
			p[j].worth = w;
			j++;
		}
	}
	int m;
	int ageL;
	int ageR;
	for(int i = 1; i <= k; i++) {
		scanf("%d %d %d", &m, &ageL, &ageR);
		sort(p, p+j, cmp1);
		printf("Case #%d\n", i);
		int mark1, mark2;
		for(int k = 0; k < j; k++) {
			if(p[k].age >= ageL) {
				mark1 = k;
				break;
			}
		}
		for(int k = 0; k < j; k++) {
			if(p[k].age > ageR) {
				mark2 = k;
				break;
			}
		}
		if(ageR >= p[j-1].age) {
            mark2 = j;
		}
		if(mark1 == mark2) {
			printf("None\n");
		}
		else {
            sort(p+mark1, p+mark2, cmp2);
            int mark3 = mark1+m;
            if(mark2-mark1 <= m) {
            	mark3 = mark2;
            }
			for(int k = mark1; k < mark3; k++) {
				printf("%s %d %d\n", p[k].name, p[k].age, p[k].worth);
			}
		}
	}
	return 0;
}
