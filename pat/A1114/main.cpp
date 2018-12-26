#include <cstdio>
#include <algorithm>
using namespace std;

bool visit[10000] = {false};
int father[10000];

struct Data {
	int id;
	int fid;
	int mid;
	int num;
	int children[7];
	int estate;
	int area;
};
Data data[10000];

struct node {
	int id;
	int number;
	double estate;
	double area;
	bool flag;
};
node record[10000];

int find(int x) {
	int current = x;
	while(x != father[x]) {
		x = father[x];
	}
	int a = current;
	while(a != x) {
		current = father[a];
		father[a] = x;
		a = current;
	}
	return x;
}

void Union(int a, int b) {
	int faA = find(a);
	int faB = find(b);
	if(faA > faB) {
		father[faA] = faB;
	}
	else if(faA < faB) {
		father[faB] = faA;
	}
}

bool cmp(node a, node b) {
	if(a.area != b.area) {
		return a.area > b.area;
	}
	else {
		return a.id < b.id;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 10000; i++) {
		father[i] = i;
	}
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &data[i].num);
		visit[data[i].id] = true;
		if(data[i].fid != -1) {
			Union(data[i].id, data[i].fid);
			visit[data[i].fid] = true;
		}
		if(data[i].mid != -1) {
			visit[data[i].mid] = true;
			Union(data[i].id, data[i].mid);
		}
		for(int j = 0; j < data[i].num; j++) {
			scanf("%d", &data[i].children[j]);
			visit[data[i].children[j]] = true;
			Union(data[i].id, data[i].children[j]);
		}
		scanf("%d %d", &data[i].estate, &data[i].area);
	}
	for(int i = 0; i < n; i++) {
		int id = find(data[i].id);
		record[id].id = id;
		record[id].area += data[i].area;
		record[id].estate += data[i].estate;
		record[id].flag = true;
	}
	int count = 0;
	for(int i = 0; i < 10000; i++) {
		if(record[i].flag == true) {
			count++;
		}
		if(visit[i] == true) {
			record[find(i)].number++;
		}
	}
	printf("%d\n", count);
	for(int i = 0; i < 10000; i++) {
		if(record[i].flag == true) {
			record[i].area = (double)(record[i].area * 1.0 / record[i].number);
			record[i].estate = (double)(record[i].estate * 1.0 / record[i].number);
		}
	}
	sort(record, record + 10000, cmp);
	for(int i = 0; i < count; i++) {
		printf("%04d %d %.3lf %.3lf\n", record[i].id, record[i].number, record[i].estate, record[i].area);
	}
	return 0;
}
