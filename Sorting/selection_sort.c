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

void selectionSort(int *array, int n)
{
    for (int currentFirstIndex = 0; currentFirstIndex < n; currentFirstIndex++){
        //Let the first index of unsorted array = minimum value
        int currentMin = array[currentFirstIndex];
        int indexOfMinValue = currentFirstIndex;
        //Find minimum value of unsorted array by comparing it with the minimum
        for (int j = currentFirstIndex + 1; j < n; j++){
            if (array[j] < currentMin) {
                currentMin = array[j];
                indexOfMinValue = j;
            }
        }
        //Swap to create sorted array from the first index to currentFirstIndex index
        swap(&array[indexOfMinValue], &array[currentFirstIndex]);
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
    selectionSort(array, n);
    printArray(array, n);
    return 0;
}