#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int werewolves1;
	int werewolves2;
};
vector<int> person;
vector<int> guess;
vector<int> werewolf;
vector<node> ans;

bool cmp(node a, node b) {
	return a.werewolves1 != b.werewolves1 ? a.werewolves1 < b.werewolves1 : a.werewolves2 < b.werewolves2;
}

int main() {
	int n;
	scanf("%d", &n);
	person.resize(n + 1);
	guess.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &person[i]);
	}
	for(int i = 1; i < n; i++) {
		for(int j = i + 1; j <= n; j++) {
			werewolf.clear();
			fill(guess.begin(), guess.end(), 0);
			int werewolves = 0;
			for(int k = 1; k <= n; k++) {
				if(k == i || k == j) {
					guess[abs(person[k])] = -person[k];
				}
				else {
					guess[abs(person[k])] = person[k];
				}
			}
			for(int k = 1; k <= n; k++) {
				if(guess[k] < 0) {
					werewolves++;
					werewolf.push_back(k);
				}
			}
			if(werewolves == 2) {
				sort(werewolf.begin(), werewolf.end());
				if((werewolf[0] == i && werewolf[1] != j) || (werewolf[0] == j) || (werewolf[0] != i && werewolf[1] == j)) {
					node current;
					current.werewolves1 = min(werewolf[0], werewolf[1]);
					current.werewolves2 = max(werewolf[0], werewolf[1]);
					ans.push_back(current);
				}
			}
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	if(ans.size() != 0) {
		printf("%d %d", ans[0].werewolves1, ans[0].werewolves2);
	}
	else {
		printf("No Solution");
	}
	return 0;
}
