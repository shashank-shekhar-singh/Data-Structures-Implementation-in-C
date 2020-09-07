#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* link;
}queue;

queue* front = NULL;
queue* rear = NULL;

queue* GetNewNode(int data) {
    queue* newNode = (queue*)malloc(sizeof(queue));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void InsertIntoQueue(int data) {
    if (front == NULL && rear == NULL)
    {
        front = rear = GetNewNode(data);
    }
    else
    {
        rear->link = GetNewNode(data);
        rear = rear->link;
    } 
}

void DeleteFromQueue() {
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        front = front->link;
    }   
}

void Display() {
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        queue* p = front;
        while (p != NULL)
        {
            printf("%d  ", p->data);
            p = p->link;
        } 
    }
    
}

int main() {

    while(1)
    {
        printf("\nOperations-- \n");
        printf("\n1 - Insert");
        printf("\n2 - Delete");
        printf("\n3 - Display");
        printf("\n4 - Exit");
        printf("\nEnter choice : ");
        int choice;
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number : ");
            int data;
            scanf("%d", &data);
            InsertIntoQueue(data);
            break;

        case 2:
            DeleteFromQueue();
            break;

        case 3:
            Display();
            break;
        
        case 4:
            exit(0);
            
        default:
            printf("Wrong input. Enter again");
            break;
        }

    }

}
