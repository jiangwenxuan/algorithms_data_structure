#include <cstdio>
#include <algorithm>
using namespace std;

// the down flag of the first element (in the heap) is 1, not 0

const int maxn = 100;
int heap[maxn], n = 10;

void downAdjust(int low, int high) {
    int i = low;
    int j = i * 2;
    while(j <= high) {
        if(j+1 <= high && heap[j+1] > heap[j]) {
            j = j+1;
        }
        if(heap[i] < heap[j]) {
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        }
        else {
            break;
        }
    }
}

void createHeap() {
    for(int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);
    }
}

void deleteTop() {
    heap[1] = heap[n];
    n--;
    downAdjust(1, n);
}

void upAdjust(int low, int high) {
    int i = high;
    int j = i / 2;
    while(j >= low) {
        if(heap[i] > heap[j]) {
            swap(heap[i], heap[j]);
            i = j;
            j = i / 2;
        }
        else {
            break;
        }
    }
}

void insert(int x) {
    n++;
    heap[n] = x;
    upAdjust(1, n);
}

void heapSort() {
    createHeap();
    for(int i = n; i > 1; i--) {
        swap(heap[i], heap[1]);
        downAdjust(1, i-1);
    }
}