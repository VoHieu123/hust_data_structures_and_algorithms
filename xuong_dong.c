#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 500
#define ONE_LINE 50

int process(char *target){
    int memory[MAX*5/ONE_LINE];
    memory[0] = -1;
    for (int n = 1; n <= 10; n++){
        if (n == 1){
            for (int i = ONE_LINE; i >= 0; i--){
                if (isspace(target[i]) != 0) {
                    memory[n] = i;
                    break;
                }
            }
        }else{
            for (int i = memory[n-1] + ONE_LINE + 1; i > memory[n-1]; i--){
                if (isspace(target[i]) != 0) {
                    memory[n] = i;
                    break;
                }
            }
        }

        for (int i = memory[n-1] + 1; i < memory[n]; i++){
            printf("%c", target[i]);
        }
        printf("\n");
        if (strlen(target) - memory[n] <= 50){
            for (int i = memory[n] + 1; i < strlen(target); i++){
                printf("%c", target[i]);
            }
            break;
        }
    }
}
int main(){
    char target[MAX] = "MOT HAI BA 62 367 82 37 72 DONG_NAY RAT_LA_DAI_HIHI 27 123 222 72 73 364 123 DONG_NAY_RAT_LA_DAI_HIHI";
    process(target);
}