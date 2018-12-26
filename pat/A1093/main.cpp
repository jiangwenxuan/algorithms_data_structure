#include <string>
#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    long long p = 0;
    long long a = 0;
	int begin = 0;
	while(str[begin] != 'P') {
		begin++;
	}
	long ans = 0;
	int len = str.length();
	for(int i = begin; i < len; i++) {
		if(str[i] == 'P') {
			p++;
		}
		else if(str[i] == 'A') {
			a = a + p;
		}
		else if(str[i] == 'T') {
			ans = ans + a;
		}
	}
	printf("%lld", ans % 1000000007);
	return 0;
}
