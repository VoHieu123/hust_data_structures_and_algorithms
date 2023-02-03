#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int number;
    struct Node* next;
}Node;

Node *makeNode(int input){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->number = input;
    temp->next = NULL;
    return temp;
}

Node *insertAfter(Node *pointer, int afterWhat, int input)
{
    if (pointer == NULL)
        return makeNode(input);
    if (pointer->number == afterWhat){
        Node *temp = makeNode(input);
        temp->next = pointer->next;
        pointer->next = temp;
    }else{
        pointer->next = insertAfter(pointer->next, afterWhat, input);
    }
}

Node *insertBefore(Node *pointer, int beforeWhat, int input)
{
    
    if (pointer == NULL)
        return makeNode(input);
    if (pointer->next->number == beforeWhat){
        Node *temp = makeNode(input);
        temp->next = pointer->next;
        pointer->next = temp;
    }else{
        pointer->next = insertBefore(pointer->next, beforeWhat, input);
    }
}

Node *insertTail(Node *pointer, int input)
{
    if (pointer == NULL)
        return makeNode(input);
    pointer->next = insertTail(pointer->next, input);
}

Node *insertHead(Node *pointer, int input)
{
    Node *temp = makeNode(input);
    temp->next = pointer;
    pointer = temp;
    return pointer;
}

Node *deleteNode(Node *pointer, int input)
{
    if (pointer == NULL) return NULL;
    if (pointer->number == input){
        Node *temp = pointer;
        pointer = pointer->next;
        free(temp);
        return pointer;
    }else{
        pointer->next = deleteNode(pointer->next, input);
    }
}

void print(Node *pointer)
{
    if (pointer == NULL)
        return;
    printf("%d ", pointer->number);
    print(pointer->next);
}

void main()
{
    Node *head;
    head = makeNode(10);
    head = insertHead(head, 9);
    head = insertHead(head, 8);
    insertTail(head, 7);
    insertTail(head, 6);
    deleteNode(head, 6);
    print(head);
}