#include <cstdio>
using namespace std;

int f(int n) {
    if(n == 0) {
        return 1;
    }
    else {
        return f(n-1) * n;
    }
}

const int maxn = 10;
int n;
int P[maxn];
bool hashTable[maxn] = {false};

void generateP(int index) {
    if(index == n+1) {
        for(int i = 1; i <= n; i++) {
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }
    for(int x = 1; x <= n; x++) {
        if(hashTable[x] == false) {
            P[index] = x;
            hashTable[x] = true;
            generate(index+1);
            hashTable[x] = false;
        }
    }
}

int main() {
    n = 3;
    generateP(1);
    return 0;
}

// n queen

int count = 0; 
void generateP(int index) {
    if(index == n+1) {
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            for(int j = i+1; j <= n; j++) {
                if(abs(i-1) == abs(P[i] - P[j])) {
                    flag = false;
                }
            }
        }
        if(flag) {
            count++;
        }
        return;
    }
    for(int x = 1; x <= n; x++) {
        if(hashTable[x] = false) {
            P[index] = x;
            hashTable[x] = true;
            generateP(index+1);
            hashTable[x] = false;
        }
    }
}

void generateP(int index) {
    if(index == n+1) {
        count++;
        return;
    }
    for(int x = 1; x <= n; x++) {
        if(hashTable[x] == false) {
            bool flag = true;
            for(int pre = 1; pre < index; pre++) {
                if(abs(index - pre) == abs(x - P[pre])) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                P[index] = x;
                hashTable[x] = true;
                generateP(index+1);
                hashTable[x] = false;
            }
        }
    }
}