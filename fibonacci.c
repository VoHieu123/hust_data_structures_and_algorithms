#include <stdio.h>
#include <stdlib.h>
#define MAX 200

void main(){

    //Get the valid value for n
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    while (n < 1){
        printf("Re-enter valid for n (n>0): ");
        scanf("%d",&n);
    }

    //Set an all element of 2D array memory[n][MAX] = 0
    int memory[n][MAX];
    for (int i = 0; i < n; i++){
        for (int u = 0; u < MAX ; u++){
            memory[i][u] = 0;
        }
    }
    //Set memory[1][39] = 1;
    memory[1][MAX-1] = 1;

    //Processing phase
    for (int i = 2; i < n; i++){
        int c = 0;
        for (int u = MAX - 1; u >= 0; u--){
            memory[i][u] = c + (memory[i - 1][u] + memory[i - 2][u])%10;
            c = 0;
            if (memory[i][u] == 10){
                memory[i][u] = 0;
                c = 1;
            }
            if ((memory[i - 1][u] + memory[i - 2][u]) >= 10 ){
                c = 1;
            }
        }
    }

    // Output phase
    printf("0 0\n");//Print the first output line
    if (n > 1){
        for (int u = 1; u < n; u++){
            printf ("%d ", u); //Print the corresponding order from u = 1 to n

            //Find the first position of memory[u][i] that is (!= 0) and store at startPos
            int startPos = 0;
            for (int i = 0; i < MAX; i++){
                if (memory[u][i] != 0){
                    startPos = i;
                    break;
                }
            }
            //Start printing the memory[u][i] from i = position of the first non-zero element
            for (int i = startPos; i < MAX; i++){
                printf ("%d", memory[u][i]);
            }
            printf("\n");
        }
    }
    /* Codes for proofreeding the program
    for (int u = 0; u < n; u++){
        for (int i = 35; i < MAX; i++){
            printf("%d", memory[u][i]);
        }
        printf("\n");
    }
    */
}