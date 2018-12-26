#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> initSeq;
vector<int> partSeq;

bool judge() {
    int p = 2;
    while(p <= n && partSeq[p-1] <= partSeq[p]) {
        p++;
    }
    int index = p;
    while(p <= n && initSeq[p] == partSeq[p]) {
        p++;
    }
    if(p == n+1) {
        return false;
    }
    else {
        return true;
    }
}

void sort1() {
    int a = partSeq[1];
    int k = 0;
    for(int i = 2; i < n; i++) {
        if(partSeq[i] > a) {
            k = i - 1;
            break;
        }
    }
    swap(partSeq[1], partSeq[k]);
    k--;
    int i = 1;
    int j = i * 2;
    while(j <= k) {
        if(j+1 <= k && partSeq[j+1] > partSeq[j]) {
            j = j + 1;
        }
        if(partSeq[i] < partSeq[j]) {
            swap(partSeq[i], partSeq[j]);
            i = j;
            j = i * 2;
        }
        else {
            break;
        }
    }
}

void sort2() {
    int m = 0;
    for(int i = 2; i <= n; i++) {
        if(partSeq[i] < partSeq[i-1]) {
            m = i;
            break;
        }
    }
    int n = partSeq[m];
    for(int i = m; i > 1; i--) {
        if(partSeq[i] < partSeq[i-1]) {
            partSeq[i] = partSeq[i-1];
            partSeq[i-1] = n;
        }
    }
}

int main() {
    scanf("%d", &n);
    initSeq.resize(n+1);
    partSeq.resize(n+1);
 //   int current;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &initSeq[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &partSeq[i]);
    }
    bool ifHeapSort = judge();
    if(ifHeapSort) {
        printf("Heap Sort\n");
        sort1();
        for(int i = 1; i <= n-1; i++) {
            printf("%d ", partSeq[i]);
        }
        printf("%d", partSeq[n]);
    }
    else {
        printf("Insertion Sort\n");
        sort2();
        for(int i = 1; i <= n-1; i++) {
            printf("%d ", partSeq[i]);
        }
        printf("%d", partSeq[n]);
    }
    return 0;
}
