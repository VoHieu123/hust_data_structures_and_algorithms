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

void insertionSort(int *array, int firstIndex, int lastIndex)
{
    for (int i = firstIndex + 1; i <= lastIndex; i++){
        int key = array[i];
        int j = i - 1;
        while (j >= firstIndex && key < array[j]){
            array[j + 1] = array[j];
            j--; 
        }
        array[j + 1] = key;
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
    insertionSort(array, 0, n - 1);
    printArray(array, n);
    return 0;
}