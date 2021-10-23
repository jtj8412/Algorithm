//----------------------------------------------------------------------------------
// [ SelectionSort ]
//
// 시간복잡도: O(n²) ~ O(n²)
// 공간복잡도: O(n)
// Unstable Sort
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {9, 6, 2, 4, 1, 5, 2, 6, 7, 3};
    int n = 10;
    int min;

    for (int i = 0; i < n - 1; ++i) {
        min = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[min] > arr[j]) min = j;
        }
        swap(arr[min], arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}