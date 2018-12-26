#include <cstdio>
#include <set>
using namespace std;

int main() {
    set<double> st;
    st.insert(3);
    st.insert(2);
    st.insert(1);
    for (set<double>::iterator it = st.begin(); it != st.end(); it++) {
        printf("%d", *it);
    }
    double a = *(st.find(2.5));
    printf("%f", a);
    return 0;
}
