#include <stdio.h>

int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearchIterative(arr, n, key);
    if (result != -1) printf("Element found at index %d\n", result);
    else printf("Element not found\n");
    return 0;
}

