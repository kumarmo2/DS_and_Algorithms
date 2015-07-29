//Program for linked implementation of complete binary tree
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//#include <time.h>

// For Queue Size
#define SIZE 50


// A tree node
struct node
{
    int data;
    struct node *right,*left;
};

// A queue node
struct Queue
{
    int front, rear;
    int size;
    struct node* *array;
};

// A utility function to create a new tree node
struct node* newNode(int data)
{
    struct node* temp = (struct node*) malloc(sizeof( struct node ));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to create a new Queue
struct Queue* createQueue(int size)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof( struct Queue ));

    queue->front = queue->rear = -1;
    queue->size = size;

    queue->array = (struct node**) malloc(queue->size * sizeof( struct node* ));

    int i;
    for (i = 0; i < size; ++i)
        queue->array[i] = NULL;

    return queue;
}

// Standard Queue Functions
int isEmpty(struct Queue* queue)
{
    return queue->front == -1;
}

int isFull(struct Queue* queue)
{  return queue->rear == queue->size - 1; }

int hasOnlyOneItem(struct Queue* queue)
{  return queue->front == queue->rear;  }

void Enqueue(struct node *root, struct Queue* queue)
{
    if (isFull(queue))
        return;

    queue->array[++queue->rear] = root;

    if (isEmpty(queue))
        ++queue->front;
}

struct node* Dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return NULL;

    struct node* temp = queue->array[queue->front];

    if (hasOnlyOneItem(queue))
        queue->front = queue->rear = -1;
    else
        ++queue->front;

    return temp;
}

struct node* getFront(struct Queue* queue)
{  return queue->array[queue->front]; }

// A utility function to check if a tree node has both left and right children
int hasBothChild(struct node* temp)
{
    return temp && temp->left && temp->right;
}

// Function to insert a new node in complete binary tree
void insert(struct node **root, int data, struct Queue* queue)
{
    // Create a new node for given data
    struct node *temp = newNode(data);

    // If the tree is empty, initialize the root with new node.
    if (!*root)
        *root = temp;

    else
    {
        // get the front node of the queue.
        struct node* front = getFront(queue);

        // If the left child of this front node doesn’t exist, set the
        // left child as the new node
        if (!front->left)
            front->left = temp;

        // If the right child of this front node doesn’t exist, set the
        // right child as the new node
        else if (!front->right)
            front->right = temp;

        // If the front node has both the left child and right child,
        // Dequeue() it.
        if (hasBothChild(front))
            Dequeue(queue);
    }

    // Enqueue() the new node for later insertions
    Enqueue(temp, queue);
}

// Standard level order traversal to test above function
void levelOrder(struct node* root)
{
    struct Queue* queue = createQueue(SIZE);

    Enqueue(root, queue);

    while (!isEmpty(queue))
    {
        struct node* temp = Dequeue(queue);

        printf("%d ", temp->data);

        if (temp->left)
            Enqueue(temp->left, queue);

        if (temp->right)
            Enqueue(temp->right, queue);
    }
}

struct node* mirror(struct node* root)
{
    struct node* temp;
  if(root)
  {
      mirror(root->left);
      mirror(root->right);

      temp=root->right;
      root->right=root->left;
      root->left=temp;
  }
  return root;
}

int checkmirror(struct node* root1,struct node* root2)
{
    if(!root1 && !root2)
        return 1;
    if(!root1 || !root2)
        return 0;
    if(root1->data!=root2->data)
        return 0;
     else
        return checkmirror(root1->left,root2->right)&&checkmirror(root1->right,root2->left);
}


// Driver program to test above functions
int main()
{
    struct node* root1=NULL,*root2=NULL;
    struct Queue* queue1=createQueue(SIZE),*queue2 = createQueue(SIZE);
    int i;

    for(i = 1; i <= 12; ++i)
        insert(&root1,i, queue1);
    for(i = 1; i <= 12; ++i)
        insert(&root2,i, queue2);


     mirror(root2);
    printf("The tree_1 elements are: ");
      levelOrder(root1);
        printf("\nThe tree_2 elements are: ");
      levelOrder(root2);
    printf("\n");

    if(checkmirror(root1,root2))
      printf("\nThe trees are mirror image");
    else
       printf("\nThe trees are not  mirror image");
    return 0;
}

