// set翻译为集合，内部自动有序且不含重复元素。
// 1.定义

set<typename> se;
set<set<int> > se;

// 2.访问

set<typename>::iterator it;

// 3.常用函数
s.insert(); //插入

s.find(); //查找

s.size(); //元素个数

s.clear(); //清空

s.erase(); //删除

// 4.例子

#include <cstdio>
#include <set>
using namespace std;

int main() {
	set<int> s;
	int m;
	// insert
	for(int i = 0; i < 10; i++) {
		scanf("%d", &m);
		s.insert(m);
	}
	// visit
	for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
		printf("%d\n", *it);
	}
    // find
    int num;
    scanf("%d", &num);
    set<int>::iterator it = s.find(num);
    printf("%d\n", *it);
    // erase
    // first: set<int>::iterator it = s.find(num); s.erase(it);
    // second: s.erase(num);
    // third: set<int>::iterator it = s.find(num); s.erase(it, s.end());
    return 0; 
}


// string对字符串的功能进行了封装，便于操作

// define
string str;
string s = "asdf";

// visit

string s = "asdf";
for(int i = 0; i < s.length(); i++) {
	printf("%c\n", s[i]);
}

cin >> str;
cout << str;

printf("%s\n", str.c_str());

string::iterator it;
for(it = str.begin(); it != str.end(); it++) {
	printf("%c", *it);
}

// +=
string s1;
string s2;
string s3;
cin >> s1 >> s2;
s3 = s1 + s2;
cout << s3;

// ==  !=  <  >  <=  >= 
if(s1 < s2) {
	printf("hello");
}
else {
	printf("world");
}

// length()/size()
printf("%d", s1.length());

// insert()
string str1 = "abcdefghihklmn";
string str2 = "hello world";

str1.insert(3, str2);
	// or
str1.insert(str1.begin() + 3, str2.begin(), str2.end());

// erase
string str = "asdfghjkl";
str.erase(str.begin() + 3);
	//  or
str.erase(str.begin(), str.end() - 2); // erase(first, last) means erase [first, last)
	// or
str.erase(2, 4); // erase(pos, length);

// clear
str.clear();

// substr
string str = "hello world";
str.substr(3, 5); // substr(pos, length);

// replace
str.replace(pos, length, str2);
str.replace(itBegin, itEnd, str2);

// find
// example:

string s1;
string s2;
string s3;
cin >> s1;
cin >> s2;
cin >> s3;
if(s1.find(s2) != string::npos) {
	cout << s1.find(s2) << endl;
}
if(s1.find(s2, 4) != string::npos) {
	cout << s1.find(s2, 4) << endl;
}

// string::npos 
// if s2 is not a substr of s1, string::npos == s1.find(s2)
// string::npos == -1 or == 4294967295


// map翻译为映射

// define
map<typename1, typename2> m;
map<string, int> m;
map<char, int> mp;
mp['c'] = 10;
printf("%d\n", mp['c']);

// visit
mp['e'] = 20;
mp['a'] = 90;
for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
	printf("%c %d\n", it->first, it->second);
}

// find
map<char, int>::iterator it = mp.find('b');
if(it == mp.end()) {
	printf("wow, fail\n");
}
else {
	printf("%c %d", it->first, it->second);
}

// erase
mp.erase(it);
mp.erase('c');
mp.erase(first, last); // mp.erase(it, mp.end())

// size

// clear