#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 99999999;

int distanace[510][510];
int theTime[510][510];

int dis[510];
int timeLeast[510];
int disPre[510];

int needTime[510];
int passNode[510];
int timePre[510];

bool visit[510];

int n, m;

vector<int> disPath, timePath;

void dijkstraDis(int s) {
	fill(dis, dis + 510, INF);
	fill(timeLeast, timeLeast + 510, INF);
	fill(visit, visit + 510, false);
	dis[s] = 0;
	timeLeast[s] = 0;
	for(int i = 0; i < n; i++) {
		disPre[i] = i;
	}
	for(int i = 0; i < n; i++) {
	    int u = -1;
	    int MIN = INF;
	    for(int j = 0; j < n; j++) {
	    	if(visit[j] == false && dis[j] < MIN) {
	    		u = j;
	    		MIN = dis[j];
	    	}
	    }
	    if(u == -1) {
	    	return;
	    }
	    visit[u] = true;
	    for(int j = 0; j < n; j++) {
	    	if(visit[j] == false && distanace[u][j] != INF) {
	    		if(dis[j] > distanace[u][j] + dis[u]) {
	    			dis[j] = distanace[u][j] + dis[u];
	    			disPre[j] = u;
	    			timeLeast[j] = timeLeast[u] + theTime[u][j];
	    		}
	    		else if(dis[j] == distanace[u][j] + dis[u] && timeLeast[j] > timeLeast[u] + theTime[u][j]) {
	    			disPre[j] = u;
	    			timeLeast[j] = timeLeast[u] + theTime[u][j];
	    		}
	    	}
	    }
	}
}

void dfsDis(int source, int destiantion) {
	if(destiantion == source) {
		disPath.push_back(destiantion);
		return;
	}
	dfsDis(source, disPre[destiantion]);
	disPath.push_back(destiantion);
}

void dijkstraTime(int s) {
	fill(visit, visit + 510, false);
	fill(needTime, needTime + 510, INF);
	fill(passNode, passNode + 510, INF);
	needTime[s] = 0;
	passNode[s] = 0;
	for(int i = 0; i < n; i++) {
		timePre[i] = i;
	}
	for(int i = 0; i < n; i++) {
		int u = -1;
		int MIN = INF;
		for(int j = 0; j < n; j++) {
			if(visit[j] == false && MIN > needTime[j]) {
				u = j;
				MIN = needTime[j];
			}
		}
		if(u == -1) {
			return;
		}
		visit[u] = true;
		for(int j = 0; j < n; j++) {
			if(visit[j] == false && theTime[u][j] != INF) {
				if(needTime[j] > needTime[u] + theTime[u][j]) {
					needTime[j] = needTime[u] + theTime[u][j];
					timePre[j] = u;
					passNode[j] = passNode[u] + 1;
				}
				else if(needTime[j] == needTime[u] + theTime[u][j] && passNode[j] > passNode[u] + 1) {
					timePre[j] = u;
					passNode[j] = passNode[u] + 1;
				}
			}
		}
	}
}

void dfsTime(int source, int destiantion) {
	if(destiantion == source) {
		timePath.push_back(source);
		return;
	}
	dfsTime(source, timePre[destiantion]);
	timePath.push_back(destiantion);
}

int main() {
	scanf("%d %d", &n, &m);
	fill(distanace[0], distanace[0] + 510 * 510, INF);
	fill(theTime[0], theTime[0] + 510 * 510, INF);
	int s1, s2, ifOneWay, len, time;
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d %d %d", &s1, &s2, &ifOneWay, &len, &time);
		distanace[s1][s2] = len;
		theTime[s1][s2] = time;
		if(ifOneWay != 1) {
			distanace[s2][s1] = len;
			theTime[s2][s1] = time;
		}
	}
	int source, destiantion;
	scanf("%d %d", &source, &destiantion);
	dijkstraDis(source);
	dfsDis(source, destiantion);
	dijkstraTime(source);
	dfsTime(source, destiantion);
	printf("Distance = %d", dis[destiantion]);
	if(disPath == timePath) {
		printf("; Time = %d: ", needTime[destiantion]);
	}
	else {
		printf(": ");
		for(int i = 0; i < disPath.size(); i++) {
			printf("%d", disPath[i]);
			if(i != disPath.size() - 1) {
				printf(" -> ");
			}
		}
		printf("\nTime = %d: ", needTime[destiantion]);
	}
	for(int i = 0; i < timePath.size(); i++) {
		printf("%d", timePath[i]);
		if(i != timePath.size() - 1) {
			printf(" -> ");
		}
	}
	return 0;
}
