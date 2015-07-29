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

        // If the left child of this front node doesn�t exist, set the
        // left child as the new node
        if (!front->left)
            front->left = temp;

        // If the right child of this front node doesn�t exist, set the
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

struct node* insertnode(struct node* root,int data)
{
    struct node* aux=newNode(data);

    if(!root)
      return root;
    else
    {
        struct Queue* Q=createQueue(SIZE);
        struct node* temp;
        Enqueue(root,Q);
        while(!isEmpty(Q))
        {
            temp=Dequeue(Q);
            if(!temp->left)
            {
                temp->left=aux;
                break;
            }
            else if(!temp->right)
            {
                temp->right=aux;
                break;
            }
            else
            {
                if(temp->left)
                   Enqueue(temp->left,Q);
                if(temp->right)
                   Enqueue(temp->right,Q);
            }
        }

    }
  return root;
}

void InOrder(struct node* root)
{
    if(root)
    {
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
    }
    else
        return;
}

// Driver program to test above functions
int main()
{
    struct node* root = NULL;
    struct Queue* queue = createQueue(SIZE);
    int i,key=0;

    for(i = 1; i <= 9; ++i)
        insert(&root, i, queue);
    printf("The tree elements before insertion are(LevelOrder Treaversal): ");
    levelOrder(root);
    printf("\nEnter the value of the node = ");
    scanf("%d",&key);
    root=insertnode(root,key);
    printf("\nThe tree elements after insertion are (Inorder Traversal): ");
    InOrder(root);
    return 0;
}
