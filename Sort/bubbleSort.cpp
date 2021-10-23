//----------------------------------------------------------------------------------
// [ BubbleSort ]
//
// 시간복잡도: O(n²)
// 공간복잡도: O(n)
// Stable Sort
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {9, 6, 2, 4, 1, 5, 2, 6, 7, 3};
    int n = 10;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 1; j < n - i; ++j) {
            if (arr[j - 1] <= arr[j]) continue;
            swap(arr[j - 1], arr[j]);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}