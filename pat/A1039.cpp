#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> stu[26*26*26*10 + 1];

int hashId(char* str) {
    int hashNum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        hashNum = (str[i] - 'A') + hashNum * 26;
    }
    hashNum = hashNum * 10 + (str[3] - '0');
    return hashNum;
}

int main() {
    int N, K;
    int i, j, k;
    char str[5];
    int stuID;
    int courseNum, stuNum, count;
    scanf("%d%d", &N, &K);
    for (i = 0; i < K; i++) {
        scanf("%d%d", &courseNum, &stuNum);
        for (j = 0; j < stuNum; j++) {
            scanf("%s", str);
            stuID = hashId(str);
            stu[stuID].push_back(courseNum);
        }
    }
    for (i = 0; i < N - 1; i++) {
        scanf("%s", str);
        stuID = hashId(str);
        count = stu[stuID].size();
        sort(stu[stuID].begin(), stu[stuID].begin() + count);
        printf("%s %d", str, count);
        if (count != 0) {
            for (j = 0; j < count; j++) {
                printf(" %d", stu[stuID][j]);
            }
        }
        printf("\n");
    }
    scanf("%s", str);
    stuID = hashId(str);
    count = stu[stuID].size();
    sort(stu[stuID].begin(), stu[stuID].begin() + count);
    printf("%s %d", str, count);
    if (count != 0) {
        for (j = 0; j < count; j++) {
            printf(" %d", stu[stuID][j]);
        }
    }
    return 0;
}
