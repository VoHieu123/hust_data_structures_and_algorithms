#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int key;
    struct Node *leftChild;
    struct Node *rightChild;
}Node;

Node *head = NULL;

int insertNode(int insertedKey, Node* temp)
{
    if (temp == NULL){
        temp = (Node*)malloc(sizeof(Node));
        temp->key = insertedKey;
        temp->leftChild = NULL;
        temp->rightChild = NULL;
    }else{
        if (insertedKey < temp->key){
            insertNode(insertedKey, temp = temp->leftChild);
        }else if(insertedKey > temp->key){
            insertNode(insertedKey, temp->rightChild);
        }else{
            printf("Key %d existed", insertedKey);
        }
    }
}

int printTree(Node* currentPointer)
{
    if (currentPointer != NULL){
        printf("%d", currentPointer->key);
        printTree(currentPointer->leftChild);
        printTree(currentPointer->rightChild);
    }
}

void main()
{
    insertNode(4, head);
    insertNode(5, head);
    insertNode(3, head);
    insertNode(1, head);
    insertNode(2, head);
    insertNode(6, head);
    printTree(head);
}


