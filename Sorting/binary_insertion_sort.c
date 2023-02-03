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
    printf("\n");
    return 0;
}

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int binarySearch(int *array, int firstIndex, int lastIndex, int key)
{
    if (key <= array[firstIndex])
        return firstIndex;
    if (key >= array[lastIndex])
        return lastIndex + 1;
    int mid = (firstIndex + lastIndex)/2;
    int lIndexOfIdenSeq = mid;
    int rIndexOfIdenSeq = mid;
    while(array[rIndexOfIdenSeq] == array[rIndexOfIdenSeq + 1] 
    && rIndexOfIdenSeq <= lastIndex - 1){
        rIndexOfIdenSeq++;
    }
    while(array[lIndexOfIdenSeq] == array[lIndexOfIdenSeq - 1] 
    && lIndexOfIdenSeq >= firstIndex + 1){
        lIndexOfIdenSeq--;
    }
    if (key < array[rIndexOfIdenSeq + 1] && key > array[rIndexOfIdenSeq])
        return rIndexOfIdenSeq + 1;
    if (key < array[lIndexOfIdenSeq] && key > array[lIndexOfIdenSeq - 1])
        return lIndexOfIdenSeq;
    if (key > array[rIndexOfIdenSeq] && rIndexOfIdenSeq <= lastIndex - 1){
        binarySearch(array, rIndexOfIdenSeq + 1, lastIndex, key);
    }else if (key < array[lIndexOfIdenSeq] && lIndexOfIdenSeq >= firstIndex + 1){
        binarySearch(array, firstIndex, lIndexOfIdenSeq - 1, key);
    }
}

void binaryInsertionSort(int *array, int firstIndex, int lastIndex)
{
    for (int i = firstIndex + 1; i <= lastIndex; i++){
        int key = array[i];
        int loc = binarySearch(array, firstIndex, i - 1, key);
        if (loc != i){
            for (int j = i - 1; j >= loc; j--){
                array[j + 1] = array[j];
            }
            array[loc] = key; 
        }
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
    binaryInsertionSort(array, 0, n - 1);
    printArray(array, n);
    return 0;
}