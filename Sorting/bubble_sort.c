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

void bubbleSort(int *array, int n)
{
    for (int i = 0; i < n; i++){
        int lastUnsortedIndex = n;
        for (int j = 0; j < lastUnsortedIndex; j++){
            if (array[j] > array[j+1]){
                swap(&array[j], &array[j + 1]);
            }
        }
        lastUnsortedIndex--;
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
    bubbleSort(array, n);
    printArray(array, n);
    return 0;
}