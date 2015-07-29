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
list *insertnode(list *head,int data,int pos);
list *deletenode(list *head,int data);
list *deletelist(list *head);



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


list *insertnode(list *head,int data,int pos)
{
    list *newnode=(list *)malloc(sizeof(list));
    if(!newnode)
        printf("Memory Error !!! \n");
    else
    {
     list *p,*q;
     int k=1;
     if(pos==1)
     {
         newnode->data=data;
         newnode->next=head;
         head=newnode;
     }
     else
     {
         p=head;
         while( (k<pos) && (p!=NULL))
         {
             q=p;
             p=p->next;
             k++;
         }
         if(p==NULL && k!=pos)
            printf("Position doesnot exist!!!!! \n");
         else
         {
             newnode->data=data;
             newnode->next=p;
             q->next=newnode;
         }
     }
     return head;
    }

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

 list *deletenode(list *head,int data)
 {
     list *temp,*p,*q;
     int pos=1;
     p=head;

     while(p!=NULL && p->data!=data)
     {
         q=p;
         p=p->next;
         pos++;
     }
     if(pos==1)  // deletion at the beginning
     {
         temp=head;
         head=temp->next;
         free(temp);
     }
     else if(pos!=1 && p!=NULL)
     {
         q->next=p->next;
         free(p);
     }
     else
        printf("Item not found\n");
     return head;
 }

 list *deletelist(list *head)
 {
     list *iterator,*auxillary;
     iterator=head;
     while(iterator)
     {
         auxillary=iterator->next;
         free(iterator);
         iterator=auxillary;
     }
     head=NULL;
     printf("The linked list is successfully deleted !!!!! \n");
     return head;
 }


void main()
{
    printf("#############  Welcome to Linked List Operations ########## \n \n");

    int i=0;
    int pos=0;
    list *head=NULL;
    while(i!=-1)
    {
     printf("\n1)Create a Linked list(Press 1)\n2)Insert a node(Press 2)\n3)Show the List(Press 3)\n4)Delete a node(Press 4)\n5)Delete the linked list(Press 5)\n6)Enter -1 to exit\n");
     scanf("%d",&i);
     switch (i)
     {
        case 1:
            head=create(head);
            break;
        case 2:
            printf("\nEnter the data = ");
            scanf("%d",&data);
            printf("Enter the position in which you want to insert = ");
            scanf("%d",&pos);
            head=insertnode(head,data,pos);
            break;
        case 3:
            showlist(head);
            break;
        case 4:
            printf("\nEnter the data you want to delete= ");
            scanf("%d",&data);
            head=deletenode(head,data);
            break;
        case 5:
            head=deletelist(head);
            break;
        case -1:
            exit(0);
        default:
            printf("Invalid option");
     }

    }
}
