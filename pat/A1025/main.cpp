#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct node {
    char registrationNum[15];
    int score;
    int locationNum;
    int localRank;
    int rank;
};
node record[30010];

bool cmp1(node a, node b) {
    return a.score > b.score;
}

bool cmp2(node a, node b) {
    if(a.score == b.score) {
        return strcmp(a.registrationNum, b.registrationNum) < 0;
    }
    else {
        return a.score > b.score;
    }
}

int main() {
    int n;
    int num;
    scanf("%d", &n);
    node current;
    int flag1 = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &num);
        for(int j = 0; j < num; j++) {
            scanf("%s %d", current.registrationNum, &current.score);
            current.locationNum = i;
            record[flag1+j] = current;
        }
        sort(record + flag1, record + flag1 + num, cmp1);
        record[flag1].localRank = 1;
        for(int k = 1; k < num; k++) {
            if(record[k+flag1].score != record[k+flag1-1].score) {
                record[k+flag1].localRank = k+1;
            }
            else {
                record[k+flag1].localRank = record[k+flag1-1].localRank;
            }
        }
        flag1 = flag1 + num;
    }
    sort(record, record+flag1, cmp2);
    record[0].rank = 1;
    for(int i = 1; i < flag1; i++) {
        if(record[i].score == record[i-1].score) {
            record[i].rank = record[i-1].rank;
        }
        else {
            record[i].rank = i + 1;
        }
    }
    printf("%d\n", flag1);
    for(int i = 0; i < flag1; i++) {
        printf("%s %d %d %d\n", record[i].registrationNum, record[i].rank, record[i].locationNum, record[i].localRank);
    }
    return 0;
}
