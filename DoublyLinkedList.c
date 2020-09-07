#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node

{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

void addatend();
void addatbegin();
void addafterdata();
void addafternode();
void deleteatend();
void deleteatbegin();
void deleteafternode();
void displaylist();
void reverselist();
int length();


int main()
{
    int choice,len;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;

    printf("CREATE NEW LINKED LIST\n\n\nEnter the data of first node: ");
    scanf("%d",&temp->data);

    root = temp;

    while(1)
    {
        printf("\n\nLINKED LIST OPERATIONS---\n");
        printf("1.Add at the end\n");
        printf("2.Add at beginning\n");
        printf("3.Add after Kth node\n");
        printf("4.Add after an element\n");
        printf("5.Delete at end\n");
        printf("6.Delete at beginning\n");
        printf("7.Delete Kth node\n");
        printf("8.Display List\n");
        printf("9.Length of list\n");
        printf("10.Reverse List\n");
        printf("11.Exit\n\n\n");
        printf("Choose option---");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addatend();
                break;
            case 2:
                addatbegin();
                break;
            case 3:
                addafternode();
                break;
            case 4:
                addafterdata();
                break;
            case 5:
                deleteatend();
                break;
            case 6:
                deleteatbegin();
                break;
            case 7:
                deleteafternode();
                break;
            case 8:
                displaylist();
                break;
            case 9:
                len=length();
                printf("Length is %d",len);
                break;
            case 10:
                reverselist();
                break;
            case 11:
                exit(1);
            default:
                printf("\nInvalid choice\n");
        }
    }
getch();
return 0;
}

void addatend()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:  ");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;

    struct node *p;
    p=root;
    while(p->right != NULL)
    {
        p = p->right;
    }
    p->right = temp;
    temp->left = p;
}


void addatbegin()
{

}


void addafterdata()
{

}

void addafternode()
{

}

void deleteatend()
{

}

void deleteatbegin()
{

}

void deleteafternode()
{

}


void displaylist()
{
    struct node *p;
    p=root;
    if(root==NULL)
        printf("No elemnts\n");
    else
    {
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            p=p->right;
        }
    }
}


void reverselist()
{

}

int length()
{

}











