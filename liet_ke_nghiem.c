#include <stdio.h>
#define MAX 4

int coef[MAX];
int vari[MAX];
int sumValue;

void input()
{
    for (int i = 0; i < MAX; i++){
        scanf("%d", &coef[i]);
    }
    scanf("%d", &sumValue);
}

int process(int i, int sum)
{
    if (i < MAX){
        for (int j = 1; j <= sumValue; j++){
            int tempsum = sum;
            sum += coef[i]*j;
            vari[i] = j;
            process(i+1, sum);
            sum = tempsum;
        }
    }else{
        if (sum == sumValue){
            for (int k = 0; k < MAX; k++){
                printf("%d ", vari[k]);
            }
            printf("\n");
        }
    }
}

void main(){
    input();
    process(0,0);
}