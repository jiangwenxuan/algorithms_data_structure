#include <iostream>
#include <map>
using namespace std;

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    map<int, int> m;
    int elm;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &elm);
            ++m[elm]; 
        }
    }
    int count = 0;
    int ans;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->second > count){
            count = it->second;
            ans = it->first;
        }
    }
    printf("%d", ans);
    return 0;
}
