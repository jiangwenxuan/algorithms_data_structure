int a;
long long b;
float c;
double d;
char e;
char f[10];
scanf("%d %lld %f %lf %c %s", &a, &b, &c, &d, &e, &f);
// 除了%c之外，scanf对其他格式符的输入是以空格、换行为结束
// %c可以读入换行

printf("%d %lld %f %f %e %s", a, b, c, d, e, f);
// 对于double类型的变量，读入时用%lf， 输出时用%f

// 三种特殊的输出格式
// 1: %md   不足m位的int变量右端以m位进行右对齐输出，高位用空格补齐
printf("%5d", a);

// 2: %0md 不足m位的int变量右端以m位进行右对齐输出，高位用0补齐
printf("%05d", a);

// 3: %.mf 让浮点数保留m位输出
printf("%01f", d);
printf("%02d", d);
printf("%03d", d);

// getchar以及putchar用来输入输出单个字符
// 空格、换行都可以吸收
#include <stdio.h>
int main() {
    char str[5][5];
    int n; // n <= 5
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            str[i][j] = getchar();
        }
        getchar(); // 为了吸收换行符
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            putchar(str[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

// gets以及puts用来输入输出一行字符串
// gets识别\n；puts输出一行字符串，并紧跟一个\n
#include <stdio.h>
int main() {
    char str1[20];
    char str2[5][10];
    gets(str1);
    for(int i = 0; i < 3; i++) {
        gets(str2[i]);
    }
    puts(str1);
    for(int i = ; i < 3; i++) {
        puts(str2[i]);
    }
    return 0;
}

// string.h里有一些用于字符数组的函数

// 1: strlen()，得到数组长度
// 如果是c++，应该是: #include <cstring>
#include <stdio.h>
#include <string.h>
int main() {
    char str[20];
    gets(str);
    printf("%d", strlen(str));
    return 0;
}

// 2: strcmp()，以字典序比较两个字符串
// 如果str1 < str2, 返回负整数
// 如果str1 == str2，返回0
// 如果str1 > str2，返回正整数
#include <stdio.h>
#include <string.h>
int main() {
    char str1[10], str2[10];
    gets(str1);
    gets(str2);
    int cmp = strcmp(str1, str2);
    if(cmp < 0) {
        printf("str1 < str2");
    }
    else if(cmp == 0) {
        printf("str1 == str2");
    }
    else {
        printf("str1 > str2");
    }
    return 0;
}

// hash：
// 假设字符串都由小写a~z构成，可以把a~z视为0~25，即26进制
#include <stdio.h>
#include <string.h>

int hashNum(char str[]) {
    int len = strlen(str);
    int ans = 0;
    for(int i = 0; i < len; i++) {
        ans = ans * 26 + (str[i] - 'a');
    }
    return ans;
}

int main() {
    char str[20];
    gets(str);
    int n = hashNum(str);
    printf("%d", n);
    return 0;
}

// string是stl里的一种，在c++中使用时需要：
#include <string>
#include <iostream>
using namespace std;

//初始化
string str1;
//赋值
string str2 = 'abcdefg';
//以下标访问
int main() {
    string str3 ;
    for(int i = 0; i < str3.length(); i++) {
        printf("%c", str3[i]);
    }
    return 0;
}
// pay attention! 读入或输出整个字符串只能用cin, cout
int exercise1() {
    string str;
    cin >> str;
    cout << str;
    return 0;
}
// 使用迭代器访问string, 注意：最好不要在迭代过程中对string进行修改、增减，
// 最好是访问，不然需要大量时间，因为string删除不是O(1)
int exercise2() {
    string str = "abcdefg";
    for(string::iterator it = str.begin(); it != str.end(); it++) {
        printf("%c", *it);
    }
    return 0;
}
// 查找操作：find()
// string str;
// str.find(str1);
// 如果str1是str子串，返回在str中第一次出现位置；不然返回string::npos
// str.find(str1, pos), 从str第pos位开始匹配str1
int exercise3() {
    string str1 = "hello world!";
    string str2 = "I like apple";
    string str3 = "hello";
    if(str1.find(str3) != string::npos) {
        cout << str1.find(str3) << endl;
    }
    if(str2.find(str3) != string::npos) {
        cout << str2.find(str3) << endl;
    }
    return 0;    
}