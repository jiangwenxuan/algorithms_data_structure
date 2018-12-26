#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int gender[maxn];   //1为女性，2为男性
int G[maxn][maxn];      //标记两人是否为朋友，是为1，否为0
vector<int> v[maxn];
 
struct node{
    int first, second;      //记录输出的两个朋友
};
 
bool cmp(node a, node b) {      //将输出的朋友对排序
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}
 
int main(int argc, const char * argv[]) {
    int n, m, k;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        char s1[6], s2[6];  //通过字符串输入排除-0000的情况
        int a = 0, b = 0, flag1, flag2;
        scanf("%s %s", s1, s2);
        if(s1[0] == '-') flag1 = 1;     //如果有负号则为女性1
        else flag1 = 2;
        if(s2[0] == '-') flag2 = 1;
        else flag2 = 2;
        for(int i = 0; i < strlen(s1); i++) {   //a， b 都转化为自然数
            if(s1[i] != '-') {
                a = a * 10 + s1[i] - '0';
            }
        }
        for(int i = 0; i < strlen(s2); i++) {
            if(s2[i] != '-') {
                b = b * 10 + s2[i] - '0';
            }
        }
        gender[a] = flag1;      //标记a， b 的性别
        gender[b] = flag2;
        G[a][b] = G[b][a] = 1;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int a, b, gen_1, gen_2;
        scanf("%d %d", &a, &b);
        if(a < 0) {     //将a，b转化为自然数
            a *= -1;
        }
        if(b < 0) {
            b *= -1;
        }
        gen_1 = gender[a];
        gen_2 = gender[b];
        vector<node> v1;    //保存满足条件的朋友对
        for(int j = 0; j < v[a].size(); j++) {
            if(gender[v[a][j]] == gen_1 && v[a][j] != b) {      //寻找a的同性朋友且这个朋友不为b
                for(int s = 0; s < v[b].size(); s++) {
                    if(gender[v[b][s]] == gen_2 && G[v[b][s]][v[a][j]] == 1 && v[b][s] != a) {   //寻找b的同性朋友v[b][s]且该朋友与a的朋友v[a][j]互为朋友，且b的同性朋友不为a
                        node no;
                        no.first = v[a][j];
                        no.second = v[b][s];
                        v1.push_back(no);       //将满足条件的朋友对加入v1中
                    }
                }
            }
        }
        sort(v1.begin(), v1.end(), cmp);    //将待输出朋友对排序
        if(v1.size() == 0) printf("0\n");
        else {
            printf("%d\n", v1.size());
            for(int j = 0; j < v1.size(); j++) {
                printf("%04d %04d\n", v1[j].first, v1[j].second); //注意输出为四位数
            }
        }
    }
    return 0;
}
