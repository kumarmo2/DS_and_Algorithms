#include<stdio.h>
#include<stdlib.h>

struct Listnode
{
  int data;
  struct Listnode *next;
};

typedef struct Listnode list;
int data=0;

list *create(list *head);
void showlist(list *head);
list *findnthnode(list *head,int n);


list *create(list *head)
{
    int j=0,size=0;
    printf("Enter the num of elements you want to enter = ");
    scanf("%d",&size);
    list *p=head;
    while(j<size)
    {
       printf("Enter the data = ");
       scanf("%d",&data);
       list *newnode=(list *)malloc(sizeof(list));
       if(newnode && j==0)
       {
          head=newnode;
          newnode->data=data;
          newnode->next=NULL;
          p=newnode;
       }
       else if(newnode && j!=0)
       {
           p->next=newnode;
           newnode->data=data;
           newnode->next=NULL;
           p=newnode;
       }
       else
           printf("Memory error !!! \n");
           j++;
    }
    p=NULL;
    if(head!=NULL)
      printf("The linked list is created successfully\n");
    return head;
}

list *findnthnode(list *head,int n)
{
    list *p,*q;
    int count=0;
    q=head;
    for(p=head;p!=NULL;)
    {
        count++;
        if(count==n && p->next==NULL)
            return q;
        else if(count==n)
        {
            count--;
            q=q->next;
        }
        p=p->next;
    }
    return NULL;
}

 void showlist(list *head)
 {
     if(head!=NULL)
     {
     printf("The list created is: ");
     list *p;
     p=head;
     while(p!=NULL)
     {
         printf ("%d ",p->data);
         p=p->next;
     }
     }
     else
        printf("The list is empty !!! \n");
 }



void main()
{
    printf("#############  Welcome to Linked List Operations ########## \n \n");
    printf("Creating a linked list.......\n");
    int n=0;
    list *head=NULL;
     head=create(head);
     showlist(head);
     printf("\nEnter the nth node from the last you want to see=");
     scanf("%d",&n);
     if(findnthnode(head,n)!=NULL)
       printf("The %dth node from the last is = %d",n,findnthnode(head,n)->data);
     else
        printf("Node doesnot exist !!!");
}
