#include <iostream>
#include <vector>
using namespace std;

vector<int> father;

int findFather(int x) {
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    while(a != x) {
        int z = a;
        father[z] = x;
        a = father[a];
    }
    return x;
}

void Union(int a, int b) {
    int A = findFather(a);
    int B = findFather(b);
    if(A != B) {
        father[A] = B;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    father.resize(n);
    for(int i = 0; i < n; i++) {
        father[i] = i;
    }
    int a, b;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        Union(a, b);
    }
    int ans;
    for(int i = 0; i < n; i++) {
        if(i == father[i]) {
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
