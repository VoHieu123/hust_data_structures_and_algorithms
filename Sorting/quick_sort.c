#include <stdio.h>

int input(int *array, int n)
{
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    return 0;
}

int printArray(int *array, int first, int last)
{
    for (int i = first; i <= last; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int quickSort(int *array, int firstIndex, int lastIndex)
{
    if (lastIndex >= firstIndex){
        if (lastIndex == firstIndex) return;
        if (lastIndex - firstIndex == 1){
            if (array[firstIndex] > array[lastIndex]) 
                swap(&array[firstIndex], &array[lastIndex]);
        }else{
            int pivot = (lastIndex + firstIndex)/2;
            int key = array[pivot];
            int numberOfSmallerValue = 0;
            for (int i = firstIndex; i <= lastIndex; i++){
                if (array[i] < array[pivot]){
                    numberOfSmallerValue++;
                }
            }
            int correctPositionOfPivotValue = firstIndex + numberOfSmallerValue;
            if (pivot != correctPositionOfPivotValue) 
                swap(&array[pivot], &array[correctPositionOfPivotValue]);

            int i = firstIndex, j = correctPositionOfPivotValue + 1;
            while (i < correctPositionOfPivotValue && j <= lastIndex){
                if (array[i] >= key){
                    swap(&array[i], &array[j]);
                    j++;
                }else{
                    i++;
                }
            }
            quickSort(array, correctPositionOfPivotValue + 1, lastIndex);
            quickSort(array, firstIndex, correctPositionOfPivotValue - 1);
        }
    }
    return 0;
}

int main()
{
    int n;
    //printf("The number of numbers in the unsorted array: ");
    scanf("%d", &n);
    int array[n];
    //printf("Input unsorted array respectively: ");
    input(array, n);
    quickSort(array, 0, n - 1);
    printArray(array, 0, n - 1);
    return 0;
}