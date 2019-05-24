#include <vector>
using namespace std;

struct bigInteger {
	static const int base = 100000000;
	static const int width = 8;

	vector<int> s;
	bigInteger(long long num = 0) {
		*this = num;
	}
	bigInteger operator = (long long num) {
		s.clear();
		do {
			s.push_back(num % base);
			num = num / base;
		} while (num > 0);
	}
};
