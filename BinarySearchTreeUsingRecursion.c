#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct bstNode {
    int data;
    struct bstNode* left;
    struct bstNode* right;
}bstNode;

bstNode* getNewNode(int data) {
    bstNode *new_node = (bstNode*)malloc(sizeof(bstNode));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bstNode* Insert(bstNode* current,int data) {
    if (current == NULL)
    {
        current = getNewNode(data);
    }
    else if (data <= current->data )
    {
        current->left = Insert(current->left, data);
    }
    else
    {
        current->right = Insert(current->right, data);
    }
    
    return current;
}

bool search(bstNode* current, int data) {
    if (current == NULL)
    {
        return false;
    }
    else if (current->data == data)
    {
        return true;
    }
    else if (data <= current->data)
    {
        search(current->left, data);
    }
    else
    {
        search(current->right, data);
    }
}

#define SIZE 20

bstNode* queue[SIZE];
int front = 0, rear = 0;

void InsertIntoQueue(bstNode* data) {
    if (rear == SIZE)
    {
        printf("Queue is full");
    }
    else if (data == NULL)
    {
        return;
    }
    else
    {
        queue[rear] = data;
        rear++;
    }  
}

void DeleteFromQueue() {
    if (rear == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        for (int i = 0; i < (rear - 1); i++)
        {
            queue[i] = queue[i + 1];
        }
        rear--;
    }
}

void LevelOrderTraversal(bstNode* current) {
    if (current == NULL)
    {
        printf("Tree is empty");
    }
    else
    {
        InsertIntoQueue(current);
        while (rear != 0)
        {
            printf("%d  ", current->data);
            DeleteFromQueue();
            InsertIntoQueue(current->left);
            InsertIntoQueue(current->right);
            current = queue[front];
        }
    }  
}

void PreorderTraversal(bstNode* current) {
    if (current == NULL)
    {
        return;
    }
    
    printf("%d  ",current->data);
    PreorderTraversal(current->left);
    PreorderTraversal(current->right);
}

void InorderTraversal(bstNode* current) {
    if (current == NULL)
    {
        return;
    }
    PreorderTraversal(current->left);
    printf("%d  ",current->data);
    PreorderTraversal(current->right);
}

void PostorderTraversal(bstNode* current) {
    if (current == NULL)
    {
        return;
    }
    PreorderTraversal(current->left);
    PreorderTraversal(current->right);
    printf("%d  ",current->data);
}

int IsSubtreeLesser (bstNode* current, int value) {
    if (current == NULL) return 1;
    if (current->data <= value && IsSubtreeLesser (current->left, value && IsSubtreeLesser (current->right, value)))
        return 1;
    else return 0;
}

int IsSubtreeGreater (bstNode* current, int value) {
    if (current == NULL) return 1;
    if (current->data > value && IsSubtreeGreater (current->left, value) && IsSubtreeGreater (current->right, value))
        return 1;
    else return 0;
}

int IsBinarySearchTreeMethod_1 (bstNode* current) {
    if (current == NULL) return 1;
    if (IsSubtreeLesser (current->left, current->data)
        && IsSubtreeGreater (current->right, current->data)
        && IsBinarySearchTreeMethod_1 (current->left)
        && IsBinarySearchTreeMethod_1 (current->right))
        return 1;
    else return 0;
}

int INT_MIN = -32768;
int INT_MAX = 32767;

int BstUtil (bstNode* current,int minValue, int maxValue) {
    if (current == NULL) return 1;
    if (current->data > minValue && current->data < maxValue && BstUtil (current->left, minValue, current->data)
        && BstUtil (current->right, current->data, maxValue))
        return 1;
    else return 0;
}

int IsBinarySearchTreeMethod_2 (bstNode* root) {
    return BstUtil (root, INT_MIN, INT_MAX);
}

void DeleteANode (bstNode* current, int data) {
    if (current == NULL) return;
    else if (current->)
}


int main() {
    bstNode* root = NULL;
    root = Insert(root,15);
    root = Insert(root,20);
    root = Insert(root,10);
    root = Insert(root,9);
    root = Insert(root,19);
    root = Insert(root,11);
    root = Insert(root,25);
    root = Insert(root,18);
    root = Insert(root,1);

    // int number;
    // printf("Enter the no. : ");
    // scanf("%d",&number);
    // if (search(root,number) == true)
    // {
    //     printf("Found");
    // }
    // else
    // {
    //     printf("Not Found");
    // }

    // LevelOrderTraversal(root);
    // PreorderTraversal(root);
    // printf("\n");
    // InorderTraversal(root);
    // printf("\n");
    // PostorderTraversal(root);

    // if (IsBinarySearchTreeMethod_1 (root)) printf("It is a Bst\n");
    // else printf("It is Not a Bst\n");

    // if (IsBinarySearchTreeMethod_2 (root)) printf("It is a Bst\n");
    // else printf("It is Not a Bst\n");
    
    printf("Enter the data to be deleted : ");
    int dataToBeDeleted;
    scanf("%d", &dataToBeDeleted);
    DeleteANode(root, dataToBeDeleted)

    return 0;
}