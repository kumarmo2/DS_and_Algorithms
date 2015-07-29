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
int BSTfloor(node *root,int key);
int BSTceil(node *root,int key);

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

int BSTfloor(node *root,int key)
{
  if(root==NULL)
    return INT_MAX;

      if(root->data==key)
        return root->data;
      if(root->data > key)
        return BSTfloor(root->left,key);
      else
      {
          int floor=BSTfloor(root->right,key);
          return floor<=key?floor:root->data;
      }

}

int BSTceil(node *root,int key)
{
    if(root==NULL)
        return INT_MIN;
    if(root->data==key)
        return root->data;
    else if(root->data < key)
        return BSTceil(root->right,key);
    else
    {
        int ceil=BSTceil(root->left,key);
        return ceil>=key?ceil:root->data;
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
    printf("\nEnter the key to find the floor of the BST = ");
    scanf("%d",&key);
    if(BSTfloor(root,key)!=INT_MAX)
       printf("\nThe floor of the BST is %d",BSTfloor(root,key));
    else
       printf("\nThe floor doesnot exist for the given key !!!!");
    printf("\nEnter the key to find the floor of the BST = ");
    scanf("%d",&key);
    if(BSTceil(root,key)!=-1)
       printf("\nThe ceil of the BST is %d",BSTceil(root,key));
    else
       printf("\nThe ceil 7doesnot exist for the given key !!!!");

}
