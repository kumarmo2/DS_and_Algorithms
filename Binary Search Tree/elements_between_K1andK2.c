#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct BST
{
 int data;
 struct BST *left,*right;
};
typedef struct BST node;

void insert(node *,node *,int );
void display(node *);
node *get_node(int);

node *get_node(int data)
{
 node *temp;
 temp=(node *)malloc(sizeof(node));
 temp->data=data;
 temp->left=NULL;
 temp->right=NULL;

 return temp;
}

void insert(node *root,node *new_node,int data)
{
     if(root->data > data)
     {
         if(root->left==NULL)
            root->left=new_node;
         else
            insert(root->left,new_node,data);
     }
     else
     {
        if(root->right==NULL)
            root->right=new_node;
        else
            insert(root->right,new_node,data);
     }
}

void display(node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        printf("%d ",root->data);
        display(root->right);
    }
}

void printrange(node *root,int k1,int k2)
{
    if(root!=NULL)
    {
        if(root->data >= k1 || root->data <= k2)
           printrange(root->left,k1,k2);
        if(root->data>=k1 && root->data<=k2)
            printf("%d ",root->data);
        if(root->data < k2 || root->data > k1)
            printrange(root->right,k1,k2);
    }
}

void main()
{
    char ans='n';
    printf("Want to create a BST (y/n) ? :");
    scanf("%c",&ans);
    node *root=NULL;
    int data=0,key;
    while(ans=='y')
    {
      node *new_node;
      printf("\nEnter the element = ");
      scanf("%d",&data);
      new_node=get_node(data);
      if(root==NULL)
        root=new_node;
      else
        insert(root,new_node,data);
      printf("\nWant to add more elements(y/n)? : ");
      ans=getch();
    }
    printf("\nThe BST created is: ");
    display(root);
    int k1,k2;
    printf("\nEnter the range k1 and k2 = ");
    scanf("%d%d",&k1,&k2);
    printf("\nThe elements in the range k1 and k2 are :");
    printrange(root,k1,k2);

}
