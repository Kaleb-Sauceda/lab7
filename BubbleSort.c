#include <stdbool.h>
#include <stdio.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n, int swaps[])
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
                swaps[i]++;
            }
        }

        if (swapped == false)
            break;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = { 97, 16, 45, 63, 13, 22, 7 , 58, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    int swaps[n];
    for (int i = 0; i < n; i++) {
        swaps[i] = 0;
    }
    bubbleSort(arr, n, swaps);
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("\nNumber of swaps for each index: \n");
    printArray(swaps, n);
    return 0;
}