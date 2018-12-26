#include <cstdio>
using namespace std;

int main() {
    int n;
    double v;
    double ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lf", &v);
        ans += v * i * (n + 1 - i);
    }
    printf("%.2lf\n", ans);
    return 0;
}
