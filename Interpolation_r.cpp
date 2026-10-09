#include <stdio.h>

int interpolationSearchRecursive(int arr[], int low, int high, int key) {
    if (low > high || key < arr[low] || key > arr[high]) return -1;
    int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);
    if (arr[pos] == key) return pos;
    else if (arr[pos] > key) return interpolationSearchRecursive(arr, low, pos - 1, key);
    else return interpolationSearchRecursive(arr, pos + 1, high, key);
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

    int result = interpolationSearchRecursive(arr, 0, n - 1, key);
    if (result != -1) printf("Element found at index %d\n", result);
    else printf("Element not found\n");
    return 0;
}

