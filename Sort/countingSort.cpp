//----------------------------------------------------------------------------------
// [ CountingSort ]
//
// 시간복잡도: O(n + k) (k는 counting을 위한 배열 크기)
// 공간복잡도: O(k)
// Stable Sort
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {9, 6, 2, 4, 1, 5, 2, 6, 7, 3},
        count[10] = {}, n = 10, k = 10, idx = 0;

    for (int i = 0; i < n; ++i) {
        ++count[arr[i]];
    }

    for (int i = 0; i < k; ++i) {
        while (count[i]--) arr[idx++] = i;
    }
    
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}