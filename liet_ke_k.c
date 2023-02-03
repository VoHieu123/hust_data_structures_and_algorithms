#include <stdio.h>

int n;

void input()
{
    printf("Enter n: ");
    scanf("%d", &n);
}

int check(int *result, int k)
{
    for (int i = 1; i < k-1; i++){
        if (result[i] == result[i+1] || result[i] == result[i-1] || result[i] == 0 || result[0] == 0 || result[k ==0]){
            return 0;
        }
    }
    return 1;
}

void printSolution(int *result, int k)
{
    printf("With k = %d:", k);
    for (int i = 0; i < k; i++){
        printf(" %d", result[i]);
        if (i == k-1) printf("\n");
    }
}
void findIt(int j, int i, int *result, int k)
{
    if (j <= k){
        if (i <= n){
            for (; i <= n; i++){
                result[j] = i;
                findIt(j+1,i+1, result, k);
            }
        }
    }else{
        if (check(result,k)) printSolution(result,k);
    }
}
void process()
{
    for (int k = 1; k <= n; k++){
        int result[k];
        for (int x = 0; x < k; x++){
            result[x] = 0;
        }
        findIt(0,1,result,k);
    }
}

void main(){
    input();
    process();
}