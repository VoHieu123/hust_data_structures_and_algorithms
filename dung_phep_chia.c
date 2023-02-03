#include <stdio.h>
#include <string.h>

int series[5];
int resultSeries[5];

int processing(int *series){
    for (int j = 0; j < 5; j++){
        int product = 1;
        for (int i = 0; i < 5; i++ ){
            product *= series[i];
        }
        if (series[j] == 0){
            series[j] = 0;
        }else{
        resultSeries[j]= product/series[j];
        }
    }
}

void printSeries(int *series){
    for (int i = 0; i < 5; i++){
        printf("%d,", series[i]);
    }
}

void main(){
    
    for (int i = 0; i < 5; i++) {
        scanf("%d",&series[i]);
    }
    processing(series);
    printSeries(resultSeries);
    
}
