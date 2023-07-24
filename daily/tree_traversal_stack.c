/*
 * Date: 23/07/23
 * Problem: Tree with stack
 * Approach: Use stack operations to do traversals
 *
 * Files: tree_traversal_stack.c
 */

#include <stdio.h>
#include <stdlib.h>

struct tNode
{
  struct tNode *left;
  int data;
  struct tNode *right;
}*rootTree = NULL;

// Stack to push and pop elements for traversal
// This is node in linked list, which will have the tree node address as data value.
struct node
{
    struct tNode *tn;
    struct node *next;
};

struct stack
{
    struct node *top;
    int sElemCnt;
};

// Global stack variable
struct stack *s = NULL;

// pushes the addresses of children
void push(struct tNode *tn)
{
    // If stack is not created
    if(s == NULL)
    {
        s = (struct stack*)malloc(sizeof(struct stack));
        s->top = NULL;
        s->sElemCnt = 0;
    }

    // Add a new node, assign the tree node to newNode's tree node
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->tn = tn;

    // If no elements in stack yet
    if(s->top == NULL)
        s->top = newNode;
    else    // Push on top
    {
        newNode->next = s->top;
        s->top = newNode;
    }
    s->sElemCnt++;

    // printf("\nPushed elem=%d, total elems=%d\n", newNode->tn->data, s->sElemCnt);
}

// Removes the addresses of children
struct tNode* pop()
{
    struct node *temp = NULL;
    struct tNode *tn = NULL;

    if(s->top == NULL)
    {
        printf("Error: stack is empty\n");
        return tn;
    }

    temp = s->top;
    s->top = s->top->next;
    tn = temp->tn; // Get the tree node from temp and free temp
    free(temp);
    s->sElemCnt--;

    // printf("\nPopped elem=%d, total elems=%d\n", tn->data, s->sElemCnt);

    return tn;
}

// Return the top of stack, do not POP
struct tNode* peek()
{
    if(s && s->top)
        return s->top->tn;
    else
        return NULL;
}
// Checks if stack is empty
int isStackEmpty()
{
    if(s->top == NULL)
        return 1;
    else
        return 0;
}

// Creates a tree node
struct tNode* createTreeNode(int data)
{
  struct tNode *newNode = (struct tNode*)malloc(sizeof(struct tNode));

  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Preorder traversal
// Root->left->right 1-2-4-5-3-6-7
void preOrderIter(struct tNode *root)
{
    struct tNode *t = root;
    if( !t )
        return;

    while(t || s->top)
    {
        if(t != NULL)
        {
            printf("%d ", t->data);
            push(t);
            t = t->left;
        }
        else
        {
            t = pop();
            t = t->right;
        }
    }
}

// inorder traversal iterative way
// left->Root->right 4-2-5-1-6-3-7
void inOrderIter(struct tNode *root)
{
    struct tNode *t = root;
    if( !t )
        return;

    while(t || s->top)
    {
        if(t != NULL)
        {
            push(t);
            t = t->left;
        }
        else
        {
            t = pop();
            printf("%d ", t->data);
            t = t->right;
        }
    }
}

// postorder traversal iterative way
// left->right->Root 4-5-2-6-7-3-1
void postOrderIter(struct tNode *root)
{
    struct tNode *t = root;
    struct tNode *prev = NULL;

    if( !t )
        return;

    while(t || s->top)
    {
        if(t != NULL)
        {
            push(t);
            t = t->left;
        }
        else
        {
            t = peek();

            // If we have visited this node once, then pop and print
            if(t->right == prev || t->right == NULL )
            {
                t = pop();
                printf("%d ", t->data);
                prev = t;
                t = NULL;
            }
            else
                t = t->right;
        }
    }
}

#if 0
// level order traversal
// level 1-2-3-n 1-2-3-4-5-6-7
void levelOrder(struct tNode *root)
{
    // base condition
    if(root == NULL)
        return;

    // Logic is to enQ the tree nodes to the Q
    // Until Q is empty,
    //  print the element -> deQ node from Q ->
    //  enQ left to the Q -> enQ right to the Q ->
    //  print the element -> deQ node from Q
    enQ(root);

    // DeQ until Q is not empty
    while(!isQempty())
    {
        struct tNode* temp = deQ();

        if(temp)
            printf("%d ", temp->data);

        if(temp->left)
            enQ(temp->left);
        if(temp->right)
            enQ(temp->right);
    }
}

int isMirror(struct tNode *root1, struct tNode *root2)
{
  // Conditions to be symmetric,
  // 1. When both the nodes are empty at the same time
  // 2. When left node of root1 == right node of root2 &&
  // 3. When left subtree of root == right subtree

  // Cond - 1, An empty tree is symmetric
  if(root1 == NULL && root2 == NULL)
    return 1;

  // Cond 2 && 3, Subtree match
  if((root1 && root2) && (root1->data == root2->data))
      return isMirror(root1->left, root2->right) &&
                isMirror(root1->right, root2->left);
  else
    return 0;
}

// This routine has to call the isMirror() recursively
int isSymmetry(struct tNode *root)
{
  return isMirror(root, root);
}
#endif

struct tNode* createTree()
{
  struct tNode *root = createTreeNode(1);

  root->left = createTreeNode(2);
  root->right= createTreeNode(3);
#if 1
  root->left->left = createTreeNode(4);
  root->left->right = createTreeNode(5);

  root->right->left = createTreeNode(6);
  root->right->right= createTreeNode(7);
#endif
  return root;
}

int main(int argc, char *argv[])
{
    // Function body

    /* First just create a Binary Tree which looks like below.
     *           1
     *           /\
     *          2  3
     *         /\  /\
     *        4  5 6 7
     */
    rootTree = createTree();

    printf("\nPreorder of nodes 1-2-3-4-5-6-7: ");
    preOrderIter(rootTree);

    printf("\ninorder of nodes 1-2-3-4-5-6-7: ");
    inOrderIter(rootTree);

    printf("\npostorder of nodes 1-2-3-4-5-6-7: ");
    postOrderIter(rootTree);

    // printf("\nLevelorder of nodes 1-2-3-4-5-6-7: ");
    // levelOrder(rootTree);

    printf("\nEnd of the program\n");

    return 0;
}