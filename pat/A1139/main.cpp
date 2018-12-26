#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 1 means male; 2 means female;
int gender[10005] = {0};
vector<int> adj[10005];
int g[10005][10005];

struct node {
	int first, second;
};

bool cmp(node a, node b) {
	return a.first != b.first ? a.first < b.first : a.second < b.second;
}

vector<node> path;

void find(int loverA, int loverB) {
	node current;
	if(gender[loverA] != gender[loverB]) {
		int len1 = adj[loverA].size();
		int len2 = adj[loverB].size();
		for(int i = 0; i < len1; i++) {
			for(int j = 0; j < len2; j++) {
				int c = adj[loverA][i];
				int d = adj[loverB][j];
				if(gender[c] == gender[loverA] && gender[d] == gender[loverB] && g[c][d] == 1) {
					current.first = c;
					current.second = d;
					path.push_back(current);
				}
			}
		}
	}
	else {
		int len1 = adj[loverA].size();
		int len2 = adj[loverB].size();
		for(int i = 0; i < len1; i++) {
			for(int j = 0; j < len2; j++) {
				int c = adj[loverA][i];
				int d = adj[loverB][j];
				if(gender[c] == gender[d] && gender[d] == gender[loverA]) {
					if(c != loverB && d != loverA && g[c][d] == 1) {
						current.first = c;
						current.second = d;
						path.push_back(current);
					}
				}
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		string A, B;
		int a, b;
		cin >> A >> B;
		int flag1, flag2;
		a = abs(stoi(A));
		b = abs(stoi(B));
		if(A[0] == '-') {
			flag1 = 2;
		}
		else {
			flag1 = 1;
		}
		if(B[0] == '-') {
			flag2 = 2;
		}
		else {
			flag2 = 1;
		}
		gender[a] = flag1;
		gender[b] = flag2;
		adj[a].push_back(b);
		adj[b].push_back(a);
		g[a][b] = g[b][a] = 1;
	}
	int k;
	scanf("%d", &k);
	int loverA, loverB;
	for(int i = 0; i < k; i++) {
		scanf("%d %d", &loverA, &loverB);
		loverA = abs(loverA);
		loverB = abs(loverB);
		path.clear();
		find(loverA, loverB);
		sort(path.begin(), path.end(), cmp);
		int len = path.size();
		printf("%d\n", len);
		for(int i = 0; i < len; i++) {
			printf("%04d %04d\n", path[i].first, path[i].second);
		}
	}
	return 0;
}
