#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// give a array ans M, find all the element 
// that array[index1] + array[index2] = M
struct node {
	int a;
	int b;
};
vector<node> v;

int main() {
	int n, M;
	scanf("%d %d", &n, &M);
	int* array = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	node current;
	int i = 0;
	int j = n - 1;
	while(i < j) {
		if(array[i] + array[j] == M) {
			current.a = array[i];
			current.b = array[j];
			v.push_back(current);
			i++;
			j--;
		}
		else if(array[i] + array[j] < M) {
			i++;
		}
		else {
			j--;
		}
	}
	printf("%d\n", v.size());
	for(int i = 0; i < v.size(); i++) {
		printf("%d %d\n", v[i].a, v[i].b);
	}
	return 0;
}

// merge sequence
int merge(int* A, int* B, int* C, int sizeA, int sizeB) {
	int i = 0;
	int j = 0;
	int index = 0;
	while(i < sizeA && j < sizeB) {
		if(A[i] < B[j]) {
			C[index] = A[i];
			i++;
			index++;
		}
		else {
			C[index] = B[j];
			j++;
			index++;
		}
	}
	while(i < sizeA) {
		C[index] = A[i];
		i++;
		index++;
	}
	while(j < sizeB) {
		C[index] = B[j];
		j++;
		index++;
	}
	return index;
}

// merge sort

// 1.recursive

const int maxn = 100;

// merge[l1, r2] into a sorted array
void merge(int* a, int l1, int r1, int l2, int r2) {
	int i = l1;
	int j = l2;
	int temp[maxn];
	int index = 0;
	while(i <= r1 && j <= r2) {
		if(a[i] < a[j]) {
			temp[index] = a[i];
			i++;
			index++;
		}
		else {
			temp[index] = a[j];
			j++;
			index++;
		}
	}
	while(i <= r1) {
		temp[index] = a[i];
		i++;
		index++;
	}
	while(j <= r2) {
		temp[index] = a[j];
		j++;
		index++;
	}
	for(int i = 0; i < index; i++) {
		a[l1 + i] = temp[i];
	}
}

// mergeSort a[left, right]
void mergeSort(int* a, int left, int right) {
	if(left < right) {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid+1, right);
		merge(a, left, mid, mid+1, right);
	}
}

// 2.iterate

void mergeSort(int* a) {
	for(int step = 2; step / 2 <= n; step = step * 2) {
		for(int i = 1; i <= n; i += step) {
			int mid = i + step / 2 - 1;
			if(mid + 1 <= n) {
				merge(a, i, mid, mid+1, min(i + step - 1, n));
			}
		}
	}
}

void mergeSort(int* a) {
	for(int step = 2; step / 2 <= n; step = step * 2) {
		for(int i = 1; i <= n; i += step) {
			sort(a+i, a + min(i + step, n + 1));
		}
	}
}

// quick sort

int partition(int* a, int left, int right) {
	int temp = a[left];
	while(left < right) {
		while(left < right && a[right] > temp) {
			right--;
		}
		a[left] = a[right];
		while(left < right && a[left] <= temp) {
			left++;
		}
		a[right] = a[left];
	}
	a[left] = temp;
	return left;
}

void quickSort(int* a, int left, int right) {
	if(left < right) {
		int pos = partition(a, left, right);
		quickSort(a, left, pos - 1);
		quickSort(a, pos + 1, right);
	}
}

// better quickSort

int randPartition(int* a, int left, int right) {
	int p = (round(1.0 * rand() / RAND_MAX * (right - left) + left));
	swap(a[p], a[left]);
	int temp = a[left];
	while(left < right) {
		while(left < right && a[right] > temp) {
			right--;
		}
		a[left] = a[right];
		while(left < right && a[left] <= temp) {
			left++
		}
		a[right] = a[left];
	}
	a[left] = temp;
	return left;
}