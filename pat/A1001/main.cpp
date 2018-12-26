#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = a + b;
    char str[20];
    sprintf(str, "%d", c);
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        printf("%c", str[i]);
        if(i != len - 1 && str[i] != '-' && (len - i - 1) % 3 == 0) {
            printf(",");
        }
    }
    return 0;
}