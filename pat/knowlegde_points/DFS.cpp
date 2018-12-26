#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 30;
int n, V, maxValue = 0;
int w[maxn], c[maxn];

void DFS(int index, int sumW, int sumC) {
    if(index == n) {
        if(sumW <= V && sumC >= maxValue) {
            maxValue = sumC;
        }
        return;
    }
    DFS(index+1, sumW, sumC);
    DFS(index+1, sumW+w[index], sumC+c[index]);
}

int main() {
    scanf("%d %d", &n, &V);
    for(int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    DFS(0, 0, 0);
    printf("%d", maxValue);
    return 0;
}

// a new and better DFS

void DFS(int index, int sumW, int sumC) {
    if(index == n) {
        return;
    }
    DFS(index+1, sumW, sumC);
    if(sumW+w[index] <= V) {
        if(sumC+c[index] >= maxValue) {
            maxValue = sumC + c[index];
        }
        DFS(index+1, sumW+w[index], sumC+c[index]);
    }
}

// a new exercise

int N, K, X, maxSqu;
int A[maxN]
vector<int> temp, ans;

void DFS(int index, int nowk, int sum, int sumSqu) {
    if(nowK == K && sum == X) {
        if(sumSqu > maxSqu) {
            maxSqu = sumSqu;
            ans = temp;
        }
        return;
    }
    if(nowK > K || sum > X || index == N) {
        return;
    }
    DFS(index+1, nowK, sum, sumSqu);
    temp.push_back(A[index]);
    DFS(index+1, nowK+1, sum+A[index], sumSqu + A[index]*A[index]);
    temp.pop_back();
}