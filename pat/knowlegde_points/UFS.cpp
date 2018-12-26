// union, find, set
// means a data structure called set, which can union two sets, and we can find a 
// if an element is in the set

#include <cstdio>
using namespace std;

int father[N];

void init(int num) {
    for(int i = 0; i < num; i++) {
        father[i] = i;
    }
}

int findFather(int x) {
    while(x != father[x]) {
        x = father[x];
    }
    return x;
}

void union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        father[faB] = faA;
    }
}

int betterFindFather(int x) {
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
} 

// recursion betterFindFather
int betterFindFather(int x) {
    if(x == father[x]) {
        return;
    }
    else {
        int F = betterFindFather(father[x]);
        father[x] = F;
        return F;
    }
}