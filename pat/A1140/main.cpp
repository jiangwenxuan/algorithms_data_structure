#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int d, num;
	scanf("%d %d", &d, &num);
	vector<int> a, b;
	a.push_back(d);
    while(num > 1) {
    	b.clear();
    	int array[10] = {0};
    	array[a[0]]++;
    	int len = a.size();
    	for(int i = 1; i < len; i++) {
    		if(a[i] != a[i - 1]) {
    			b.push_back(a[i - 1]);
    			b.push_back(array[a[i - 1]]);
    			array[a[i - 1]] = 0;
    			array[a[i]]++;
    		}
    		else {
    			array[a[i]]++;
    		}
    	}
    	b.push_back(a[len - 1]);
    	b.push_back(array[a[len - 1]]);
    	array[a[len - 1]] = 0;
    	a = b;
    	num--;
    }
	int len = a.size();
	for(int i = 0; i < len; i++) {
		printf("%d", a[i]);
	}
	return 0;
}
