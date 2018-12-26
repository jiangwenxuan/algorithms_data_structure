#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "abcd";
    for (int i = 0; i < str.length(); i++) {
        printf("%s", str[i]);
    }
    for (string::iterator it = str.begin(); it != str.end(); it++) {
        printf("%c", *it);
    }
    
}