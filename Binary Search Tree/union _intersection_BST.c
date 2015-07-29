#include<stdio.h>
#include<stdlib.h>

struct BST
{
 int data;
 struct BST *left,*right;
};
typedef struct BST node;

void insert(node *,node *,int );
void display(node *);
node *get_node(int);
node *intersectionBST(node *root1,node *root2,node *res);
node *unionBST(node *root,node *res2);

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

int search(node *root,int data)
{
    if(root==NULL)
        return 0;
    else
    {
        if(root->data==data)
            return 1;
        else if(root->data > data)
            return search(root->left,data);
        else
            return search(root->right,data);
    }
}

node *intersectionBST(node *root1,node *root2,node *res)
{
    if(root1)
    {
        intersectionBST(root1->left,root2,res);
        if(search(root2,root1->data))
        {
            node *new_node=get_node(root1->data);
            if(res==NULL)
                res=new_node;
            else
                insert(res,new_node,root1->data);
        }
        intersectionBST(root1->right,root2,res);
    }
    else
        return res;
}

node *unionBST(node *root,node *res2)
{
  if(root)
  {
      unionBST(root->left,res2);
      if(!search(res2,root->data))
      {
          node *new_node=get_node(root->data);
          if(res2==NULL)
            res2=new_node;
          else
          insert(res2,new_node,root->data);
      }
      unionBST(root->right,res2);
  }
  else
    return res2;
}



void main()
{
    printf("Creating two BST.....");
    node *root1=NULL,*root2=NULL,*res1=NULL,*new_node1,*new_node2,*res2=NULL;
    int data=0,i,j,key=0;

    for(i=5,j=1;j<=15;i++,j++)
    {
      new_node1=get_node(i);
      new_node2=get_node(j);
      if(root1==NULL)
        root1=new_node1;
      if(root2==NULL)
        root2=new_node2;
      else
      {
        insert(root1,new_node1,i);
        insert(root2,new_node2,j);
      }
    }
    printf("\nThe BST_1 created is: ");
    display(root1);
    printf("\nThe BST_2 created is: ");
    display(root2);

    res1=intersectionBST(root1,root2,res1);
    printf("\nThe intersection of BST_1 and BST_2 is:");
    display(res1);

    res2=unionBST(root1,res2);
    res2=unionBST(root2,res2);
    printf("\nThe intersection of BST_1 and BST_2 is:");
    display(res2);
}
