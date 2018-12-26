#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct people {
	int ID;
	int v;
	int t;
	int total;
};
vector<people> sages;
vector<people> nobleman;
vector<people> foolman;
vector<people> others;

bool cmp(people a, people b) {
	if(a.total != b.total) {
		return a.total > b.total;
	}
	else if(a.v != b.v) {
		return a.v > b.v;
	}
	else {
		return a.ID < b.ID;
	}
}

int main() {
    int N, L, H;
    scanf("%d %d %d", &N, &L, &H);
    int id, vG, tG;
    people current;
    int num = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d %d %d", &id, &vG, &tG);
		if(vG >= L && tG >= L) {
			num++;
			current.ID = id;
			current.v = vG;
			current.t = tG;
			current.total = vG + tG;
		  	if(vG >= H && tG >= H) {
		  		sages.push_back(current);
		  	}
		  	if(vG >= H && tG < H) {
		  		nobleman.push_back(current);
		  	}
		  	if(vG < H) {
		  		if(vG >= tG) {
		  			foolman.push_back(current);
		  		}
		  		else {
		  			others.push_back(current);
		  		}
		  	}
		}
    }
    sort(sages.begin(), sages.end(), cmp);
    sort(nobleman.begin(), nobleman.end(), cmp);
    sort(foolman.begin(), foolman.end(), cmp);
    sort(others.begin(), others.end(), cmp);
    printf("%d\n", num);
    int i;
    for(i = 0; i < sages.size(); i++) {
    	printf("%d %d %d\n", sages[i].ID, sages[i].v, sages[i].t);
    }
    for(i = 0; i < nobleman.size(); i++) {
    	printf("%d %d %d\n", nobleman[i].ID, nobleman[i].v, nobleman[i].t);
    }
    for(i = 0; i < foolman.size(); i++) {
    	printf("%d %d %d\n", foolman[i].ID, foolman[i].v, foolman[i].t);
    }
    for(i = 0; i < others.size(); i++) {
    	printf("%d %d %d\n", others[i].ID, others[i].v, others[i].t);
    }
    return 0;
}
