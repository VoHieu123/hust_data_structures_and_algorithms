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

int findTruePos(int *array, int firstIndex, int lastIndex, int key)
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
        return findTruePos(array, rIndexOfIdenSeq + 1, lastIndex, key);
    }else if (key < array[lIndexOfIdenSeq] && lIndexOfIdenSeq >= firstIndex + 1){
        return findTruePos(array, firstIndex, lIndexOfIdenSeq - 1, key);
    }
    return -1;
}

int binarySearch(int *array, int firstIndex, int lastIndex, int key)
{
    int mid = (firstIndex + lastIndex)/2;
    if (key == array[mid]){
        while(mid <= lastIndex - 1 && array[mid] == array[mid + 1]){
            mid++;
        }
        return mid;
    }
        
    if (key > array[mid] && mid <= lastIndex - 1){
        binarySearch(array, mid + 1, lastIndex, key);
    }else if (key < array[mid] && mid >= firstIndex + 1){
        binarySearch(array, firstIndex, mid - 1, key);
    }
    return -1;
}

int main()
{
    int n;
    //printf("The number of numbers in the unsorted array: ");
    scanf("%d", &n);
    int array[n];
    //printf("Input unsorted array respectively: ");
    input(array, n);
    int loc = findTruePos(array, 0, n-1, 5);
    printf("%d", loc);
    return 0;
}