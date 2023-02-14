// what is a linked list?
// a linked list is a list of pointers. Each block on
// a linked list points to a node, that is a structure
// that holds a content and a reference for the previous
// and next node in the list
//
// root <-> node_1 <-> node_2 <-> node_3
//
// it is a good data structure for operations like "appending", since
// you just need to create a node, fill it with some content and reference
// it as the next node of the current final node.
//
// but it sucks to perform operations like search and whatever.
// for complex searches we're gonna use binary search trees (BSTs)
// and trees in general
#include <stdlib.h>

typedef struct Node
{
  struct Node* previous;
  struct Node* next;

  int content;
} Node;


typedef struct List
{
  Node* root;
  Node* top;
} List;


List* NewList(int root_content)
{
  List* list = malloc(sizeof(List)); // don't forget to allocate space for pointers, fucker.
  Node* root_node = malloc(sizeof(Node));

  root_node->content = root_content;
  root_node->previous = NULL;
  root_node->next = NULL;

  list->root = root_node;
  list->top = root_node;

  return list;
}


Node* get_next_node(Node* node)
{
  return node->next;
}


void append_node(List* list, int top_content)
{
  Node* top_node = malloc(sizeof(Node));
  top_node->next = NULL;
  top_node->previous = list->top;
  top_node->content = top_content;

  list->top->next = top_node;
  list->top = top_node;
}


