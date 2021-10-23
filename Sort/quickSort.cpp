//----------------------------------------------------------------------------------
// [ QuickSort ]
//
// 시간복잡도: O(nlog₂n) ~ O(n²)
// 공간복잡도: O(n)
// Unstable Sort
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void logic(int* arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[left], l = left, r = right;

    while (l < r) {
        while (pivot < arr[r]) --r;
        while (l < r && pivot >= arr[l]) ++l;
        swap(arr[l], arr[r]);
    }
    arr[left] = arr[l];
    arr[l] = pivot;

    logic(arr, left, l - 1);
    logic(arr, l + 1, right);
}

int main() {
    int arr[] = {9, 6, 2, 4, 1, 5, 2, 6, 7, 3};
    int n = 10;

    logic(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}