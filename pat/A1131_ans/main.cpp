#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int st, ed;                     //分别为起点和终点
bool vis[10010];
int G[10010][10010];            //记录相邻两车站的线路
struct Station {
    int id;
    vector<int> next;           //存储相邻的车站
}sta[10010];
 
vector<int> temp, path;         //temp,path分别记录当前路径与最佳路径
int optvalue, optlen;           //optvalue, optlen分别为最少车站数与最短路径长
void DFS(int st) {      //DFS遍历
    vis[st] = true;     //将当前节点标记为被访问
    if(st == ed) {      //当前节点是终点时
        temp.push_back(st);
        int transfer = 1;           //记录换乘车站数量
        for(int i = 0; i < temp.size() - 2; i++) {
            int a = temp[i], b = temp[i+1], c = temp[i+2];
            if(G[b][c] != G[a][b]) transfer++;
        }
        if(temp.size() < optlen) {      //如果该条路径长度小于之前最短路径，更新最短路径长度，最短路径所需换乘车站数量
            optlen = temp.size();
            path = temp;
            optvalue = transfer;
        } else if(temp.size() == optlen){   //如果该条路径长度等于之前最短路径
            if(transfer < optvalue) {       //如果所需的换乘车站数小于之前最短路径所需换乘车站数，更新最少换乘车站数
                path = temp;
                optvalue = transfer;
            }
        }
        vis[st] = false;
        temp.pop_back();
        return;
    }
    temp.push_back(st);
    if(temp.size() < optlen){               //DFS剪枝，如果当前路径的长度小于之前最短路径长，继续DFS遍历
        for(int i = 0; i < sta[st].next.size(); i++) {
            if(vis[sta[st].next[i]] == false) {
                DFS(sta[st].next[i]);
            }
        }
    }
    vis[st] = false;
    temp.pop_back();
}
 
int main(int argc, const char * argv[]) {
    int n, m, k;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d %d", &m, &a);
        for(int j = 1; j < m; j++) {
            scanf("%d", &b);
            sta[a].next.push_back(b);
            sta[b].next.push_back(a);
            G[a][b] = G[b][a] = i;
            a = b;
        }
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        temp.clear();
        optvalue = optlen = 1000000;
        scanf("%d %d", &st, &ed);
        fill(vis, vis + 10010, false);
        DFS(st);
        printf("%d\n", optlen - 1);     //输出最短路径长度
        vector<int> tran, line;         //tran记录起点，每个换乘的节点，终点； line记录所需乘坐的路线号
        line.push_back(G[path[0]][path[1]]);
        tran.push_back(st);
        for(int j = 0; j < path.size() - 2; j++) {
            int a = path[j], b = path[j+1], c = path[j+2];
            if(G[a][b] != G[b][c]) {
                tran.push_back(b);
                line.push_back(G[b][c]);
            }
        }
        tran.push_back(ed);
        for(int j = 0; j < optvalue; j++) {
            printf("Take Line#%d from %04d to %04d.\n", line[j], tran[j], tran[j+1]);
        }
    }
    return 0;
}