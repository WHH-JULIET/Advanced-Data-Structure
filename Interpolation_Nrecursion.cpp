#include <stdio.h>

int interpolationSearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);
        if (arr[pos] == key) return pos;
        else if (arr[pos] > key) high = pos - 1;
        else low = pos + 1;
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

    int result = interpolationSearchIterative(arr, n, key);
    if (result != -1) printf("Element found at index %d\n", result);
    else printf("Element not found\n");
    return 0;
}

