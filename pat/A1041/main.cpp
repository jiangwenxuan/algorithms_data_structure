#include <cstdio>
#include <vector>
using namespace std;

int visit[10005] = {0};

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        visit[v[i]]++;
    }
    bool flag = true;
    int mark = 0;
    for(int i = 0; i < n; i++) {
        if(visit[v[i]] == 1) {
            mark = v[i];
            flag = false;
            break;
        }
    }
    if(flag == false) {
        printf("%d", mark);
    }
    else {
        printf("None");
    }
    return 0;
}
