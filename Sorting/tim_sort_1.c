#include <stdio.h>
#define MINSIZE 16

void input(int *array, int n)
{
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
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
        insertionSort(array, firstIndex, lastIndex);
    }else{
        int mid = (lastIndex + firstIndex)/2;
        timSort(array, firstIndex, mid);
        timSort(array, mid + 1, lastIndex);
        // For already sorted array, do nothing
        if (array[mid] <= array[mid +1]) return; 
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