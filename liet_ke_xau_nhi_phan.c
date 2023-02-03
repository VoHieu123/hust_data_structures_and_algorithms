#include <stdio.h>
#define MAX 5
int nhiphan[MAX];
void print(){
    for (int i = 0; i < MAX; i++){
        printf("%d", nhiphan[i]);
        if (i == MAX - 1) printf("\n");
    }
}
int check(){
    for (int v = 0; v < MAX; v++){
        if (nhiphan[v] == 1 && nhiphan[v+1] == 1){
            return 0;
        }
    }
    return 1;  
}

void process(int u){
    for (int i = 0; i < 2; i++){
        nhiphan[u] = i;
        if (u != MAX){
            process(u+1);
        }else{
            if (check()) print();
            return;
        }
    }
}

void main(){
    process(0);
}