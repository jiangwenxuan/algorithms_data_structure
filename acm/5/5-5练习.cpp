#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string line;
	while (getline(cin, line)) {
		int sum = 0;
		int x;
		stringstream ss(line);
		while (ss >> x) {
			sum = sum + x;
		}
		cout << sum << "\n";
	}
	return 0;
}