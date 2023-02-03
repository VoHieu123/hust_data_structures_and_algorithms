#include <stdio.h>
#include <stdlib.h>

struct Node {
    char c;
    struct Node* next;
};
typedef Node Node;

Node* top = NULL;

void makeNode(Node* new, char newitem){
    new = (Node*)malloc(sizeof(Node));
    new->c = newitem;
}

char pop(){
    if (top == NULL){
        return 0;
    }else{
        Node* temp = top;
        top = top->next;
        char rs = temp->c;
        free(temp);
        return rs;
    }
}
void push (Node* new){
    new->next = top;
    top = new;
}