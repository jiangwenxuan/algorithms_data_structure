#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, z;
};
int m, n, l, t;
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};
int arr[1300][130][80];
bool visit[1300][130][80];

bool judge(int x, int y, int z) {
    if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) {
        return false;
    }
    if(arr[x][y][z] == 0 || visit[x][y][z] == true) {
        return false;
    }
    return true;
}

int bfs(int x, int y, int z) {
    int cnt = 0;
    node temp;
    temp.x = x;
    temp.y = y;
    temp.z = z;
    queue<node> q;
    q.push(temp);
    visit[x][y][z] = true;
    while(!q.empty()) {
        node top = q.front();
        q.pop();
        cnt++;
        for(int i = 0; i < 6; i++) {
            int nx = top.x + X[i];
            int ny = top.y + Y[i];
            int nz = top.z + Z[i];
            if(judge(nx, ny, nz)) {
                visit[nx][ny][nz] = true;
                temp.x = tx;
                temp.y = ty;
                temp.z = tz;
                q.push(temp);
            }
        }
    }
    if(cnt >= t) {
        return cnt;
    }
    else {
        return 0;
    }
}

int main() {
    scanf("%d %d %d", &m, &n, &l, &t);
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                scanf("%d", &arr[j][k][i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < l; i++) {
        for(int k = 0; k < m; k++) {
            for(int j = 0; j < n; j++) {
                if(arr[k][j][i] == 1 && visit[k][j][i] == false) {
                    ans += bfs(k, j, i);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}