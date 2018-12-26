#include <cstdio>
using namespace std;

int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int r[11];

void init(int n) {
    for(int i = 0; i <= n; i++) {
        r[i] = -10;
    }
}

int memo_cut_rod_aux(int n) {
    int q;
    if(r[n] >= 0) {
        return r[n];
    }
    if(n == 0) {
        q = 0;
    }
    else {
        q = -10;
        for(int i = 1; i <= n; i++) {
            if(q < memo_cut_rod_aux(n-i) + p[i]) {
                q = memo_cut_rod_aux(n-i) + p[i];
            }
        }
    }
    r[n] = q;
    return q;
}

int main() {
	init(10);
	int a = memo_cut_rod_aux(10);
	printf("%d", a);
	return 0;
}
