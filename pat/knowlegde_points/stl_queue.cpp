#include <queue>
#include <iostream>
using namespace std;

int main() {
	queue<int> q;
	for(int i = 0; i < 6; i++) {
		q.push(i);
	}
	int a = q.front();
	int b = q.back();
	int c = q.size();
	bool d = q.empty();
	return 0;
}