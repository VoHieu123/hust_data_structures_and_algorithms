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
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int mergeSort(int *array, int firstIndex, int lastIndex)
{
    if (lastIndex - firstIndex == 1){
        if (array[firstIndex] > array[lastIndex])
            swap(&array[firstIndex], &array[lastIndex]);
        return 0;
    }
    if (lastIndex == firstIndex)
        return 0;
    if (lastIndex > firstIndex){
        int mid = (lastIndex + firstIndex)/2;
        mergeSort(array, firstIndex, mid);
        mergeSort(array, mid + 1, lastIndex);

        if (array[mid] > array[mid + 1]){ // Optimized for best case O(n)
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
}

int main()
{
    int n;
    //printf("The number of numbers in the unsorted array: ");
    scanf("%d", &n);
    int array[n];
    //printf("Input unsorted array respectively: ");
    input(array, n);
    mergeSort(array, 0, n - 1);
    printArray(array, 0, n - 1);
    return 0;
}