#include <cstdio>
using namespace std;

// int hash
const int maxn = 1000;
bool hashTable[maxn] = {false};
int main() {
    int n, m, x;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        hashTable[x] = true;
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        if(hashTable[x] == true) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
    return 0;
}



// digit and scale hash
int y = 0, product = 1;
while (x != 0) {
    y = y + (x % 10) * product;
    x = x / 10;
    product = product * p;
}

int z[40], num = 0;
do {
    z[num++] = y % Q;
    y = y / 10;
} while (y != 0);

int main() {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    int sum = a + b;
    int ans[30], num = 0;
    do {
        ans[num++] = sum % 10;
        sum = sum / 10；
    } while (sum != 0);
    for (int i = num - 1; i >= 0; i--) {
        printf("%d", ans[i]);
    }
    return 0;
}