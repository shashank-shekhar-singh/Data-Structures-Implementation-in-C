#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = 0, rear = 0;

void Insert(int data) {
    if (rear == SIZE)
    {
        printf("Queue is full");
    }
    else
    {
        queue[rear] = data;
        rear++;
    }  
}

void Delete() {
    if (rear == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("The deleted element is %d", queue[front]);
        for (int i = 0; i < (rear - 1); i++)
        {
            queue[i] = queue[i + 1];
        }
        rear--;
    }
}

void Display() {
    if (rear == front)
    {
        printf("Queue is empty");
    }
    else
    {
        for (int i = front; i < rear; i++)
        {
            printf("%d  ",queue[i]);
        }
        
    }
    
    
}

int main()
{

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
            Insert(data);
            break;

        case 2:
            Delete();
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


    return 0;
}
