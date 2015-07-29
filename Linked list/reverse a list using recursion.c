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
list *reverselist(list *head);


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

 list *reverselist(list *head)
 {
   if(head==NULL)
    return NULL;
   else if(head->next==NULL)
    return head;

   list *secondelement=head->next;
   head->next=NULL;
   list *reverseset=reverselist(secondelement);
   secondelement->next=head;
   return reverseset;
 }


void main()
{
    printf("#############  Welcome to Linked List Operations ########## \n \n");

    int i=0;
    int pos=0;
    list *head=NULL;
    head=create(head);
    showlist(head);
    printf("\nThe reverse linked list is created....\n");
    head=reverselist(head);
    showlist(head);
}
