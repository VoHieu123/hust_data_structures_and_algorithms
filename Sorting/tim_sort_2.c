#include <stdio.h>
#define MINSIZE 64

void input(int *array, int n)
{
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
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

void printArray(int *array, int firstIndex, int lastIndex)
{
    for (int i = firstIndex; i <= lastIndex; i++){
        printf("%d ", array[i]);   
    }
    printf("\n");
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

void timSort(int *array, int firstIndex, int lastIndex)
{
    if (lastIndex - firstIndex + 1 <= MINSIZE ){
        binaryInsertionSort(array, firstIndex, lastIndex);
    }else{
        int mid = (lastIndex + firstIndex)/2;
        timSort(array, firstIndex, mid);
        timSort(array, mid + 1, lastIndex);
        // For already sorted array, do nothing
        //if (array[mid] <= array[mid +1]) return; 
        /*The above line is good only for Merge sort, 
        since it divides the array until size == 1 or 2;
        This results in scenario in which the case of already 
        sorted array is more likely than using Timsort, 
        which divides array into MINSIZE (= 32). The fact 
        that Insertion Sort is already good for already sorted 
        array makes this optimization good for Merge sort but 
        not for Tim sort because the program has to run 1 more
        line of code everytime the function is called*/
        int buffer[lastIndex - firstIndex + 1];
        int i = firstIndex, j = mid + 1, k = 0;
        while (i <= mid && j <= lastIndex){
            if (array[i] < array[j]){
                buffer[k] = array[i];
                i++;
            }else{
                buffer[k] = array[j];
                j++;
            }
            k++;
        }
        if (i <= mid){
            for (;i <= mid; i++){
                buffer[k] = array[i];
                k++;
            }
        }
        if (j <= lastIndex){
            for (;j <= lastIndex; j++){
                buffer[k] = array[j];
                k++;
            }
        }
        int x = 0;
        for (int z = firstIndex; z <= lastIndex; z++){
            array[z] = buffer[x];
            x++;
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
    timSort(array, 0, n - 1);
    printArray(array, 0, n - 1);
    return 0;
}