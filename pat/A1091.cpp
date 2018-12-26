#include <iostream>
#include <queue>
using namespace std;

int matrix[60][1286][128];
int M, N, L, T;
struct node {
    int x, y, z;
} a;
int X[6] = {0, 0, 1, -1, 0, 0}; 
int Y[6] = {1, -1, 0, 0, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

bool judge(int x, int y, int z) {
    if(x >= M || x < 0 || y >= N || y < 0 || z >= L || z < 0) {
        return false;
    }
    if(matrix[z][x][y] != 1) {
        return false;
    }
    return true;
}

int BFS(int x, int y, int z) {
    int bobo = 0;
    queue<node> q;
    a.x = x;
    a.y = y;
    a.z = z;
    q.push(a);
    while(!q.empty()) {
        node top = q.front();
        bobo++;
        q.pop();
        for(int i = 0; i < 6; i++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];
            if (judge(newX, newY, newZ)) {
                a.x = newX;
                a.y = newY;
                a.z = newZ;
                q.push(a);
                matrix[newZ][newX][newY] = 2;
            }
        }
    }
    return bobo;
}

int main() {
	int total = 0;
    scanf("%d %d %d %d", &M, &N, &L, &T);
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < N; k++) {
                scanf("%d", &matrix[i][j][k]);
            }
        }
    }
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < N; k++) {
                if(matrix[i][j][k] == 1) {
                    matrix[i][j][k] = 2;
                    int current = BFS(j, k, i);
                    if(current >= T) {
                        total = total + current;
                    }
                }
            }
        }
    }
    printf("%d", total);
    return 0;
}
