/*
 * Day: 10
 * Date: 16/07/23
 * Problem: Create a tree.
 * Approach: Use left and right pointers, which will point to child nodes.
 *            We can pass different parameters to createTreeNode() with values
 *            upto level 3 only. A better approach will be using Queue,
 *            which I will update in another file.
 * Files: d10_tree_create.c
 */

#include <stdio.h>
#include <stdlib.h>

struct tNode
{
  struct tNode *left;
  int data;
  struct tNode *right;
}*rootTree = NULL;

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
  root->right= createTreeNode(2);
#if 1
  root->left->left = createTreeNode(4);
// root->left->right = createTreeNode(5);

//  root->right->left = createTreeNode(5);
  root->right->right= createTreeNode(4);
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

  printf("\nBT %s symmetrical\n", isSymmetry(rootTree) ? "is" : "is not");

  printf("\nEnd of the program\n");

  return 0;
}