#include <stdio.h>
#include <stdlib.h>
int a,b,c;
int visited[1000][1000];
typedef struct State{
    int x,y;
    State* next; 
}State;

State* head;
State* tail;

void iniQueue(){
    head = NULL; tail = NULL;
}

State* makeState(int x, int y){
    State*s = (State*)malloc(sizeof(State));
    s->x = x; s->y = y; s->next = NULL;
    return s;
}
void push(State* s){
    if(empty()){
        head = s; tail = s; return;
    }else{
        tail->next = s; tail = s;
    }
}

State* pop(){
    if(empty()){
        return NULL;
    }
    State* rs = head; head = head->next;
    if (head == NULL) tail = NULL;
    return rs;
}

int finalState(State *s){
    return s->x == c || s->y == c || s->x + s->y == c;
}

State* solve(){
    initQueue();
    State* startState = makeState(0,0);
    push(startState);
    visited[0][0] = 1;
    while (!empty()){
        State* s = pop();
        int nx = a; 
        int ny = s->y;
        if (visited[nx][ny]) continue;
        State* ns = makeState(nx,ny);
        if (finalState(ns)) return ns;
    }
}

int empty(){
    return head == NULL && tail == NULL; 
}

int main(){

}