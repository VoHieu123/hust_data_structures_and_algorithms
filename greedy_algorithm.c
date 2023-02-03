#include <stdio.h>

#define MAX 3

int rSlength;

struct line {
    int start;
    int end;
} space[MAX], resultSpace[MAX];

void input(){
    for (int i = 0; i < MAX; i++){
        scanf("%d %d", &(space[i].start), &(space[i].end));
    }
}

void rearrange(){
    struct line key;
    for (int i = 1; i < MAX - 1; i++){
        key = space[i];
        int u;
        u = i - 1;
        while (u >= 0 && space[u].end >= key.end){
            space[u+1] = space[u];
            u--;
        }
        space[u+1] = key;
    }
}

void process(){
    resultSpace[0] = space[0];
    int u = 1;
    for (int i = 1; i < MAX; i++){
        if (space[i].start >= resultSpace[u-1].end){
            resultSpace[u] = space[i];
            u++;
        }
    }
    rSlength = u;
}

void print(int x){
    for (int i = 0; i < x; i++){
        if (i == x - 1){
            printf("%d, %d.", resultSpace[i].start, resultSpace[i].end);
        }else{
        printf("%d, %d; ", resultSpace[i].start, resultSpace[i].end);
        }
    }
}

void main(){
    input();
    rearrange();
    process();
    print(rSlength);
}