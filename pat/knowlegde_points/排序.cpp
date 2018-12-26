#include <cstdio>
#include <algorithm>
using namespace std;

int a[100];

void selectSort() {
    for(int i = 1; i <= n; i++) {
        int k = i;
        for(int j = i; j <= n; j++) {
            if(a[j] < a[i]) {
                k = j;
            }
        }
        int temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
}

int b[maxn], n;

void insertSort() {
    for(int i = 2; i <= n; i++) {
        int temp = b[i];
        int j = i;
        while(j > 1 && temp < b[j-1]) {
            b[j] = b[j-1];
            j--;
        }
        b[j] = temp;
    }
}