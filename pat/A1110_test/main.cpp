#include <iostream>
#include <queue>
using namespace std;
struct node{
    int l, r;
}a[100];
bool ifCompleteTree(int n, int father, int& h) {
    queue<int> q;
    q.push(father);
    int i = 1;
    while(!q.empty()) {
    	int s = q.front();
    	q.pop();
    	if(i * 2 <= n) {
    		if(a[s].l == -1) {
    			h = father;
    			return false;
    		}
    		if(a[s].l != -1) {
    			q.push(a[s].l);
    		}
    	}
    	if(i * 2 + 1 <= n) {
    		if(a[s].r == -1) {
    			h = father;
    			return false;
    		}
    		if(a[s].r != -1) {
    			q.push(a[s].r);
    		}
    	}
    	i++;
    	h = a;
    }
    return true;
}
int main() {
    int n, root = 0, have[100] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        string l, r;
        cin >> l >> r;
        if (l == "-") {
            a[i].l = -1;
        } else {
            a[i].l = stoi(l);
            have[stoi(l)] = 1;
        }
        if (r == "-") {
            a[i].r = -1;
        } else {
            a[i].r = stoi(r);
            have[stoi(r)] = 1;
        }
    }
    while (have[root] != 0) root++;
    int h;
    bool flag = ifCompleteTree(n, root, h);
    if (flag == true)
        cout << "YES " << h;
    else
        cout << "NO " << root;
    return 0;
}
