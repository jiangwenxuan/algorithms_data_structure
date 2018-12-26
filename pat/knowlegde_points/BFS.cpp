#include <iostream>
#include <queue>
using namespace std;

int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

const int maxn = 100;
struct Node {
    int x, y;
} node;

int n, m;
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};

bool judge(int x, int y) {
    if(x >= n || x < 0 || y >= m || y < 0) {
        return false;
    }
    if(matrix[x][y] == 0 || inq[x][y] == true) {
        return false;
    }
    return true;
}

void BFS(int x, int y) {
    queue<node> q;
    node.x = x;
    node.y = y;
    q.push(node);
    inq[x][y] = true;
    while(!q.empty()) {
        node top = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX, newY)) {
                node.x = newX;
                node.y = newY;
                q.push(node);
                inq[newX][newY] = true;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            scanf("%d", &matrix[x][y]);
        }
    }
    int ans = 0;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            if(matrix[x][y] == 1 && inq[x][y] == false) {
                ans++;
                BFS(x, y);
            }
        }
    }
    printf("%d", ans);
    return 0;
}



// a new eg

struct node {
    int x;
    int y;
    int step;
};

node S, T, Node;
int n, m;
char matr[maxn][maxn];
bool inq[maxn][maxn];
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool test(int x, int y) {
    if(x >= n || x < 0 || y >= m || y < 0) {
        return false;
    }
    if(inq[x][y] && matr[x][y] == '*') {
        return false;
    }
    return true;
}

int BFS() {
    queue<node> q;
    q.push(S);
    while(!q.empty()) {
        node top = q.front();
        q.pop();
        if(top.x == T.x && top.y == T.y) {
            return top.step;
        }
        for(int i = 0; i < 4; i++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(test(newX, newY)) {
                Node.x = newX;
                Node.y = newY;
                Node.step = top.step + 1;
                q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        getchar();
        for(int j = 0; j < m; j++) {
            matr[i][j] = getchar();
        }
        matr[i][m] = '\0';
    }
    scanf("%d %d %d %d", &S.x, &S.y, &T.x, &T.y);
    S.step = 0;
    printf("%d", BFS());
    return 0;
}