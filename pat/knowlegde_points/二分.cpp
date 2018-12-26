#include <cstdio>
#include <algorithm>
using namespace std;

// // a[] is an array(it is better an increasing array)
// int binarySearch(int* a, int left, int right, int x) {
// 	int mid;
// 	while(left <= right) {
// 		mid = (left + right) / 2;
// // if a[right] is too large		
// //      mid = left + (right - left) / 2;		
// 		if(a[mid] == x) {
// 			return mid;
// 		}
// 		else if(a[mid] < x) {
// 			left = mid + 1;
// 		}
// 		else {
// 			right = mid - 1;
// 		}
// 	}
// 	return -1;
// }

// bool cmp(int a, int b) {
// 	return a < b;
// }

// int main() {
// 	int n;
// 	scanf("%d", &n);
// 	int a[n];
// 	for(int i = 0; i < n; i++) {
// 		scanf("%d", &a[i]);
// 	}
// 	sort(a, a + n, cmp);
// 	int x;
// 	scanf("%d", &x);
// 	int m = binarySearch(a, 0, n-1, x);
// 	printf("%d", m);
// 	return 0;
// }

// we want to know the first index that a[index] >= x
int lower_bound(int* a, int left, int right, int x) {
    int mid;
    while(left < right) {
        mid = (left + right) / 2;
        if(a[mid] >= x) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

bool cmp(int a, int b) {
    return a < b;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n, cmp);
    int x;
    scanf("%d", &x);
    int m = lower_bound(a, 0, n-1, x);
    printf("%d", m);
    return 0;
}

// we want to know the first index that a[index] > x
int upper_bound(int* a, int left, int right, int x) {
    int mid;
    whlie(left < right) {
        mid = (left + right) / 2;
        if(a[mid] > x) {
            right = x;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

// sqrt(2)
const double eps = 1e-5;

double f(double x) {
    return x * x;
}

double calSqrt() {
    double left = 1;
    double right = 2;
    double mid;
    while(right - left > eps) {
        mid = (right + left) / 2;
        if(f(mid) > 2) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    return mid;
}

