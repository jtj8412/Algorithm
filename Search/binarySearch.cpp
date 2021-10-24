//----------------------------------------------------------------------------------
// [ BinarySearch ]
//
// 시간복잡도: O(log₂n) 
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int logic(int* arr, int n, int val) {
    int l = 0, r = n - 1, mid;

    while (l <= r) {
        mid = (l + r) >> 1;

        if (arr[mid] == val) return mid;

        if (arr[mid] > val) r = mid - 1;
        else l = mid + 1;
    }

    return -1;
}

int main() {
    int arr[] = {2, 53, 602, 9094, 15335, 21124, 353561, 4935136, 10213517, 682073073};
    int n = 10;

    printf("%d\n", logic(arr, n, 353561));
}