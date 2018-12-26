#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> temp, ans;
int N, K, P;
int maxSum = -1;

void DFS(int index, int sumK, int sumPow, int sumNum) {
    if(index == 0 || sumPow > N || sumK > K) {
        return;
    }
    if(sumPow == N && sumK == K) {
        if(sumNum > maxSum) {
            maxSum = sumNum;
            ans = temp;
        }
        return;
    }
    temp.push_back(index);
    DFS(index, sumK+1, sumPow+pow(index, P), sumNum+index);
    temp.pop_back();
    DFS(index-1, sumK, sumPow, sumNum);
}

int main() {
    scanf("%d %d %d", &N, &K, &P);
    int a = sqrt(N);
    DFS(a, 0, 0, 0);
    if(maxSum == -1) {
        printf("Impossible");
        return 0;
    }
    printf("%d = %d^%d", N, ans[0], P);
    for(int i = 1; i < ans.size(); i++) {
        printf(" + %d^%d", ans[i], P);
    }
    return 0;
}
