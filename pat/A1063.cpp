

#include <cstdio>
#include <set>
using namespace std;

set<int> st;
int a[52][10010];

int main() {
    int N, M, num;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &M);
        for (int j = 0; j < M; j++) {
            scanf("%d", &num);
            st.insert(num);
        }
        for (int k = 1; k <= st.size(); k++) {
            set<int>::iterator it = st.begin();
            a[i][0] = st.size();
            a[i][k] = *it;
            it++;
        }
        st.clear();
    }
    int cmpNum, array1, array2, count;
    count = 0;
    scanf("%d", &cmpNum);
    for (int i = 1; i <= cmpNum; i++) {
        scanf("%d%d", &array1, &array2);
        for (int j = 1; j <= a[array1][0]; j++) {
            st.insert(a[array1][j]);
        }
        for (int k = 1; k <= a[array2][0]; k++) {
            if (st.end() != st.find(a[array2][k])) {
                count++;
            }
        }
        printf("%.1f%%\n", ((double)count) / ((double)(a[array1][0] + a[array2][0] - count)) * 100);
        st.clear();
        count = 0;
    }
    return 0;
}
