#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct node {
	bool ifHave = false;
	bool ifVisit = false;
	int num = 0;
};
node hashTable[65];

int myHash(char c) {
	if(c >= '0' && c <= '9') {
		return c - '0';
	}
	if(c >= 'a' && c <= 'z') {
		return c - 'a' + 10;
	}
	if(c >= 'A' && c <= 'Z') {
		return c - 'A' + 36;
	}
}

int main() {
	int missBeads = 0;
	int extraBeads = 0;
	bool flag = true;
	char sell[1005];
	char buy[1005];
	scanf("%s", sell);
	scanf("%s", buy);
	for(int i = 0; i < strlen(sell); i++) {
		int num = myHash(sell[i]);
		if(hashTable[num].ifHave == false) {
			hashTable[num].ifHave = true;
		}
		hashTable[num].num++;
	}
	for(int i = 0; i < strlen(buy); i++) {
		int j = myHash(buy[i]);
		if(hashTable[j].ifHave == false) {
			flag = false;
			missBeads++;
		}
		else if(hashTable[j].ifHave == true && hashTable[j].num == 0) {
			flag = false;
			missBeads++;
		}
		else if(hashTable[j].ifHave == true && hashTable[j].num > 0) {
			hashTable[j].num--;
		}
	}
	if(flag == false) {
		printf("No %d", missBeads);
	}
	else {
		for(int i = 0; i < strlen(sell); i++) {
			int j = myHash(sell[i]);
			if(hashTable[j].ifVisit == false) {
				extraBeads = extraBeads + hashTable[j].num;
				hashTable[j].ifVisit = true;
			}
		}
		printf("Yes %d", extraBeads);
	}
	return 0;
}
