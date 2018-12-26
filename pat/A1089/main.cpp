#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int* init = new int[n];
    int* partSort = new int[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &init[n]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &partSort[i]);
    }
    int i = 0;
    int j = 0;
    for(; i < n-1 && partSort[i] < partSort[i+1]; i++);
    for(j = i+1; j < n && partSort[j]) == init[j]; j++);
    if(j == n) {
        printf("Insertion Sort\n");
        sort(init, init + i + 2);
    }
    else {
        printf("Merge Sort\n");
        bool mark = false;
        int k = 1;
        while(mark == false) {
            mark = true;
            for(i = 0; i < n; i++) {
                if(partSort[i] != init[i]) {
                    mark = false;
                }
            }
            k = 2 * k;
            for(i = 0; i < n / k; i++) {
                sort(init + i * k, init + (i + 1) * k);
            }
            sort(init + n / k * k, init + n);
        }
    }
    printf("%d", init[0]);
    for(i = 1; i < n; i++) {
        printf(" %d", init[i]);
    }
    return 0;
}
