#include <cstdio>
using namespace std;

int main() {
  int n, total = 0, now = 0, to;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &to);
    if(to > now) {
      total = total + (to - now) * 6 + 5;
      now = to;
    }
    else if(to < now) {
      total = total + (now - to) * 4 + 5;
      now = to;
    }
    else {
      total = total + 5;
    }
  }
  printf("%d\n", total);
  return 0;
}