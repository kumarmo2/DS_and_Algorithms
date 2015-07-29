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
list *mergedlist(list *a,list *b);


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

list *mergedlist(list *a,list *b)
{
    list *res=NULL;
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    else
    {
        if(a->data <= b->data)
        {
            res=a;
            res->next=mergedlist(a->next,b);
        }
        else
        {
            res=b;
            res->next=mergedlist(a,b->next);
        }
    }
    return res;
}


void main()
{
    printf("#############  Welcome to Linked List Operations ########## \n \n");
    list *head1=NULL,*head2=NULL;
    head1=create(head1);
    head2=create(head2);
    showlist(head1);
    showlist(head2);
    printf("\nThe merged linked list is created....\n");
    showlist(mergedlist(head1,head2));
}
