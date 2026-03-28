#include <stdio.h>
#include <stdlib.h>

int merge_sort(int arr[], size_t size) {
    int *buffer = (int *)malloc(size * sizeof(int));
    if (buffer == NULL) {
        return -1; // Memory allocation failed
    }
    if (size < 2) { 
        return 0; // Base case: arrays of size 0 or 1 are already sorted
    }
    merge_recursive(arr, size, buffer);
}

int merge_recursive(int arr[], size_t size, int buffer[]) {
    if (size <= 1) {
        return 0; // Base case: arrays of size 0 or 1 are already sorted
    }
    size_t mid = size / 2;
    merge_recursive(arr, mid, buffer); // Sort the left half
    merge_recursive(arr + mid, size - mid, buffer); // Sort the right half
    merge(arr, mid, size - mid, buffer); // Merge the sorted halves
}

int merge(int arr[], size_t left_size, size_t right_size, int buffer[]) {
    size_t i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        if (arr[i] <= arr[left_size + j]) {
            buffer[i + j] = arr[i];
            i++;
        } else {
            buffer[i + j] = arr[left_size + j];
            j++;
        }
    }

    while (i < left_size) {
        buffer[i + j] = arr[i];
        i++;
    }
    while (j < right_size) {
        buffer[i + j] = arr[left_size + j];
        j++;
    }

    for (k = 0; k < left_size + right_size; k++) {
        arr[k] = buffer[k];
    }
    return 0; // Merge successful

}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    merge_sort(arr, size);

    printf("Sorted array:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}