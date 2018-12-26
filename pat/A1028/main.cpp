#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
	int id;
	int grade;
	char name[10];
};
vector<student> v;

bool cmp1(student a, student b) {
	return a.id < b.id;
}
bool cmp2(student a, student b) {
	if(strcmp(a.name, b.name) != 0) {
		return strcmp(a.name, b.name) < 0;
	}
	else {
		return a.id < b.id;
	}
}
bool cmp3(student a, student b) {
	if(a.grade != b.grade) {
		return a.grade < b.grade;
	}
	else {
		return a.id < b.id;
	}
}

int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	v.resize(n);
	for(int i = 0; i < n; i++) {
		scanf("%d %s %d", &v[i].id, v[i].name, &v[i].grade);
	}
	if(c == 1) {
		sort(v.begin(), v.end(), cmp1);
	}
	else if(c == 2) {
		sort(v.begin(), v.end(), cmp2);
	}
	else {
		sort(v.begin(), v.end(), cmp3);
	}
	for(int i = 0; i < v.size(); i++) {
		printf("%06d %s %d\n", v[i].id, v[i].name, v[i].grade);
	}
	return 0;
}
