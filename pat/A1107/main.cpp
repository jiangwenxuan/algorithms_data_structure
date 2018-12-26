#include <cstdio>
#include <algorithm>
using namespace std;

int father[1005];
int hobby[1005];
int isRoot[1005] = {0};

int findFather(int a) {
    int x = a;
    while(x != father[x]) {
        x = father[x];
    }
    while(a != x) {
        int m = a;
        a = father[a];
        father[m] = x;
    }
    return x;
}

void Union(int a, int b) {
    int A = findFather(a);
    int B = findFather(b);
    if(A != B) {
        father[A] = B;
    }
    return;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        father[i] = i;
    }
    for(int i = 1; i <= n; i++) {
        int num, likes;
        scanf("%d:", &num);
        for(int j = 0; j < num; j++) {
            scanf("%d", &likes);
            if(hobby[likes] == 0) {
                hobby[likes] = i;
            }
            else {
                Union(i, hobby[likes]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(i == father[i]) {
            ans++;
            isRoot[i]++;
        }
        else {
            isRoot[findFather(i)]++;
        }
    }
    sort(isRoot, isRoot+1005, cmp);
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++) {
        printf("%d", isRoot[i]);
        if(i != ans - 1) {
            printf(" ");
        }
    }
    return 0;
}
