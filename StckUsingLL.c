#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *top;

void create(), push(), pop(), display();

int main()
{
    int choice,item;
    while(1)
    {

        printf("Operations:\n");
        printf("1. Create\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Print Elements\n");
        printf("5. Quit\n");
        printf("Choose operation: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
            push();
            break;
        case 3:
            pop();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice\n");

        }
        printf("\n\n\n");
    }
}


void create()
{
    char ch;
    struct node *ptr, *cpt;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Input first Element: ");
    scanf("%d",&ptr->info);
    ptr->link = NULL;

    do
    {
        cpt=(struct node*)malloc(sizeof(struct node));
        printf("\nInput next element: ");
        scanf("%d",&cpt->info);
        cpt->link = ptr;
        ptr = cpt;
        printf("Press Y/N for more insertion: ");
        ch = getch();
    }while(ch == 'Y' || ch == 'y');

    top = ptr;
}

void push()
{

}

void pop()
{
    top = top->link;
    printf("The New Stack is: \n");
    display();
}

void display()
{
    struct node *ptr;
    ptr = top;

    while(ptr != NULL)
    {
        printf("%d\n",ptr->info);
        ptr = ptr->link;
    }
}


























