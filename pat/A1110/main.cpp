#include <cstdio>
#include <queue>
using namespace std;

struct node {
	int father;
	int lc;
	int rc;
}tree[30];

int findFather(node* tree, int n) {
	for(int i = 0; i < n; i++) {
		if(tree[i].father == -1) {
			return i;
		}
	}
}

bool ifCompleteTree(node* tree, int n, int father, int& h) {
    queue<int> q;
    q.push(father);
    int i = 1;
    while(!q.empty()) {
    	int a = q.front();
    	q.pop();
    	if(i * 2 <= n) {
    		if(tree[a].lc == -1) {
    			h = father;
    			return false;
    		}
    		if(tree[a].lc != -1) {
    			q.push(tree[a].lc);
    		}
    	}
    	if(i * 2 + 1 <= n) {
    		if(tree[a].rc == -1) {
    			h = father;
    			return false;
    		}
    		if(tree[a].rc != -1) {
    			q.push(tree[a].rc);
    		}
    	}
    	i++;
    	h = a;
    }
    return true;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		tree[i].father = -1;
	}
    for(int i = 0; i < n; i++) {
        char l, r;
        getchar();
        scanf("%c %c", &l, &r);
        if (l == '-') {
            tree[i].lc = -1;
        } else {
            tree[i].lc = l - '0';
            tree[l - '0'].father = i;
        }
        if (r == '-') {
            tree[i].rc = -1;
        } else {
            tree[i].rc = r - '0';
            tree[r - '0'].father = i;
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d %d %d\n", tree[i].father, tree[i].lc, tree[i].rc);
    }
	int father = findFather(tree, n);
	int h;
	bool flag = ifCompleteTree(tree, n, father, h);
	if(flag == true) {
		printf("YES %d", h);
	}
	else {
		printf("NO %d", father);
	}
	return 0;
}
