#include<stdio.h>
#include<stdlib.h>
int count=0;

struct BST
{
 int data;
 struct BST *left,*right;
};
typedef struct BST node;

void insert(node *,node *,int );
void display(node *);
void *findkthsmallest(node *,int k);
node *get_node(int);
node *findmax(node *root);
node *findmin(node *root);
node *deletenode(node *root,int data);


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

node *findmax(node *root)
{

    if(root==NULL)
        return NULL;
    else if(!root->right)
        return root;
    else
       return findmax(root->right);
}

node *findmin(node *root)
{
    node *temp;
    if(root==NULL)
        return NULL;
    else if(!root->left)
        return root;
    else
       return findmin(root->left);
}

void *findkthsmallest(node *root,int k)  //INORDER TRAVERSAL RESULTING IN SORTED ORDER
{
   if(root==NULL)
     return ;
else
{
   findkthsmallest(root->left,k);
   count++;
   if(count==k)
   {
     printf("\nkth smallest element is %d",root->data);
     root->right=NULL;
     return;
   }
   findkthsmallest(root->right,k);
}
}

node *deletenode(node *root,int data)
{
    node *temp;
    if(root==NULL)
        printf("Element doesnot exist!!!");

    else if(root->data > data)
         root->left=deletenode(root->left,data);
    else if(root->data < data)
         root->right=deletenode(root->right,data);
    else
    {
        if(root->left && root->right)
        {
            printf("\ntest");
            temp=findmax(root->left);
            root->data=temp->data;
            root->left=deletenode(root->left,root->data);
        }
        else
        {
            temp=root;
            if(root->left)
                root=root->left;
            else if(root->right)
                root=root->right;
            else
                root=NULL;
            free(temp);
        }

    }
    return root;
}

void main()
{
    char ans='n';
    printf("Want to create a BST (y/n) ? :");
    scanf("%c",&ans);
    node *root=NULL;
    int data=0,count=0,k=0;
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
    printf("\nsmallest node= %d",findmin(root)->data);
    printf("\nlargest node= %d",findmax(root)->data);
    printf("\nEnter the value of k for kth smallest node = ");
    scanf("%d",&k);
    findkthsmallest(root,k);
    printf("\nDo you want to delete a node (y/n)? :");
    ans=getch();
    if(ans=='y')
    {
        printf("\nEnter the element you want to delete = ");
        scanf("%d",&data);
        root=deletenode(root,data);
        printf("\nThe BST after deletion is: ");
        display(root);
    }
}
