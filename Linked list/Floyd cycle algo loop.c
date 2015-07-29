
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
int checkloop(list *head);

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
          newnode->next=newnode;
          p=newnode;
       }
       else if(newnode && j!=0)
       {
           p->next=newnode;
           newnode->data=data;
           newnode->next=head;
           p=newnode;
       }
       else
        printf("Memory error !!! \n");
      j++;
    }
    if(head!=NULL)
      printf("The circular linked list is created successfully\n");
    return head;
}


 void showlist(list *head)
 {
     if(head!=NULL)
     {
     printf("The list created is: ");
     list *p;
     p=head;
     do
     {
         printf ("%d ",p->data);
         p=p->next;
     }while(p!=head);
     }
     else
        printf("The list is empty !!! \n");
 }

int checkloop(list *head)
{
    list *fastptr=head,*slowptr=head;
    while(fastptr && slowptr && fastptr->next)
    {
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(fastptr==slowptr)
            return 1;
    }
    return 0;
}

void main()
{
    printf("#############  Welcome to Linked List Operations ########## \n \n");

    int i=0;
    int pos=0;
    list *head=NULL;
    head=create(head);
    showlist(head);
    if(checkloop(head))
        printf("\nLoop exists !!!");
    else
        printf("No loop exist !!!");

}
