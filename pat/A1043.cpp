#include <iostream>
#include <vector>
using namespace std;

int pre[1005];
vector<int> post;

bool judge1(int preL, int preR, int n) {
    if(n == 0 || n == 1) {
        return true;
    }
    int root = pre[preL];
    int curr;
    for(int i = preL+1; i <= preR; i++) {
        if(pre[i] >= root) {
            curr = i;
            break;
        }
    }
    for(int i = curr+1; i <= preR; i++) {
        if(pre[i] < root) {
            return false;
        }
    }
    return judge1(preL+1, curr-1, curr-preL-1) && judge1(curr, preR, preR-curr);
}

bool judge2(int preL, int preR, int n) {
    if(n == 0 || n == 1) {
        return true;
    }
    int root = pre[preL];
    int curr;
    for(int i = preL+1; i <= preR; i++) {
        if(pre[i] < root) {
            curr = i;
            break;
        }
    }
    for(int i = curr+1; i < preR; i++) {
        if(pre[i] >= root) {
            return false;
        }
    }
    return judge2(preL + 1, curr - 1, curr - preL - 1) && judge2(curr, preR, preR - curr);
}

void transform1(int preL, int preR, int postFlag, int n) {
	if(n == 0) {
		return;
	}
    if(n == 1) {
        post.push_back(pre[preL]);
        return;
    }
    int root = pre[preL];
    int current;
    for(int i = preL+1; i <= preR; i++) {
        if(pre[i] >= root) {
            current = i;
            break;
        }
    }
    transform1(preL+1, current-1, current-2, current-preL-1);
    transform1(current, preR, preR-1, preR-current+1);
    post.push_back(root);
}

void transform2(int preL, int preR, int postFlag, int n) {
    if(n == 0) {
    	return;
	}
	if(n == 1) {
        post.push_back(pre[preL]);
        return;
    }
    int root = pre[preL];
    int current;
    for(int i = preL+1; i <= preR; i++) {
        if(pre[i] < root) {
            current = i;
            break;
        }
    }
    transform2(preL+1, current-1, current-2, current-preL-1);
    transform2(current, preR, preR - 1, preR - current + 1);
    post.push_back(root);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    if(judge1(0, n-1, n)) {
        transform1(0, n-1, n-1, n);
        printf("YES\n%d", post[0]);
        for(int i = 1; i < n; i++) {
            printf(" %d", post[i]);
        }
    }
    else if(judge2(0, n-1, n)) {
        transform2(0, n - 1, n - 1, n);
        printf("YES\n%d", post[0]);
        for (int i = 1; i < n; i++) {
            printf(" %d", post[i]);
        }
    }
    else {
        printf("NO");
    }
    return 0;
}
