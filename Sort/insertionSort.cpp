//----------------------------------------------------------------------------------
// [ InsertionSort ]
//
// 시간복잡도: O(n) ~ O(n²)
// 공간복잡도: O(n)
// Stable Sort
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {9, 6, 2, 4, 1, 5, 2, 6, 7, 3};
    int n = 10;

    for (int i = 1; i < n; ++i) {
        int tmp = arr[i];
        int idx = i - 1;
        while (idx >= 0 && tmp < arr[idx]) {
            arr[idx + 1] = arr[idx];
            idx--;
        }
        arr[idx + 1] = tmp;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}