#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct timeData {
	int hour;
	int min;
	int second;
	int status;
};

struct node {
	bool ignore;
	int totalTime;
	vector<timeData> v;
}

bool cmp(timeData a, timeData b) {
	if(a.hour != b.hour) {
		return a.hour < b.hour;
	}
	else if(a.min != b.min) {
		return a.min < b.min;
	}
	else {
		return a.second < b.second;
	}
}

map<string, node> mp;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	char plate_num[10];
	int hou, mi, secon;
	char sta[4];
	string plate;
	char a, b;
	for(int i = 0; i < n; i++) {
		scanf("%s %d%c%d%c%d %s", plate_num, &hou, a, &mi, b, &secon, sta);
		timeData curr;
		plate = plate_num;
		curr.hour = hou;
		curr.min = mi;
		curr
		if(sta[0] == 'i') {

		}	
		else {

		}	
	}
}