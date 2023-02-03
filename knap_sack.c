#include <stdio.h>
#include <stdlib.h>
struct bag{
    int value;
    int weight;
    int mark;
} *options;
typedef struct bag bag;

void input(int numberOfElements, bag *options){

    printf("Enter the number of elements: ");
    scanf("%d", &numberOfElements);
    options = (bag*) malloc(numberOfElements * sizeof(bag));

    printf("Enter value and weight respectively: ");
    for (int i = 0; i < numberOfElements; i++){
        scanf("%d %d", &(options + i)->value, &(options + i)->weight);
        (options + i)->mark = 1;
    }
}

void solveKnapSack(bag *options, int W, int valEnd, int curVal, int curWei, int startPos, int numberOfElements){
    for (int i = startPos; i < numberOfElements; i++){
        if (curWei < W){
            curVal += ((options + i)->value)*((options + i)->mark);
            curWei += ((options + i)->weight)*((options + i)->mark);
            (options + i)->mark = 0;
        }
    }

    startPos++;
    if (startPos < numberOfElements) solveKnapSack(options, W, valEnd, curVal, curWei, startPos, numberOfElements);
}





























void main(){

}