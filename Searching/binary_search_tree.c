#include <stdio.h>

typedef struct Node
{
    struct Node *right,*left;
    int key;
}Node;

Node *head;

Node *createNode(int number)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->key = number;
    temp->left = temp->right = NULL;
    return temp;
}

Node *addNode(int number)
{
    Node *temp = head;
    if (temp == NULL){
        temp = createNode(number);
    }else{
        if (number > temp->key){
            temp = temp->right;
            temp->key = number;
        }else{
            temp = temp->left;
            temp->key = number;
        }
    }
}
