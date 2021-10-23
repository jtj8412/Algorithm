//----------------------------------------------------------------------------------
// [ RadixSort ]
//
// 시간복잡도: O(n)
// StableSort
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void logic(int* arr, int n) {
    int max_val = *max_element(arr, arr + n), count[10];

    for (int i = 1, idx = 0; max_val / i != 0; i *= 10) {
        memset(count, 0, sizeof(int) * 10);

        for (int j = 0; j < n; ++j) {
            ++count[(arr[j] / i) % 10];
        }

        for (int j = 0; j < 10; ++j) {
            while (count[j]--) arr[idx++] = j;
        }
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