//----------------------------------------------------------------------------------
// [ MergeSort ]
//
// 시간복잡도: O(nlog₂n)
// 공간복잡도: O(n)
// Stable Sort
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void logic(int* arr, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) >> 1;

    logic(arr, left, mid);
    logic(arr, mid + 1, right);

    int l = 0, r = mid - left + 1, i = left, ll = r, rr = right - left + 1;
    int* tmp = new int[right - left + 1];

    copy(arr + left, arr + right + 1, tmp);
    
    while (l < ll && r < rr) {
        if (tmp[l] < tmp[r]) arr[i++] = tmp[l++];
        else arr[i++] = tmp[r++];
    }

    while (l < ll) arr[i++] = tmp[l++];
    while (r < rr) arr[i++] = tmp[r++];

    delete[] tmp;
}

int main() {
    int arr[] = {9, 6, 2, 4, 1, 5, 2, 6, 7, 3};
    int n = 10;

    logic(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}