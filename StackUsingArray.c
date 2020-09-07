#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define CAPACITY 5

int stack[CAPACITY], top=-1;

void Push(int);
void Pop();
void Print();
int isFull();
int isEmpty();

void main()
{
    int choice,item;
    while(1)
    {

        printf("Operations:\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Print Elements\n");
        printf("4.Quit\n");
        printf("Choose operation:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter the element:");
            scanf("%d",&item);
            Push(item);
            break;
        case 2:
            Pop();
            break;
        case 3:
            Print();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice\n");

        }
        printf("\n\n\n");
    }
}


void Push(int ele)
{
    if(isFull())
        printf("Stack is Full");
    else
    {
        top++;
        stack[top]=ele;
        printf("%d Inserted\n",ele);
    }
}



int isFull()
{
    if(top==CAPACITY-1)
        return 1;
    else
        return 0;
}



void Pop()
{
    if(isEmpty())
        printf("Stack underflow\n");
    else
    {
        printf("Popped item is %d",stack[top]);
        stack[top]='\0';
        top--;
    }
}


int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}


void Print()
{
    int i;
    if(isEmpty())
        printf("Stack is empty\n");
    else
    {
        printf("Elements are: ");
        for(i=0;i<=top;i++)
        {
            printf("%d\t",stack[i]);
        }
    }

}
