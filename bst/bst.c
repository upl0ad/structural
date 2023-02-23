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

// NOTE: recursion based insertion algorithm
/* void insert_node(Node *node, Node *inst) */
/* { */
/*   if (current->content > inst->content) { */
/*     if (current->left == NULL) { */
/*       current->left = inst; */
/*       return; */
/*     } */
/*     insert_node(current->left, inst); */
/*   } */

/*   if(current->content < inst->content) { */
/*     if (current->right == NULL) { */
/*       current->right = inst; */
/*       return; */
/*     } */
/*     insert_node(current->right, inst); */
/*   } */
/* } */

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
        /* printf("inserting %d in left\n", content); */
        current->left = new_node(content);
        break;
      }
      current = current->left;
    }

    if (current->content < content) {
      if (current->right == NULL) {
        /* printf("inserting %d in right\n", content); */
        current->right = new_node(content);
        break;
      }
      current = current->right;
    }
  }
}

// NOTE: binary tree traversal algorithm.
void traverse_over(Node *root)
{
}

void dump_dot_info(Node *nd)
{
  printf("    %d -> %d;\n", nd->content, nd->left->content);
  printf("    %d -> %d;\n", nd->content, nd->right->content);
}

int main(void)
{
  Node *root = new_node(50);

  for (int i = 0; i < 50; i++) {
    insert_node(root, i);
  }

  for (int i = 51; i < 100; i++) {
    insert_node(root, i);
  }

  printf("digraph BST {\n");
  iterate_over(root);
  printf("}\n");

  return 0;
}
