/*
 * Date: 22/07/23
 * Problem: Tree with Queue
 * Approach: Use left and right pointers, which will point to child nodes.
 *
 * Files: tree_from_q.c
 */

#include <stdio.h>
#include <stdlib.h>

struct tNode
{
  struct tNode *left;
  int data;
  struct tNode *right;
}*rootTree = NULL;

// Queue to enQ or deQ elements for traversal
// This is node in linked list, which will have the tree node address as data value.
struct node
{
    struct tNode *tn;
    struct node *next;
};

struct Q
{
    struct node *qFront;
    struct node *qRear;
    int qElemCnt;
};

// Global Queue variable
struct Q *q = NULL;

// Enqueues the addresses of children
void enQ(struct tNode *tn)
{
    // If Q is not initialized
    if(q == NULL)
    {
        q = (struct Q*)malloc(sizeof(struct Q));
        q->qFront = NULL;
        q->qRear = NULL;
        q->qElemCnt = 0;
    }

    // Add a new node, assign the tree node to newNode's tree node
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->tn = tn;

    // If no elements in Q yet
    if(q->qRear == NULL)
        q->qFront = newNode;
    else
        q->qRear->next = newNode;

    q->qRear = newNode;
    q->qElemCnt++;

   // printf("\nEnqed elem=%d, total elems=%d\n", newNode->tn->data, q->qElemCnt);
}

// Removes the addresses of children
struct tNode* deQ()
{
    struct node *temp = NULL;
    struct tNode *tn = NULL;

    if(q->qFront == NULL)
    {
        printf("Error: Q is empty\n");
        return tn;
    }

    temp = q->qFront;
    q->qFront = q->qFront->next;

#if 0
    // This is very very important, make sure when Q is empty, make the rear too NULL
    if(q->qFront == NULL)
        q->qRear = NULL;
#endif
    q->qElemCnt--;
    //printf("\nDeQed elem=%d, total elems=%d\n", temp->tn->data, q->qElemCnt);
    tn = temp->tn;
    free(temp);
    return tn;
}

int isQempty()
{
    if(q->qFront == NULL || q->qRear == NULL)
        return 1;
    else
        return 0;
}

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
void preOrder(struct tNode *root)
{
  // base condition, end the recursion
  if(root == NULL)
    return;

  printf("%d ", root->data);
  preOrder(root->left);
  preOrder(root->right);
}

// Postorder traversal
// left->right->Root 4-5-2-6-7-3-1
void postOrder(struct tNode *root)
{
  // base condition, end the recursion
  if(root == NULL)
    return;

  postOrder(root->left);
  postOrder(root->right);
  printf("%d ", root->data);
}

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
  preOrder(rootTree);

  printf("\nPostorder of nodes 1-2-3-4-5-6-7: ");
  postOrder(rootTree);

  printf("\nLevelorder of nodes 1-2-3-4-5-6-7: ");
  levelOrder(rootTree);

  printf("\nEnd of the program\n");

  return 0;
}