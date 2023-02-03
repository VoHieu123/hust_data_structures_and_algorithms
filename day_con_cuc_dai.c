#include <stdio.h>
#include <stdlib.h>
#define size 10

int *input()
{
    int *array = (int*)malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++){
        scanf("%d", array[i]);
    }
    return array;
}

int findMax(int *partialSum)
{
    int max = -99999999;
    for (int i = 0; i < size; i++){
        max = partialSum[i] > max ? partialSum[i] : max;
    }
    return max;
}

int findEndIndex(int *partialSum)
{
    int max = -99999999;
    int endIndex;
    for (int i = 0; i < size; i++){
        if (partialSum[i] > max){
            max = partialSum[i];
            endIndex = i;
        }
    }
    return endIndex;
}

int traceStartIndex(int endIndex, int max, int *inputArray)
{
    int startIndex;
    for (int i = endIndex; i >= 0; i--){
        max -= inputArray[i];
        if (max == 0){
            startIndex = i;
            break;
        }
    }
    return startIndex;
}

int *dynamicProgramming(int* inputArray)
{
    int *partialSum = (int*)malloc(sizeof(int)*size);
    partialSum[0] = inputArray[0];
    for (int i = 1; i < size; i++){
        partialSum[i] = partialSum[i - 1] <= 0 ? inputArray[i] : (partialSum[i - 1] + inputArray[i]);
    }
    return partialSum;
}

void printSolution(int startIndex, int endIndex, int *inputArray)
{
    printf("The sequence is: \n");
    for (int i = startIndex; i <= endIndex; i++){
        printf("%d", inputArray[i]);
        if (i == endIndex){
            printf(".");
        }else{
            printf(" ");
        }
    }
}

void main()
{
    int *inputArray = input();
    int *partialSum = dynamicProgramming(inputArray);
    int max = findMax(partialSum);
    int endIndex = findEndIndex(partialSum);
    int startIndex = traceStartIndex(endIndex, max, inputArray);
    printSolution(startIndex, endIndex, inputArray);
}