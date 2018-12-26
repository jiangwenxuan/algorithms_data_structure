#include <iostream>
#include <map>
using namespace std;

struct node {
	int a;
};

int main() {
    map<char, node> mp;
    node current;
    current.a = 50;
    mp['c'] = current;
    printf("%d\n", mp['c']);
//    for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
//        printf("%c %d\n", it->first, it->second);
//    }
    map<char, node>::iterator it = mp.find('h');
    printf("%d", it->second);
    return 0;
}
