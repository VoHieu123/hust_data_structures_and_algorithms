#include <stdio.h>
#include <string.h>
#define MAX 5

int series[MAX];
int resultSeries[MAX];

int processing(int *series){
    for (int j = 0; j < MAX; j++){
        int product = 1;
        for (int i = 0; i < MAX; i++ ){
            if (i == j) continue;
            product *= series[i];
        }
        resultSeries[j]= product;
    }
}

void printSeries(int *series){
    for (int i = 0; i < MAX; i++){
        printf("%d,", series[i]);
    }
}

void main(){
    for (int i = 0; i < MAX; i++) {
        scanf("%d",&series[i]);
    }
    processing(series);
    printSeries(resultSeries);
}
