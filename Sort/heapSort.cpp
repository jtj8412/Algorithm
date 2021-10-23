//----------------------------------------------------------------------------------
// [ HeapSort ]
//
// 시간복잡도: O(nlog₂n)
// 공간복잡도: O(n)
// Unstable Sort
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void heapify(int* arr, int n, int parent) {
    int p = parent, l = p * 2 + 1, r = p * 2 + 2;

    if (l < n && arr[p] < arr[l]) p = l;
    if (r < n && arr[p] < arr[r]) p = r;

    if (parent != p) {
        swap(arr[p], arr[parent]);
        heapify(arr, n, p);
    }
}

void logic(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {9, 6, 2, 4, 1, 5, 2, 6, 7, 3};
    int n = 10;

    logic(arr, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}