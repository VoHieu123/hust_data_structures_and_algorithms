#include <stdio.h>

typedef struct Node{
    int id;
    struct Node* leftMostChild;
    struct Node* rightSibling;
}Node;

Node* root;// pointer to the root of the tree

Node* makeNode(int id){
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id; p->leftMostChild = NULL; p->rightSibling = NULL;
    return p;
}

Node* find(Node* r, int v){
    // return a pointer to a node having id = v
    if(r == NULL) return NULL;
    if(r->id == v) return r;
    Node* p = r->leftMostChild;
    while(p != NULL){
        Node* q = find(p,v);
        if(q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}

void preOrder(){}
void postOrder(){}
void inOrder(){}

int depth(Node* r, int v){
    //retunr the depth of Node having id = v
}
void insert(int v, Node* p){
    // create a new node having id = v,
    // insert at the end of the children list of p
    Node* q = makeNode(v);
    if(p->leftMostChild == NULL)
        p->leftMostChild = q;
    else{
        Node* i = p->leftMostChild;
        while(i->rightSibling != NULL)
            i = i->rightSibling;
            i->rightSibling = q;
    }
}
void printTree(Node* r){
    if(r == NULL) return;
    printf("%d: ",r->id);
    Node* p = r->leftMostChild;
    while(p != NULL){
        printf("%d ",p->id);
        p = p->rightSibling;
    }
    printf("\n");
    p = r->leftMostChild;
    while(p != NULL){
        printTree(p);
        p = p->rightSibling;
    }
}

int count(Node* r)
{
    Node* temp = r; int count;
    while (temp != NULL){
        count++;
    }
}

int countLeaves(Node* r)
{
    if (r == NULL) return 0;
    if (r->leftMostChild == NULL) {
        return 1;
    }else{
        Node* temp = r->leftMostChild;
        int count = 0;
        while (temp != NULL){
            count += countLeaves(temp);
            temp = temp->rightSibling;
        }
        return count;
    }
}

int height(Node* r, int maxHeight) // initially maxHeight = 0;
{
    if (r == NULL) return 0;
    if (r->leftMostChild == NULL) return 1;
    int count = 1;
    Node* temp = r->leftMostChild;
    while (temp->leftMostChild != NULL){
        count += height(temp);
        if (count > maxHeight){
            maxHeight = count;
            return maxHeight;
        }
        temp = temp->rightSibling;
    }
}

int main(){
    root = makeNode(10);
    Node* p = find(root, 10);
    insert(11,p); insert(1,p); insert(3,p);

    p = find(root,11);
    insert(5,p); insert(4,p);

    p = find(root,3);
    insert(8,p); insert(2,p); insert(7,p);

    p = find(root,4);
    insert(6,p); insert(9,p);

    printTree(root);
}