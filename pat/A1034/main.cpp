#include <iostream>
#include <map>
using namespace std;

map<string, int> strToInt;
map<int, string> intToStr;
map<string, int> ans;

int idNum = 1;
int k;
int myHash(string s) {
    if(strToInt[s] == 0) {
        strToInt[s] = idNum;
        intToStr[idNum] = s;
        return idNum++;
    }
    else {
        return strToInt[s];
    }
}

int adj[1010][1010];
int weight[1010];
bool visit[2010];

void dfs(int u, int& head, int& numPeo, int& totalWeight) {
    visit[u] = true;
    numPeo++;
    if(weight[head] < weight[u]) {
        head = u;
    }
    for(int i = 1; i < idNum; i++) {
        if (adj[u][v] > 0) {
            totalWeight += adj[u][v];
            adj[u][v] = adj[v][u] = 0;
            if (visit[v] == false)
                dfs(v, head, numPeo, totalWeight);
        }
    }
}

void dfsTra() {
    for(int i = 1; i < idNum; i++) {
        if(visit[i] == false) {
            int head = i;
            int numPeo = 0;
            int totalWeight = 0;
            dfs(i, head, numPeo, totalWeight);
            if(numPeo > 2 && totalWeight > k) {
                ans[intToStr[head]] = numPeo;
            }
        }
    }
}

int main() {
    int n;
    int w;
    cin >> n >> k;
    string s1, s2;
    for(int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> w;
        int id1 = myHash(s1);
        int id2 = myHash(s2);
        weight[id1] += w;
        weight[id2] += w;
        adj[id1][id2] += w;
        adj[id2][id1] += w;
    }
    dfsTra();
    cout << ans.size() << endl;
    for(map<string, int>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
