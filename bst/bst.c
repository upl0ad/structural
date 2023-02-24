#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int content;

  struct Node* right;
  struct Node* left;
} Node;

Node *new_node(int content)
{
  Node *node = malloc(sizeof(Node));
  node->content = content;
  node->right = NULL;
  node->left = NULL;
  return node;
}

// NOTE: iteration based insertion algorithm
void insert_node(Node *root, int content)
{
  Node *current = root;
  while (1)
  {
    if (current->content == content) // NOTE: not inserting stuff that already exists in BST
      break;

    if (current->content > content) {
      if (current->left == NULL) {
        current->left = new_node(content);
        break;
      }
      current = current->left;
    }

    if (current->content < content) {
      if (current->right == NULL) {
        current->right = new_node(content);
        break;
      }
      current = current->right;
    }
  }
}

// will traverse throughout every node in tree and
// print their dot information
void dot_traversal(Node *nd)
{
  if (nd == NULL)
    return;

  dot_traversal(nd->left);

  if (nd->left != NULL)
    printf("    %d -> %d;\n", nd->content, nd->left->content);

  if (nd->right != NULL)
    printf("    %d -> %d;\n", nd->content, nd->right->content);

  dot_traversal(nd->right);
}

int main(void)
{
  Node *root = new_node(50);

  insert_node(root, 8);
  insert_node(root, 3);
  insert_node(root, 6);
  insert_node(root, 1);
  insert_node(root, 10);
  insert_node(root, 11);
  insert_node(root, 9);

  printf("digraph BST {\n");
    dot_traversal(root);
  printf("}\n");

  return 0;
}
