#include <stdio.h>

int input(int *array, int n)
{
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    return 0;
}

int printArray(int *array, int n)
{
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    return 0;
}

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int maxHeap(int *array, int unsortedSize, int consideredIndex)
{
    if (consideredIndex >= 0){
        if (consideredIndex*2 + 2 <= unsortedSize - 1){ // Exclude the sorted or inexistant indexes
            if (array[consideredIndex*2 + 2] > array[consideredIndex]){
                swap(&array[consideredIndex], 
                &array[consideredIndex*2 + 2]);
            }
        }
        if (array[consideredIndex*2 + 1] > array[consideredIndex]){
            swap(&array[consideredIndex], 
            &array[consideredIndex*2 + 1]);
        }
        maxHeap(array, unsortedSize, consideredIndex - 1);
    }
}

void heapSort(int *array, int n)
{
    int unsortedSize = n;
    while (unsortedSize > 1){
        maxHeap(array, unsortedSize, (unsortedSize)/2 - 1);
        swap(&array[0], &array[unsortedSize - 1]);
        unsortedSize--;
    }
}

int main()
{
    int n;
    //printf("The number of numbers in the unsorted array: ");
    scanf("%d", &n);
    int array[n];
    //printf("Input unsorted array respectively: ");
    input(array, n);
    heapSort(array, n);
    printArray(array, n);
    return 0;
}