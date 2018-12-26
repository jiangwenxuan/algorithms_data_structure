#include <cstdio>
#include <cstring>
using namespace std;

bool hashNum[40] = {false};
int myHash(char a) {
    if(a >= '0' && a <= '9') {
        return a - '0';
    }
    if(a >= 'a' && a <= 'z') {
        return a - 'a' + 10;
    }
    if(a >= 'A' && a <= 'Z') {
        return a - 'A' + 10;
    }
    return 36;
}

int main() {
    char a[85];
    char b[85];
    gets(a);
    gets(b);
    int lenA = strlen(a);
    int j = 0;
    for(int i = 0; i < lenA; i++) {
        if(a[i] != b[j]) {
            int m = myHash(a[i]);
            if(hashNum[m] == false) {
                hashNum[m] = true;
                if (a[i] >= 'a' && a[i] <= 'z') {
                    printf("%c", (a[i] - 32));
                }
                else {
                    printf("%c", a[i]);
                }
            }
        }
        else {
            j++;
        }
    }
    return 0;
}
