#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{

    int data;
    struct node *link;
};

struct node *root;

void addatend();
void addatbegin();
void addafternode();
void addafterdata();
void deleteatend();
void deleteatbegin();
void deleteafter();
void dispalylist();
void reverselist();
int length();


void main()
{
    int choice,len;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->link = NULL;

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
                deleteafter();
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
}


void addatend()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&temp->data);
    temp->link=NULL;

    struct node* p;
    p=root;
    while(p->link!=NULL)
        p=p->link;
    p->link=temp;
}





void addatbegin()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        temp->link=root;
        root=temp;
    }
}




void addafternode()
{
    printf("Enter the node after which you want to insert:");
    int n;
    scanf("%d",&n);
    if(n>length())
        printf("Node not available,Length of node is %d",length());
    else
    {
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&temp->data);
        temp->link=NULL;
        int i=1;
        struct node* p;
        p=root;
        while(i<n)
        {
            p=p->link;
            i++;
        }
        temp->link=p->link;
        p->link=temp;

    }

}



void addafterdata()
{
    printf("Enter the data after which you want to insert a new node: ");
    int data;
    scanf("%d",&data);
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the new node data: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    struct node *p;
    p=root;
    while(p->data!=data)
    {
        p=p->link;
    }
    temp->link=p->link;
    p->link=temp;

}



void deleteatend()
{
    struct node *p,*temp;
    p=root;
    while(p->link!=NULL)
    {
        temp=p;
        p=p->link;
    }
    temp->link=NULL;
    printf("Deleted item= %d",p->data);
    free(p);
}

void deleteatbegin()
{
    printf("Deleted item= %d",root->data);
    root=root->link;
}

void deleteafter()
{

}

void displaylist()
{
    struct node* temp;
    temp=root;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}


void reverselist()
{
    struct node *p,*temp1,*temp2;
    p=root;
    while(p!=NULL)
    {
        temp2=p->link;
        p->link=temp1;
        temp1=p;
        p=temp2;
    }
    root->link=NULL;
    printf("Reversed list is...\n");
    while(temp1!=NULL)
    {
        printf("%d\t",temp1->data);
        temp1=temp1->link;
    }
}



int length()
{
    struct node *temp;
    int count=0;
    temp=root;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    return count;
}
