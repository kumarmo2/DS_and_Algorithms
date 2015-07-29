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

    if(!root)
        return;

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
struct node* findnode(struct node* root,int key)
{
    struct Queue* queue = createQueue(SIZE);

    Enqueue(root, queue);

    while (!isEmpty(queue))
    {
        struct node* temp = Dequeue(queue);

        if(temp->data==key)
            return temp;

        if (temp->left)
            Enqueue(temp->left, queue);

        if (temp->right)
            Enqueue(temp->right, queue);
    }

        return NULL;

}

struct node* deepestnode(struct node* root)
{
 struct node* temp;
 struct Queue* Q=createQueue(SIZE);

 if(!root)
   return 0;
 Enqueue(root,Q);
 while(!isEmpty(Q))
 {
     temp=Dequeue(Q);
     if(temp->left)
        Enqueue(temp->left,Q);
     if(temp->right)
        Enqueue(temp->right,Q);
 }
 return temp;
}

struct node* findparent(struct node* root,int key)
{
    struct Queue* queue = createQueue(SIZE);

    Enqueue(root, queue);

    while (!isEmpty(queue))
    {
        struct node* temp = Dequeue(queue);

        if(temp->right && temp->right->data==key)
            return temp;

        else if (temp->left && temp->left->data==key)
            return temp;

        if(temp->left)
            Enqueue(temp->left,queue);

        if (temp->right)
            Enqueue(temp->right, queue);
    }

        return NULL;

}

struct node* deletenode(struct node* root,struct node* temp1,struct node* temp2)
{
   temp1->data=temp1->data+temp2->data;
   temp2->data=temp1->data-temp2->data;
   temp1->data=temp1->data-temp2->data;
   struct node* parent=findparent(root,temp1->data);
   parent->left=NULL;
   parent->right=NULL;
   free(temp1);
   return root;
}



// Driver program to test above functions
int main()
{
    struct node* temp1,*temp2,*root = NULL;
    struct Queue* queue = createQueue(SIZE);
    int i,key;

    for(i = 1; i <= 12; ++i)
        insert(&root,i, queue);
    printf("The tree elements before deletion are: ");
    levelOrder(root);
    temp1=deepestnode(root);
    printf("\nEnter the node you want to delete = ");
    scanf("%d",&key);
    temp2=findnode(root,key);
    root=deletenode(root,temp1,temp2);
    printf("\nThe tree elements after deletion are: ");
    levelOrder(root);

    return 0;
}
