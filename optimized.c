#include <stdio.h>
#include <string.h>
#define MAX 5

int series[MAX];
int resultSeries[MAX];
int pos[MAX];
int pre[MAX];

int processing(int *series){
    pre[0] = series[0];
    for (int i = 1; i < MAX; i++){
        pre[i] = pre[i - 1]*series[i];
    }

    pos[MAX - 1] = series[MAX - 1];
    for (int i = MAX - 2; i >= 0; i--){
        pos[i] = pos[i + 1]*series[i];
    }

    resultSeries[0] = pos[1];
    resultSeries[MAX - 1] = pre[MAX - 2];
    for (int i = 1; i < MAX - 1; i++){
        resultSeries[i] = pre[i - 1]*pos[i + 1];
    }
}

void printSeries(int *series){
    for (int i = 0; i < MAX; i++){
        if (i != MAX -1){
            printf("%d, ", series[i]);
        }else{
            printf("%d.", series[i]);
            break;
        }
    }
}

void main(){
    for (int i = 0; i < MAX; i++) {
        scanf("%d",&series[i]);
    }
    processing(series);
    printSeries(resultSeries);
}
